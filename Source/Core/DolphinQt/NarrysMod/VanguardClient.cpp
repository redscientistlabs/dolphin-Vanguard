//A basic test implementation of Netcore for IPC in Dolphin

#pragma warning(disable:4564) 

#include "stdafx.h"

#include "Core/State.h"
#include "Core/HW/Memmap.h"
#include "Core/HW/DSP.h"
#include "Core/PatchEngine.h"
#include "Core/PowerPC/PowerPC.h"
#include "Core/ConfigManager.h"
#include "Core/Core.h"
#include "Common/SPSCQueue.h"

#include <string>  
#include <iostream>

#include "VanguardClient.h"
#include "DolphinMemoryDomain.h"

#include <msclr/marshal_cppstd.h>

using namespace cli;
using namespace System;
using namespace RTCV;
using namespace RTCV::NetCore;
using namespace RTCV::CorruptCore;
using namespace RTCV::Vanguard;
using namespace System::Runtime::InteropServices;
using namespace System::Threading;
using namespace System::Collections::Generic;

#using <system.dll>
#using <system.windows.forms.dll>
using namespace System::Diagnostics;

#define SRAM_SIZE 25165824
#define ARAM_SIZE 16777216
#define EXRAM_SIZE 67108864

/*
Trace::Listeners->Add(gcnew TextWriterTraceListener(Console::Out));
Trace::AutoFlush = true;
Trace::WriteLine(filename);
*/


delegate void MessageDelegate(Object ^);
// Define this in here as it's managed and it can't be in VanguardClient.h as that's included in
// unmanaged code. Could probably move this to a header
public
ref class VanguardClient
{
public:
  static RTCV::NetCore::NetCoreReceiver ^ receiver;
  static RTCV::Vanguard::VanguardConnector ^ connector;

  void OnMessageReceived(Object ^ sender, RTCV::NetCore::NetCoreEventArgs ^ e);

  void StartClient();
  void RestartClient();

  void LoadState(String ^ filename, StashKeySavestateLocation ^ location);
  void SaveState(String ^ filename, StashKeySavestateLocation ^ location, bool wait);

  static Mutex ^ mutex = gcnew Mutex(false, "VanguardMutex");
};

ref class ManagedGlobals
{
public:
  static VanguardClient ^ client = nullptr;
  static FullSpec ^ VanguardSpec = nullptr;
};


static PartialSpec^ getDefaultPartial()
{
  PartialSpec ^ partial = gcnew PartialSpec("RTCSpec");

  partial->Set(VSPEC::SYSTEM, String::Empty);
  return partial;
}


void SpecUpdated(System::Object ^ sender, SpecUpdateEventArgs ^ e)
{
  PartialSpec ^ partial = e->partialSpec;

  //if (!VanguardCore.attached)
  RTCV::NetCore::AllSpec::VanguardSpec = ManagedGlobals::VanguardSpec;

  LocalNetCoreRouter::Route(NetcoreCommands::CORRUPTCORE, NetcoreCommands::REMOTE_PUSHVANGUARDSPECUPDATE, partial, true);
  LocalNetCoreRouter::Route(NetcoreCommands::UI, NetcoreCommands::REMOTE_PUSHVANGUARDSPECUPDATE, partial, true);
}

static void RegisterEmuhawkSpec()
{
  PartialSpec ^ emuSpecTemplate = gcnew PartialSpec("VanguardSpec");

  emuSpecTemplate->Insert(getDefaultPartial());

  ManagedGlobals::VanguardSpec = gcnew FullSpec(emuSpecTemplate, !RTCV::CorruptCore::CorruptCore::Attached);  // You have to feed a partial spec as a template

  //if (VanguardCore.attached)
   // RTCV.Vanguard.VanguardConnector.PushVanguardSpecRef(VanguardCore.VanguardSpec);

  LocalNetCoreRouter::Route(NetcoreCommands::CORRUPTCORE, NetcoreCommands::REMOTE_PUSHVANGUARDSPEC,
                           emuSpecTemplate, true);
  LocalNetCoreRouter::Route(NetcoreCommands::UI, NetcoreCommands::REMOTE_PUSHVANGUARDSPEC,
                           emuSpecTemplate, true);

  ManagedGlobals::VanguardSpec->SpecUpdated += gcnew EventHandler<SpecUpdateEventArgs^>(SpecUpdated);

}
bool RefreshDomains()
{
  List<MemoryDomainProxy ^> ^ interfaces = gcnew List<MemoryDomainProxy ^>();
  interfaces->Add(gcnew MemoryDomainProxy(gcnew SRAM));
  interfaces->Add(gcnew MemoryDomainProxy(gcnew ARAM));
  interfaces->Add(gcnew MemoryDomainProxy(gcnew EXRAM));

  AllSpec::VanguardSpec->Update(VSPEC::MEMORYDOMAINS_INTERFACES, interfaces->ToArray(), true, true);
  LocalNetCoreRouter::Route(NetcoreCommands::CORRUPTCORE,
                            NetcoreCommands::REMOTE_EVENT_DOMAINSUPDATED, true, true);
  return true;
}

//Create our VanguardClient
void VanguardClientInitializer::Initialize()
{
  System::Windows::Forms::Form ^ dummy = gcnew System::Windows::Forms::Form();
  IntPtr Handle = dummy->Handle;
  SyncObjectSingleton::SyncObject = dummy;

  // Start everything
  ManagedGlobals::client = gcnew VanguardClient;
  ManagedGlobals::client->StartClient();
  RegisterEmuhawkSpec();
  RTCV::CorruptCore::CorruptCore::StartEmuSide();

}



int CPU_STEP_Count = 0;
static void STEP_CORRUPT()  // errors trapped by CPU_STEP
{
  StepActions::Execute();
  CPU_STEP_Count++;
  bool autoCorrupt = RTCV::CorruptCore::CorruptCore::AutoCorrupt;
  long errorDelay = RTCV::CorruptCore::CorruptCore::ErrorDelay;
  if (autoCorrupt && CPU_STEP_Count >= errorDelay)
  {
    array<System::String ^> ^ domains = AllSpec::UISpec->Get<array<System::String ^>^>("SELECTEDDOMAINS");

    BlastLayer ^ bl = RTCV::CorruptCore::CorruptCore::GenerateBlastLayer(domains);
    if (bl != nullptr)
      bl->Apply(false, true);
  }
}


 
void VanguardClientUnmanaged::CORE_STEP()
{
  // Any step hook for corruption
  STEP_CORRUPT();
}

bool VanguardClientInitializer::isWii()
{
  if (SConfig::GetInstance().bWii)
    return true;
  return false;
}

//Initialize it 
void VanguardClient::StartClient() 
{
  VanguardClient::receiver = gcnew RTCV::NetCore::NetCoreReceiver();
  VanguardClient::receiver->MessageReceived += gcnew EventHandler<NetCore::NetCoreEventArgs ^>(this, &VanguardClient::OnMessageReceived);
  VanguardClient::connector = gcnew RTCV::Vanguard::VanguardConnector(receiver);
}

void VanguardClient::RestartClient()
{
  VanguardClient::connector->Kill();
  VanguardClient::connector = nullptr;
  StartClient();
}

/* IMPLEMENT YOUR COMMANDS HERE */
void VanguardClient::LoadState(String^ filename, StashKeySavestateLocation ^ location) {

  std::string converted_filename = msclr::interop::marshal_as< std::string >(filename);
  State::LoadAs(converted_filename);

}
void VanguardClient::SaveState(String ^ filename, StashKeySavestateLocation ^ location, bool wait)
{

  std::string converted_filename = msclr::interop::marshal_as< std::string >(filename);
  State::SaveAs(converted_filename, wait);
}

/*ENUMS FOR THE SWITCH STATEMENT*/
enum COMMANDS {
  SAVESAVESTATE,
  LOADSAVESTATE,
  REMOTE_LOADROM,
  REMOTE_CLOSEGAME,
  REMOTE_DOMAIN_GETDOMAINS,
  REMOTE_KEY_SETSYNCSETTINGS,
  REMOTE_KEY_SETSYSTEMCORE,
  REMOTE_EVENT_EMU_MAINFORM_CLOSE,
  REMOTE_EVENT_EMUSTARTED,
  REMOTE_ISNORMALADVANCE,
  REMOTE_EVENT_CLOSEEMULATOR,
  REMOTE_ALLSPECSSENT,
  UNKNOWN
};

inline COMMANDS CheckCommand(String^ inString) {
  if (inString == "LOADSAVESTATE")
    return LOADSAVESTATE;
  if (inString == "SAVESAVESTATE")
    return SAVESAVESTATE;
  if (inString == "REMOTE_LOADROM")
    return REMOTE_LOADROM;
  if (inString == "REMOTE_CLOSEGAME")
    return REMOTE_CLOSEGAME;
  if (inString == "REMOTE_ALLSPECSSENT")
    return REMOTE_DOMAIN_GETDOMAINS;
  if (inString == "REMOTE_DOMAIN_GETDOMAINS")
    return REMOTE_KEY_SETSYNCSETTINGS;
  if (inString == "REMOTE_KEY_SETSYNCSETTINGS")
    return REMOTE_KEY_SETSYSTEMCORE;
  if (inString == "REMOTE_KEY_SETSYSTEMCORE")
    return REMOTE_EVENT_EMU_MAINFORM_CLOSE;
  if (inString == "REMOTE_EVENT_EMU_MAINFORM_CLOSE")
    return REMOTE_EVENT_EMUSTARTED;
  if (inString == "REMOTE_EVENT_EMUSTARTED")
    return REMOTE_ISNORMALADVANCE;
  if (inString == "REMOTE_ISNORMALADVANCE")
    return REMOTE_ALLSPECSSENT;
  if (inString == "REMOTE_EVENT_CLOSEEMULATOR")
    return REMOTE_EVENT_CLOSEEMULATOR;
  if (inString == "REMOTE_ALLSPECSSENT")
    return REMOTE_ALLSPECSSENT;
  return UNKNOWN;
}

 LOADSTATE_NET(System::Object^ o, NetCoreEventArgs^ e)
{
  e->setReturnValue(VanguardCore.LoadSavestate_NET(path, location));
}


/* THIS IS WHERE YOU HANDLE ANY RECEIVED MESSAGES */
void VanguardClient::OnMessageReceived(Object^ sender, NetCoreEventArgs^ e)
{
  NetCoreMessage ^ message = e->message;

  //Can't define this unless it's used as SLN is set to treat warnings as errors.
  //NetCoreSimpleMessage ^ simpleMessage = (NetCoreSimpleMessage^)message;

  NetCoreAdvancedMessage ^ advancedMessage = (NetCoreAdvancedMessage^)message;

  switch (CheckCommand(message->Type)) {
  case LOADSAVESTATE: {
    if (Core::GetState() == Core::State::Running)
    {
      array<System::Object ^> ^ cmd = static_cast<array<System::Object ^> ^>(advancedMessage->objectValue);
      System::String ^ path = static_cast<System::String^>(cmd[0]);
      StashKeySavestateLocation ^ location = safe_cast<StashKeySavestateLocation ^>(cmd[1]);
      SyncObjectSingleton::FormExecute();
      break;
    }
      LoadState((advancedMessage->objectValue)->ToString());
  }
    
    break;

  case SAVESAVESTATE:
  {
    if (Core::GetState() == Core::State::Running)
      SaveState((advancedMessage->objectValue)->ToString(), 0);
  }
  break;
  case REMOTE_ALLSPECSSENT:
  {
    RefreshDomains();
  }
  break;


  default:
    break;
  }
}
