include_external_msproject(
    CorruptCore C:/Users/Daniel/Documents/RTCV/Source/Libraries/CorruptCore/CorruptCore.csproj
    TYPE B5633A86-DC66-4723-88EB-7DFC95458072)
include_external_msproject(
    NetCore C:/Users/Daniel/Documents/RTCV/Source/Libraries/NetCore/NetCore.csproj
    TYPE 7E106AEC-5614-4206-9E4D-25759C90E8AE)
include_external_msproject(
    Vanguard C:/Users/Daniel/Documents/RTCV/Source/Libraries/Vanguard/Vanguard.csproj
    TYPE 364C705E-B7AB-4A94-A59B-88899CE65958)

file(GLOB CLR_FILES
				"Helpers.hpp"
				"VanguardClient.cpp"
        "DolphinMemoryDomain.h"
				"DolphinMemoryDomain.cpp"
				"VanguardSettings.cpp"
				"VanguardSettingsWrapper.h"
        )
				
set_source_files_properties(${PROJECT_NAME} PROPERTIES DOTNET_TARGET_FRAMEWORK_VERSION "v4.7.1")
set_source_files_properties(${PROJECT_NAME} PROPERTIES VS_DOTNET_REFERENCES "System;System.Windows.Forms;Vanguard;NetCore;CorruptCore;RTCV.NetCore;RTCV.CorruptCore;RTCV.Vanguard")
set_source_files_properties(${CLR_FILES} PROPERTIES COMPILE_FLAGS "/clr /EHa")
string(REGEX REPLACE "/RTC(su|[1su])" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
string(REGEX REPLACE "/RTC(su|[1su])" "" CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")

add_library(narrysmod
  VanguardClient.cpp
  Helpers.hpp
  DolphinMemoryDomain.h
  DolphinMemoryDomain.cpp
  ThreadLocalHelper.h
  VanguardClientInitializer.h
  VanguardConfigLoader.cpp
	VanguardConfigLoader.h
	VanguardSettings.cpp
	VanguardSettingsWrapper.h
)
add_dependencies(narrysmod
	CorruptCore
	Vanguard
	NetCore)
