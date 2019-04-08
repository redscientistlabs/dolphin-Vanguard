#pragma once
ref class SRAM : RTCV::CorruptCore::IMemoryDomain
{
public:
  property System::String^ Name { virtual System::String^ get(); }
  property long long Size { virtual long long get(); }
  property int WordSize { virtual int get(); }
  property bool BigEndian { virtual bool get(); }
  virtual unsigned char PeekByte(long long addr);
  virtual void PokeByte(long long addr, unsigned char val);
};

ref class EXRAM : RTCV::CorruptCore::IMemoryDomain
{
public:
  property System::String ^ Name { virtual System::String ^ get(); }
  property long long Size {virtual long long get(); }
  property int WordSize { virtual int get(); }
  property bool BigEndian { virtual bool get(); }

  virtual unsigned char PeekByte(long long addr);
  virtual void PokeByte(long long addr, unsigned char val);
};

ref class ARAM : RTCV::CorruptCore::IMemoryDomain
{
public:
  property System::String ^ Name { virtual System::String ^ get(); } 
  property long long Size{ virtual long long get(); }
  property int WordSize { virtual int get(); }
  property bool BigEndian { virtual bool get(); }

  virtual unsigned char PeekByte(long long addr);
  virtual void PokeByte(long long addr, unsigned char val);
};
