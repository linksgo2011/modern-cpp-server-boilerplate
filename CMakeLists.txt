cmake_minimum_required(VERSION 2.8.12)
project(modernCpp)

set(SOURCES
        src/lib/Logger.cpp
        src/Server.cpp
        src/main.cpp
        )

add_definitions("-std=c++11")

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


# lib for testing
add_library(lib
        src/lib/Reverse.cpp
        )
target_include_directories(lib PUBLIC src/lib)
#target_include_directories(lib PUBLIC src/lib/inner)

# enable CTest testing
enable_testing()

add_executable(unit_tests
        test/unit_test.cpp
        )
find_package(GTest REQUIRED)

target_link_libraries(unit_tests
        lib
        GTest::GTest
        GTest::Main
        )

add_test(NAME ${PROJECT_NAME}_test COMMAND unit_tests)
