add_executable(main_ta main.cpp)

if(ENV STREQUAL "DEV")
    add_library(surakarta_ta_lib SHARED surakarta_rule_manager_imp.h surakarta_rule_manager_imp.cpp)
    target_link_libraries(surakarta_ta_lib surakarta)
    install(TARGETS surakarta_ta_lib DESTINATION ${INSTALL_DIR}/lib)

    
    add_library(surakarta_ta STATIC surakarta_rule_manager_imp.h surakarta_rule_manager_imp.cpp)
    target_link_libraries(surakarta_ta surakarta)
    target_link_libraries(main_ta surakarta_ta)
else()
    find_library(SURAKARTA_TA_LIB surakarta_ta_lib ${CMAKE_SOURCE_DIR}/surakarta_ta/lib)
    add_library(surakarta_ta_lib SHARED IMPORTED)
    set_target_properties(surakarta_ta_lib PROPERTIES IMPORTED_LOCATION ${SURAKARTA_TA_LIB})
    target_link_libraries(main_ta surakarta surakarta_ta_lib)
endif()