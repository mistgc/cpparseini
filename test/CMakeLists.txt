set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin/test)

set(test_cases add_section display modify_section read_valid_line remove_section)

foreach(item IN LISTS test_cases)
    add_executable(
        test_${item}
        test_${item}.cc
    )
    
    target_include_directories(test_${item} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)

    target_link_libraries(test_${item} PUBLIC cpparseini)
endforeach()
