cmake_minimum_required(VERSION 2.8.12)
project(modernCpp)

set(SOURCES
        src/Logger.cpp
        src/Server.cpp
        src/main.cpp
        test/unit_test.cpp
        )

add_definitions("-std=c++11")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(modernCpp ${SOURCES})
target_link_libraries(modernCpp ${CONAN_LIBS})

target_include_directories(${PROJECT_NAME}
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        )

# enable CTest testing
include(CTest)
enable_testing()

add_executable(unit_tests
        test/unit_test.cpp
        )
find_package(GTest REQUIRED)

target_link_libraries(unit_tests
        GTest::GTest
        GTest::Main
        )

add_test(test_all unit_tests)