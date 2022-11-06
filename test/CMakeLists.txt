add_executable(test_read_valid_line test_read_valid_line.cc)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin/test)

target_include_directories(test_read_valid_line PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)

target_link_libraries(test_read_valid_line PUBLIC cpparseini)


