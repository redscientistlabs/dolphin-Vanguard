find_package(Qt5 5.9 REQUIRED COMPONENTS Gui Widgets)

set_property(TARGET Qt5::Core PROPERTY INTERFACE_COMPILE_FEATURES "")
message(STATUS "Found Qt version ${Qt5Core_VERSION}")

set(CMAKE_AUTOMOC ON)

#Narrysmod - Goes before add_executable
add_compile_options("/AI\"${PROJECT_SOURCE_DIR}/\"")
#---------

add_executable(dolphin-emu
  AboutDialog.cpp
  CheatsManager.cpp
  DiscordHandler.cpp
  DiscordJoinRequestDialog.cpp
  FIFO/FIFOPlayerWindow.cpp
  FIFO/FIFOAnalyzer.cpp
  HotkeyScheduler.cpp
  Host.cpp
  Main.cpp
  MainWindow.cpp
  MenuBar.cpp
  RenderWidget.cpp
  Resources.cpp
  SearchBar.cpp
  Settings.cpp
  ToolBar.cpp
  Translation.cpp
  WiiUpdate.cpp
  WiiUpdate.h
  Config/CheatCodeEditor.cpp
  Config/ARCodeWidget.cpp
  Config/CheatWarningWidget.cpp
  Config/ControllersWindow.cpp
  Config/FilesystemWidget.cpp
  Config/GameConfigEdit.cpp
  Config/GameConfigHighlighter.cpp
  Config/GameConfigWidget.cpp
  Config/GeckoCodeWidget.cpp
  Config/Graphics/AdvancedWidget.cpp
  Config/Graphics/EnhancementsWidget.cpp
  Config/Graphics/GeneralWidget.cpp
  Config/Graphics/HacksWidget.cpp
  Config/Graphics/GraphicsBool.cpp
  Config/Graphics/GraphicsChoice.cpp
  Config/Graphics/GraphicsRadio.cpp
  Config/Graphics/GraphicsSlider.cpp
  Config/Graphics/GraphicsWidget.cpp
  Config/Graphics/GraphicsWindow.cpp
  Config/Graphics/PostProcessingConfigWindow.cpp
  Config/Graphics/SoftwareRendererWidget.cpp
  Config/InfoWidget.cpp
  Config/LogConfigWidget.cpp
  Config/LogWidget.cpp
  Config/Mapping/GCKeyboardEmu.cpp
  Config/Mapping/GCMicrophone.cpp
  Config/Mapping/GCPadEmu.cpp
  Config/Mapping/GCPadWiiUConfigDialog.cpp
  Config/Mapping/Hotkey3D.cpp
  Config/Mapping/HotkeyControllerProfile.cpp
  Config/Mapping/HotkeyDebugging.cpp
  Config/Mapping/HotkeyGeneral.cpp
  Config/Mapping/HotkeyGraphics.cpp
  Config/Mapping/HotkeyStates.cpp
  Config/Mapping/HotkeyStatesOther.cpp
  Config/Mapping/HotkeyTAS.cpp
  Config/Mapping/HotkeyWii.cpp
  Config/Mapping/IOWindow.cpp
  Config/Mapping/MappingButton.cpp
  Config/Mapping/MappingCommon.cpp
  Config/Mapping/MappingIndicator.cpp
  Config/Mapping/MappingNumeric.cpp
  Config/Mapping/MappingWidget.cpp
  Config/Mapping/MappingWindow.cpp
  Config/Mapping/WiimoteEmuExtension.cpp
  Config/Mapping/WiimoteEmuGeneral.cpp
  Config/Mapping/WiimoteEmuMotionControl.cpp
  Config/NewPatchDialog.cpp
  Config/PatchesWidget.cpp
  Config/PropertiesDialog.cpp
  Config/SettingsWindow.cpp
  Config/VerifyWidget.cpp
  Debugger/BreakpointWidget.cpp
  Debugger/CodeViewWidget.cpp
  Debugger/CodeWidget.cpp
  Debugger/JITWidget.cpp
  Debugger/MemoryViewWidget.cpp
  Debugger/MemoryWidget.cpp
  Debugger/NewBreakpointDialog.cpp
  Debugger/PatchInstructionDialog.cpp
  Debugger/RegisterColumn.cpp
  Debugger/RegisterWidget.cpp
  Debugger/WatchWidget.cpp
  GameList/GameList.cpp
  GameList/GameListModel.cpp
  GameList/GameTracker.cpp
  GameList/GridProxyModel.cpp
  GameList/ListProxyModel.cpp
  GCMemcardManager.cpp
  QtUtils/BlockUserInputFilter.cpp
  NetPlay/ChunkedProgressDialog.cpp
  NetPlay/GameListDialog.cpp
  NetPlay/MD5Dialog.cpp
  NetPlay/NetPlayBrowser.cpp
  NetPlay/NetPlayDialog.cpp
  NetPlay/NetPlaySetupDialog.cpp
  NetPlay/PadMappingDialog.cpp
  QtUtils/DoubleClickEventFilter.cpp
  QtUtils/ElidedButton.cpp
  QtUtils/FlowLayout.cpp
  QtUtils/ModalMessageBox.cpp
  QtUtils/ImageConverter.cpp
  QtUtils/WindowActivationEventFilter.cpp
  QtUtils/WinIconHelper.cpp
  QtUtils/WrapInScrollArea.cpp
  QtUtils/AspectRatioWidget.cpp
  ResourcePackManager.cpp
  Settings/AdvancedPane.cpp
  Settings/AudioPane.cpp
  Settings/GameCubePane.cpp
  Settings/GeneralPane.cpp
  Settings/InterfacePane.cpp
  Settings/PathPane.cpp
  Settings/WiiPane.cpp
  Settings/USBDeviceAddToWhitelistDialog.cpp
  TAS/GCTASInputWindow.cpp
  TAS/WiiTASInputWindow.cpp
  TAS/TASCheckBox.cpp
  TAS/TASInputWindow.cpp
  TAS/StickWidget.cpp
  TAS/IRWidget.cpp
  Updater.cpp
	NarrysMod/VanguardClient.cpp
  NarrysMod/Helpers.hpp
  NarrysMod/DolphinMemoryDomain.h
  NarrysMod/DolphinMemoryDomain.cpp
  NarrysMod/ThreadLocalHelper.h
  NarrysMod/VanguardClientInitializer.h
  NarrysMod/VanguardConfigLoader.cpp
	NarrysMod/VanguardConfigLoader.h
	NarrysMod/VanguardSettings.cpp
	NarrysMod/VanguardSettingsWrapper.h
)


#Narrysmod
file(GLOB CLR_FILES
				"NarrysMod/Helpers.hpp"
				"NarrysMod/VanguardClient.cpp"
        "NarrysMod/DolphinMemoryDomain.h"
				"NarrysMod/DolphinMemoryDomain.cpp"
				"NarrysMod/VanguardSettings.cpp"
				"NarrysMod/VanguardSettingsWrapper.h"
        )
include_external_msproject(
    CorruptCore ${PROJECT_SOURCE_DIR}/../RTCV/Source/Libraries/CorruptCore/CorruptCore.csproj
    TYPE B5633A86-DC66-4723-88EB-7DFC95458072)
include_external_msproject(
    NetCore ${PROJECT_SOURCE_DIR}/../RTCV/Source/Libraries/NetCore/NetCore.csproj
    TYPE 7E106AEC-5614-4206-9E4D-25759C90E8AE)
include_external_msproject(
    Vanguard ${PROJECT_SOURCE_DIR}/../RTCV/Source/Libraries/Vanguard/Vanguard.csproj
    TYPE 364C705E-B7AB-4A94-A59B-88899CE65958)

file(GLOB CLR_FILES
				"NarrysMod/Helpers.hpp"
				"NarrysMod/VanguardClient.cpp"
        "NarrysMod/DolphinMemoryDomain.h"
				"NarrysMod/DolphinMemoryDomain.cpp"
				"NarrysMod/VanguardSettings.cpp"
				"NarrysMod/VanguardSettingsWrapper.h"
        )

set_source_files_properties(${CLR_FILES} PROPERTIES COMPILE_FLAGS "/clr /EHa /Zc:twoPhase-")
set_target_properties(${PROJECT_NAME} PROPERTIES VS_DOTNET_REFERENCES_COPY_LOCAL ON )
set_target_properties(${PROJECT_NAME} PROPERTIES DOTNET_TARGET_FRAMEWORK_VERSION "v4.7.1")
set_target_properties(${PROJECT_NAME} PROPERTIES VS_DOTNET_REFERENCE_CorruptCore "${PROJECT_SOURCE_DIR}/../RTCV/Build/CorruptCore.dll")
set_target_properties(${PROJECT_NAME} PROPERTIES VS_DOTNET_REFERENCE_NetCore "${PROJECT_SOURCE_DIR}/../RTCV/Build/NetCore.dll")
set_target_properties(${PROJECT_NAME} PROPERTIES VS_DOTNET_REFERENCE_Vanguard "${PROJECT_SOURCE_DIR}/../RTCV/Build/Vanguard.dll")
set_target_properties(${PROJECT_NAME} PROPERTIES VS_DOTNET_REFERENCES "System;System.Windows.Forms")

string(REGEX REPLACE "/RTC(su|[1su])" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
string(REGEX REPLACE "/RTC(su|[1su])" "" CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
#-----------------------------------------------

if (NOT WIN32)
  target_sources(dolphin-emu PRIVATE QtUtils/SignalDaemon.cpp)
endif()

target_compile_definitions(dolphin-emu
PRIVATE
  -DQT_USE_QSTRINGBUILDER
  -DQT_NO_CAST_FROM_ASCII
  -DQT_NO_CAST_TO_ASCII
)

target_include_directories(dolphin-emu
PRIVATE
  ${CMAKE_CURRENT_BINARY_DIR}
  ${Qt5Gui_PRIVATE_INCLUDE_DIRS}
)

target_link_libraries(dolphin-emu
PRIVATE
  core
  Qt5::Widgets
  uicommon
  imgui
)


if(WIN32)
  target_sources(dolphin-emu PRIVATE DolphinQt.manifest DolphinQt.rc)

	if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(Dolphin_NAME "DolphinD")
  else()
    set(Dolphin_NAME "Dolphin")
  endif()

  set_target_properties(dolphin-emu PROPERTIES
    WIN32_EXECUTABLE TRUE
    OUTPUT_NAME ${Dolphin_NAME}
  )

  target_compile_options(dolphin-emu PRIVATE /D _SILENCE_CXX17_RESULT_OF_DEPRECATION_WARNING)

  # Copy Sys dir
  set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/Data/Sys")
  file(GLOB_RECURSE resources RELATIVE "${CMAKE_SOURCE_DIR}/Data" "${CMAKE_SOURCE_DIR}/Data/Sys/*")

  foreach(res ${resources})
    configure_file("${CMAKE_SOURCE_DIR}/Data/${res}" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${res}" COPYONLY)
  endforeach()

	# Copy qt.conf
  configure_file(qt.conf.win "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/qt.conf" COPYONLY)

  # Copy plugins
	set (Qt5_PLUGINS_DIR "${Qt5_DIR}/../../../plugins")
	file(GLOB_RECURSE plugins RELATIVE "${Qt5_PLUGINS_DIR}" "${Qt5_PLUGINS_DIR}/*.dll")

  if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    list(FILTER plugins INCLUDE REGEX ".*d.dll")
  else()
    list(FILTER plugins EXCLUDE REGEX ".*d.dll")
  endif()

  foreach(plugin ${plugins})
    configure_file("${Qt5_PLUGINS_DIR}/${plugin}" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/QtPlugins/${plugin}" COPYONLY)
  endforeach()

	# Copy DLLs
  set (Qt5_DLL_DIR "${Qt5_DIR}/../../../bin")

  file(GLOB_RECURSE dlls RELATIVE "${Qt5_DLL_DIR}" "${Qt5_DLL_DIR}/*.dll")

  if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    list(FILTER dlls INCLUDE REGEX ".*d.dll")
  else()
    list(FILTER dlls EXCLUDE REGEX ".*d.dll")
  endif()

  foreach(dll ${dlls})
    configure_file("${Qt5_DLL_DIR}/${dll}" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${dll}" COPYONLY)
  endforeach()


	# Narrysmod
	# Copy RTCV dlls and pdbs for easier dev purposes
  set (RTC_DLL_DIR "${PROJECT_SOURCE_DIR}/../RTCV/Build/")
  file(GLOB rtcdlls RELATIVE "${RTC_DLL_DIR}" "${RTC_DLL_DIR}/*.dll")
  file(GLOB rtcpdbs RELATIVE "${RTC_DLL_DIR}" "${RTC_DLL_DIR}/*.pdb")
	
  foreach(dll ${rtcdlls})
    configure_file("${RTC_DLL_DIR}/${dll}" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${dll}" COPYONLY)
  endforeach()

  foreach(pdb ${rtcpdbs})
    configure_file("${RTC_DLL_DIR}/${pdb}" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${pdb}" COPYONLY)
  endforeach()

endif()

# Handle localization
find_package(Gettext)

if(WIN32 AND NOT Gettext_FOUND)
  message(STATUS "Using Gettext from Externals")
  set(GETTEXT_MSGFMT_EXECUTABLE "${CMAKE_SOURCE_DIR}/Externals/gettext/msgfmt.exe")
endif()

if(GETTEXT_MSGMERGE_EXECUTABLE AND GETTEXT_MSGFMT_EXECUTABLE)
  set(pot_file "${CMAKE_SOURCE_DIR}/Languages/po/dolphin-emu.pot")
  file(GLOB LINGUAS ${CMAKE_SOURCE_DIR}/Languages/po/*.po)

  target_sources(dolphin-emu PRIVATE ${pot_file} ${LINGUAS})
  source_group("Localization" FILES ${LINGUAS})
  source_group("Localization\\\\Generated" FILES ${pot_file})

  foreach(po ${LINGUAS})
    get_filename_component(lang ${po} NAME_WE)
    set(mo_dir ${CMAKE_CURRENT_BINARY_DIR}/${lang})
    set(mo ${mo_dir}/dolphin-emu.mo)

    target_sources(dolphin-emu PRIVATE ${mo})
    source_group("Localization\\\\Generated" FILES ${mo})

    if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
      set_source_files_properties(${mo} PROPERTIES MACOSX_PACKAGE_LOCATION "Resources/${lang}.lproj")
    else()
      install(FILES ${mo} DESTINATION share/locale/${lang}/LC_MESSAGES)
    endif()

    if(WIN32)
      add_custom_command(OUTPUT ${mo}
        COMMAND ${CMAKE_COMMAND} -E make_directory ${mo_dir}
        COMMAND ${GETTEXT_MSGFMT_EXECUTABLE} -o ${mo} ${po}
        COMMAND ${CMAKE_COMMAND} -E copy ${mo} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Languages/${lang}/dolphin-emu.mo
        DEPENDS ${po}
      )
    else()
      add_custom_command(OUTPUT ${mo}
        COMMAND ${CMAKE_COMMAND} -E make_directory ${mo_dir}
        COMMAND ${GETTEXT_MSGMERGE_EXECUTABLE} --quiet --update --backup=none -s ${po} ${pot_file}
        COMMAND ${GETTEXT_MSGFMT_EXECUTABLE} -o ${mo} ${po}
        DEPENDS ${po}
      )
    endif()
  endforeach()
endif()

if(APPLE)
  include(BundleUtilities)
  set(BUNDLE_PATH ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Dolphin.app)

  # Ask for an application bundle.
  set_target_properties(dolphin-emu PROPERTIES
    MACOSX_BUNDLE true
    MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/Info.plist.in
    OUTPUT_NAME Dolphin
    )

  # Copy qt.conf into the bundle
  target_sources(dolphin-emu PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/qt.conf")
  set_source_files_properties("${CMAKE_CURRENT_SOURCE_DIR}/qt.conf" PROPERTIES MACOSX_PACKAGE_LOCATION Resources)

  # Copy icon into the bundle
  target_sources(dolphin-emu PRIVATE "${CMAKE_SOURCE_DIR}/Data/Dolphin.icns")
  set_source_files_properties("${CMAKE_SOURCE_DIR}/Data/Dolphin.icns" PROPERTIES MACOSX_PACKAGE_LOCATION Resources)

  # Copy Qt plugins into the bundle
  get_target_property(qtcocoa_location Qt5::QCocoaIntegrationPlugin LOCATION)
  target_sources(dolphin-emu PRIVATE "${qtcocoa_location}")
  set_source_files_properties("${qtcocoa_location}" PROPERTIES MACOSX_PACKAGE_LOCATION MacOS/platforms)

  get_target_property(qtmacstyle_location Qt5::QMacStylePlugin LOCATION)
  target_sources(dolphin-emu PRIVATE "${qtmacstyle_location}")
  set_source_files_properties("${qtmacstyle_location}" PROPERTIES MACOSX_PACKAGE_LOCATION MacOS/styles)

  # Copy resources into the bundle
  set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/Data/Sys")
  file(GLOB_RECURSE resources RELATIVE "${CMAKE_SOURCE_DIR}/Data" "${CMAKE_SOURCE_DIR}/Data/Sys/*")
  foreach(res ${resources})
    target_sources(dolphin-emu PRIVATE "${CMAKE_SOURCE_DIR}/Data/${res}")
    get_filename_component(resdir "${res}" DIRECTORY)
    set_source_files_properties("${CMAKE_SOURCE_DIR}/Data/${res}" PROPERTIES
      MACOSX_PACKAGE_LOCATION "Resources/${resdir}")
    source_group("Resources" FILES "${CMAKE_SOURCE_DIR}/Data/${res}")
  endforeach()

  # Copy MoltenVK into the bundle
  target_sources(dolphin-emu PRIVATE "${CMAKE_SOURCE_DIR}/Externals/MoltenVK/libvulkan.dylib")
  set_source_files_properties("${CMAKE_SOURCE_DIR}/Externals/MoltenVK/libvulkan.dylib" PROPERTIES MACOSX_PACKAGE_LOCATION Frameworks)

  # Update library references to make the bundle portable
  include(DolphinPostprocessBundle)
  dolphin_postprocess_bundle(dolphin-emu)
else()
  install(TARGETS dolphin-emu RUNTIME DESTINATION ${bindir})
endif()

if(USE_DISCORD_PRESENCE)
  target_compile_definitions(dolphin-emu PRIVATE -DUSE_DISCORD_PRESENCE)
endif()
