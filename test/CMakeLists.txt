set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin/test)

# test_read_valid_line

add_executable(test_read_valid_line test_read_valid_line.cc)

target_include_directories(test_read_valid_line PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)

target_link_libraries(test_read_valid_line PUBLIC cpparseini)

# test_display

add_executable(test_display test_display.cc)

target_include_directories(test_display PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)

target_link_libraries(test_display PUBLIC cpparseini)

# test_remove_section

add_executable(test_remove_section test_remove_section.cc)

target_include_directories(test_remove_section PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)

target_link_libraries(test_remove_section PUBLIC cpparseini)

# test_add_section

add_executable(test_add_section test_add_section.cc)

target_include_directories(test_add_section PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)

target_link_libraries(test_add_section PUBLIC cpparseini)

# test_modify_section

add_executable(test_modify_section test_modify_section.cc)

target_include_directories(test_modify_section PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)

target_link_libraries(test_modify_section PUBLIC cpparseini)
