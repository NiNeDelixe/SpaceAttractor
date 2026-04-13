include(cmake/SystemLink.cmake)
include(cmake/LibFuzzer.cmake)
include(CMakeDependentOption)
include(CheckCXXCompilerFlag)


include(CheckCXXSourceCompiles)


macro(ZapretPP_supports_sanitizers)
  # Emscripten doesn't support sanitizers
  if(EMSCRIPTEN)
    set(SUPPORTS_UBSAN OFF)
    set(SUPPORTS_ASAN OFF)
  elseif((CMAKE_CXX_COMPILER_ID MATCHES ".*Clang.*" OR CMAKE_CXX_COMPILER_ID MATCHES ".*GNU.*") AND NOT WIN32)

    message(STATUS "Sanity checking UndefinedBehaviorSanitizer, it should be supported on this platform")
    set(TEST_PROGRAM "int main() { return 0; }")

    # Check if UndefinedBehaviorSanitizer works at link time
    set(CMAKE_REQUIRED_FLAGS "-fsanitize=undefined")
    set(CMAKE_REQUIRED_LINK_OPTIONS "-fsanitize=undefined")
    check_cxx_source_compiles("${TEST_PROGRAM}" HAS_UBSAN_LINK_SUPPORT)

    if(HAS_UBSAN_LINK_SUPPORT)
      message(STATUS "UndefinedBehaviorSanitizer is supported at both compile and link time.")
      set(SUPPORTS_UBSAN ON)
    else()
      message(WARNING "UndefinedBehaviorSanitizer is NOT supported at link time.")
      set(SUPPORTS_UBSAN OFF)
    endif()
  else()
    set(SUPPORTS_UBSAN OFF)
  endif()

  if((CMAKE_CXX_COMPILER_ID MATCHES ".*Clang.*" OR CMAKE_CXX_COMPILER_ID MATCHES ".*GNU.*") AND WIN32)
    set(SUPPORTS_ASAN OFF)
  else()
    if (NOT WIN32)
      message(STATUS "Sanity checking AddressSanitizer, it should be supported on this platform")
      set(TEST_PROGRAM "int main() { return 0; }")

      # Check if AddressSanitizer works at link time
      set(CMAKE_REQUIRED_FLAGS "-fsanitize=address")
      set(CMAKE_REQUIRED_LINK_OPTIONS "-fsanitize=address")
      check_cxx_source_compiles("${TEST_PROGRAM}" HAS_ASAN_LINK_SUPPORT)

      if(HAS_ASAN_LINK_SUPPORT)
        message(STATUS "AddressSanitizer is supported at both compile and link time.")
        set(SUPPORTS_ASAN ON)
      else()
        message(WARNING "AddressSanitizer is NOT supported at link time.")
        set(SUPPORTS_ASAN OFF)
      endif()
    else()
      set(SUPPORTS_ASAN ON)
    endif()
  endif()
endmacro()

macro(ZapretPP_setup_options)
  option(ZapretPP_ENABLE_HARDENING "Enable hardening" ON)
  option(ZapretPP_ENABLE_COVERAGE "Enable coverage reporting" OFF)
  cmake_dependent_option(
    ZapretPP_ENABLE_GLOBAL_HARDENING
    "Attempt to push hardening options to built dependencies"
    ON
    ZapretPP_ENABLE_HARDENING
    OFF)

  ZapretPP_supports_sanitizers()

  if(NOT PROJECT_IS_TOP_LEVEL OR ZapretPP_PACKAGING_MAINTAINER_MODE)
    option(ZapretPP_ENABLE_IPO "Enable IPO/LTO" OFF)
    option(ZapretPP_WARNINGS_AS_ERRORS "Treat Warnings As Errors" OFF)
    option(ZapretPP_ENABLE_SANITIZER_ADDRESS "Enable address sanitizer" OFF)
    option(ZapretPP_ENABLE_SANITIZER_LEAK "Enable leak sanitizer" OFF)
    option(ZapretPP_ENABLE_SANITIZER_UNDEFINED "Enable undefined sanitizer" OFF)
    option(ZapretPP_ENABLE_SANITIZER_THREAD "Enable thread sanitizer" OFF)
    option(ZapretPP_ENABLE_SANITIZER_MEMORY "Enable memory sanitizer" OFF)
    option(ZapretPP_ENABLE_UNITY_BUILD "Enable unity builds" OFF)
    option(ZapretPP_ENABLE_CLANG_TIDY "Enable clang-tidy" OFF)
    option(ZapretPP_ENABLE_CPPCHECK "Enable cpp-check analysis" OFF)
    option(ZapretPP_ENABLE_PCH "Enable precompiled headers" OFF)
    option(ZapretPP_ENABLE_CACHE "Enable ccache" OFF)
  elseif(ENABLE_DEVELOPER_MODE)
    option(ZapretPP_ENABLE_IPO "Enable IPO/LTO" ON)
    option(ZapretPP_WARNINGS_AS_ERRORS "Treat Warnings As Errors" ON)
    option(ZapretPP_ENABLE_SANITIZER_ADDRESS "Enable address sanitizer" ${SUPPORTS_ASAN})
    option(ZapretPP_ENABLE_SANITIZER_LEAK "Enable leak sanitizer" OFF)
    option(ZapretPP_ENABLE_SANITIZER_UNDEFINED "Enable undefined sanitizer" ${SUPPORTS_UBSAN})
    option(ZapretPP_ENABLE_SANITIZER_THREAD "Enable thread sanitizer" OFF)
    option(ZapretPP_ENABLE_SANITIZER_MEMORY "Enable memory sanitizer" OFF)
    option(ZapretPP_ENABLE_UNITY_BUILD "Enable unity builds" OFF)
    option(ZapretPP_ENABLE_CLANG_TIDY "Enable clang-tidy" ON)
    option(ZapretPP_ENABLE_CPPCHECK "Enable cpp-check analysis" ON)
    option(ZapretPP_ENABLE_PCH "Enable precompiled headers" OFF)
    option(ZapretPP_ENABLE_CACHE "Enable ccache" ON)
  else()
    option(ZapretPP_ENABLE_IPO "Enable IPO/LTO" ON)
    option(ZapretPP_WARNINGS_AS_ERRORS "Treat Warnings As Errors" OFF)
    option(ZapretPP_ENABLE_SANITIZER_ADDRESS "Enable address sanitizer" OFF)
    option(ZapretPP_ENABLE_SANITIZER_LEAK "Enable leak sanitizer" OFF)
    option(ZapretPP_ENABLE_SANITIZER_UNDEFINED "Enable undefined sanitizer" OFF)
    option(ZapretPP_ENABLE_SANITIZER_THREAD "Enable thread sanitizer" OFF)
    option(ZapretPP_ENABLE_SANITIZER_MEMORY "Enable memory sanitizer" OFF)
    option(ZapretPP_ENABLE_UNITY_BUILD "Enable unity builds" OFF)
    option(ZapretPP_ENABLE_CLANG_TIDY "Enable clang-tidy" OFF)
    option(ZapretPP_ENABLE_CPPCHECK "Enable cpp-check analysis" OFF)
    option(ZapretPP_ENABLE_PCH "Enable precompiled headers" OFF)
    option(ZapretPP_ENABLE_CACHE "Enable ccache" ON)
  endif()

  if(NOT PROJECT_IS_TOP_LEVEL)
    mark_as_advanced(
      ZapretPP_ENABLE_IPO
      ZapretPP_WARNINGS_AS_ERRORS
      ZapretPP_ENABLE_SANITIZER_ADDRESS
      ZapretPP_ENABLE_SANITIZER_LEAK
      ZapretPP_ENABLE_SANITIZER_UNDEFINED
      ZapretPP_ENABLE_SANITIZER_THREAD
      ZapretPP_ENABLE_SANITIZER_MEMORY
      ZapretPP_ENABLE_UNITY_BUILD
      ZapretPP_ENABLE_CLANG_TIDY
      ZapretPP_ENABLE_CPPCHECK
      ZapretPP_ENABLE_LIZARD
      ZapretPP_ENABLE_BLOATY
      ZapretPP_ENABLE_COVERAGE
      ZapretPP_ENABLE_PCH
      ZapretPP_ENABLE_CACHE)
  endif()

  ZapretPP_check_libfuzzer_support(LIBFUZZER_SUPPORTED)
  if(LIBFUZZER_SUPPORTED AND (ZapretPP_ENABLE_SANITIZER_ADDRESS OR ZapretPP_ENABLE_SANITIZER_THREAD OR ZapretPP_ENABLE_SANITIZER_UNDEFINED))
    set(DEFAULT_FUZZER ON)
  else()
    set(DEFAULT_FUZZER OFF)
  endif()

  option(ZapretPP_BUILD_FUZZ_TESTS "Enable fuzz testing executable" ${DEFAULT_FUZZER})

endmacro()

macro(ZapretPP_global_options)
  if(ZapretPP_ENABLE_IPO)
    include(cmake/InterproceduralOptimization.cmake)
    ZapretPP_enable_ipo()
  endif()

  ZapretPP_supports_sanitizers()

  if(ZapretPP_ENABLE_HARDENING AND ZapretPP_ENABLE_GLOBAL_HARDENING)
    include(cmake/Hardening.cmake)
    if(NOT SUPPORTS_UBSAN 
       OR ZapretPP_ENABLE_SANITIZER_UNDEFINED
       OR ZapretPP_ENABLE_SANITIZER_ADDRESS
       OR ZapretPP_ENABLE_SANITIZER_THREAD
       OR ZapretPP_ENABLE_SANITIZER_LEAK)
      set(ENABLE_UBSAN_MINIMAL_RUNTIME FALSE)
    else()
      set(ENABLE_UBSAN_MINIMAL_RUNTIME TRUE)
    endif()
    message("${ZapretPP_ENABLE_HARDENING} ${ENABLE_UBSAN_MINIMAL_RUNTIME} ${ZapretPP_ENABLE_SANITIZER_UNDEFINED}")
    ZapretPP_enable_hardening(ZapretPP_options ON ${ENABLE_UBSAN_MINIMAL_RUNTIME})
  endif()
endmacro()

macro(ZapretPP_local_options)
  if(PROJECT_IS_TOP_LEVEL)
    include(cmake/StandardProjectSettings.cmake)
  endif()

  add_library(ZapretPP_warnings INTERFACE)
  add_library(ZapretPP_options INTERFACE)

  include(cmake/CompilerWarnings.cmake)
  ZapretPP_set_project_warnings(
    ZapretPP_warnings
    ${ZapretPP_WARNINGS_AS_ERRORS}
    ""
    ""
    ""
    "")

  include(cmake/Linker.cmake)
  # Must configure each target with linker options, we're avoiding setting it globally for now

  if(NOT EMSCRIPTEN)
    include(cmake/Sanitizers.cmake)
    ZapretPP_enable_sanitizers(
      ZapretPP_options
      ${ZapretPP_ENABLE_SANITIZER_ADDRESS}
      ${ZapretPP_ENABLE_SANITIZER_LEAK}
      ${ZapretPP_ENABLE_SANITIZER_UNDEFINED}
      ${ZapretPP_ENABLE_SANITIZER_THREAD}
      ${ZapretPP_ENABLE_SANITIZER_MEMORY})
  endif()

  set_target_properties(ZapretPP_options PROPERTIES UNITY_BUILD ${ZapretPP_ENABLE_UNITY_BUILD})

  if(ZapretPP_ENABLE_PCH)
    target_precompile_headers(
      ZapretPP_options
      INTERFACE
      <vector>
      <string>
      <utility>)
  endif()

  if(ZapretPP_ENABLE_CACHE)
    include(cmake/Cache.cmake)
    ZapretPP_enable_cache()
  endif()

  include(cmake/StaticAnalyzers.cmake)
  if(ZapretPP_ENABLE_CLANG_TIDY)
    ZapretPP_enable_clang_tidy(ZapretPP_options ${ZapretPP_WARNINGS_AS_ERRORS})
  endif()

  if(ZapretPP_ENABLE_CPPCHECK)
    ZapretPP_enable_cppcheck(${ZapretPP_WARNINGS_AS_ERRORS} "" # override cppcheck options
    )
  endif()
  
  if(ZapretPP_ENABLE_LIZARD)
    ZapretPP_enable_lizard(${ZapretPP_WARNINGS_AS_ERRORS})
  endif()
  
  if(ZapretPP_ENABLE_BLOATY)
    ZapretPP_enable_bloaty()
  endif()

  if(ZapretPP_ENABLE_COVERAGE)
    include(cmake/Tests.cmake)
    ZapretPP_enable_coverage(ZapretPP_options)
  endif()

  if(ZapretPP_WARNINGS_AS_ERRORS)
    check_cxx_compiler_flag("-Wl,--fatal-warnings" LINKER_FATAL_WARNINGS)
    if(LINKER_FATAL_WARNINGS)
      # This is not working consistently, so disabling for now
      target_link_options(ZapretPP_options INTERFACE -Wl,--fatal-warnings)
    endif()
  endif()

  if(ZapretPP_ENABLE_HARDENING AND NOT ZapretPP_ENABLE_GLOBAL_HARDENING)
    include(cmake/Hardening.cmake)
    if(NOT SUPPORTS_UBSAN 
       OR ZapretPP_ENABLE_SANITIZER_UNDEFINED
       OR ZapretPP_ENABLE_SANITIZER_ADDRESS
       OR ZapretPP_ENABLE_SANITIZER_THREAD
       OR ZapretPP_ENABLE_SANITIZER_LEAK)
      set(ENABLE_UBSAN_MINIMAL_RUNTIME FALSE)
    else()
      set(ENABLE_UBSAN_MINIMAL_RUNTIME TRUE)
    endif()
    ZapretPP_enable_hardening(ZapretPP_options OFF ${ENABLE_UBSAN_MINIMAL_RUNTIME})
  endif()

endmacro()
