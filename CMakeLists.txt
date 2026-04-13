cmake_minimum_required (VERSION 3.10)

set(CMAKE_POLICY_VERSION_MINIMUM 3.5)

if(POLICY CMP0155)
  cmake_policy(SET CMP0155 OLD)
endif()

if (POLICY CMP0141)
  #cmake_policy(SET CMP0141 NEW)
  # set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project("SpaceAttractor")

include(cmake/PreventInSourceBuilds.cmake)
include(cmake/Emscripten.cmake)
include(ProjectOptions.cmake)


ZapretPP_setup_options()

if (ZapretPP_WARNINGS_AS_ERRORS)
  set(ZapretPP_WARNING_TYPE SEND_ERROR)
else()
  set(ZapretPP_WARNING_TYPE WARNING)
endif()

ZapretPP_global_options()


ZapretPP_local_options()

option(BUILD_TESTS "Build tests" OFF)


message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
set(IS_DEBUG_BUILD "false")
if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
    set(IS_DEBUG_BUILD "true")
endif()


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

message(STATUS "cmake toolchain file: ${CMAKE_TOOLCHAIN_FILE}")

set(${ENTT_BUILD_DOCS} ON)

####################################### Subdirectories #######################################

add_subdirectory("thirdparty/Engine")

add_subdirectory("Game")

if(BUILD_TESTS)
    message(STATUS "Building tests")
    enable_testing()
    add_subdirectory("tests")
endif()