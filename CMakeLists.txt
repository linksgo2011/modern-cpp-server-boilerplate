cmake_minimum_required(VERSION 2.8.12)
project(modernCpp)

set(SOURCES
        src/Logger.cpp
        src/Server.cpp
        src/main.cpp
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
