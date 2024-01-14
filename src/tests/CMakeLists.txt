add_executable(hello_cpp_test hello_cpp_test.cpp)
target_link_libraries(hello_cpp_test PRIVATE hello_cpp gtest gtest_main)

add_executable(surakarta_rule_manager_test surakarta_rule_manager_test.cpp)

get_filename_component(TEST_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}" ABSOLUTE)
add_definitions(-DTEST_DATA_DIR="${TEST_SOURCE_DIR}/test_data/")

if(ENV STREQUAL "DEV")
    target_link_libraries(surakarta_rule_manager_test PRIVATE surakarta surakarta_ta gtest gtest_main)
else()
    find_library(SURAKARTA_TA_LIB surakarta_ta_lib ${CMAKE_SOURCE_DIR}/surakarta_ta/lib)
    add_library(surakarta_ta_lib SHARED IMPORTED)
    set_target_properties(surakarta_ta_lib PROPERTIES IMPORTED_LOCATION ${SURAKARTA_TA_LIB})
    
    target_link_libraries(surakarta_rule_manager_test PRIVATE surakarta surakarta_ta_lib gtest gtest_main)
endif()