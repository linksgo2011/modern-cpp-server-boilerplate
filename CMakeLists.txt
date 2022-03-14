cmake_minimum_required(VERSION 2.8.12)
project(modernCpp)

# Set the compiler options

set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)
add_definitions("-std=c++11")

set(SOURCES
        src/lib/Logger.cpp
        src/Server.cpp
        src/main.cpp
        )


include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(modernCpp ${SOURCES})
target_link_libraries(
        modernCpp
        ${CONAN_LIBS}
        lib
)

target_include_directories(${PROJECT_NAME}
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        )

# Create the gcov target. Run coverage tests with 'make gcov'


# lib for testing
add_library(lib
        src/lib/Reverse.cpp
        src/lib/Logger.cpp
        )
target_include_directories(lib PUBLIC src/lib)
#target_include_directories(lib PUBLIC src/lib/inner)

# enable CTest testing
enable_testing()

add_executable(unit_tests
        test/unit_test.cpp
        )

target_link_libraries(unit_tests
        lib
        gmock_main
        gtest_main
        )

add_test(NAME ${PROJECT_NAME}_test COMMAND unit_tests)

add_subdirectory(features)