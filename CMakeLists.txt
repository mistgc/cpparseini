cmake_minimum_required(VERSION 3.10)

project(cpparseini)

file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc)

option(DEBUG "debug mode" off)
if(DEBUG)
    add_definitions(-DDEBUG)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS on)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

add_library(cpparseini STATIC ${SRC_FILES})

target_include_directories(cpparseini PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(test)
