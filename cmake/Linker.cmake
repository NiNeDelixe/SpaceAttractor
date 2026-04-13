macro(ZapretPP_configure_linker project_name)
  set(ZapretPP_USER_LINKER_OPTION
    "DEFAULT"
      CACHE STRING "Linker to be used")
    set(ZapretPP_USER_LINKER_OPTION_VALUES "DEFAULT" "SYSTEM" "LLD" "GOLD" "BFD" "MOLD" "SOLD" "APPLE_CLASSIC" "MSVC")
  set_property(CACHE ZapretPP_USER_LINKER_OPTION PROPERTY STRINGS ${ZapretPP_USER_LINKER_OPTION_VALUES})
  list(
    FIND
    ZapretPP_USER_LINKER_OPTION_VALUES
    ${ZapretPP_USER_LINKER_OPTION}
    ZapretPP_USER_LINKER_OPTION_INDEX)

  if(${ZapretPP_USER_LINKER_OPTION_INDEX} EQUAL -1)
    message(
      STATUS
        "Using custom linker: '${ZapretPP_USER_LINKER_OPTION}', explicitly supported entries are ${ZapretPP_USER_LINKER_OPTION_VALUES}")
  endif()

  set_target_properties(${project_name} PROPERTIES LINKER_TYPE "${ZapretPP_USER_LINKER_OPTION}")
endmacro()
