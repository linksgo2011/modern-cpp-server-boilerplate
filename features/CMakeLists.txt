cmake_minimum_required(VERSION 2.8.12)
project(exercise)

add_definitions("-std=c++11")

add_executable(exercise_basic 01-basic/main.cpp)
add_executable(exercise_basic_type 02-basic-types/main.cpp)
add_executable(exercise_variable_types 03-variable-types/main.cpp)
add_executable(exercise_variable_scope 04-variable-scope/main.cpp)
add_executable(exercise_const 05-const/main.cpp)
add_executable(exercise_modifier-type 06-modifier-types/main.cpp)
add_executable(exercise_storage-classes 07-storage-classes/main.cpp)

# enable CTest testing
enable_testing()

add_executable(feature_unit_tests 01-basic/main_test.cpp)
find_package(GTest REQUIRED)

target_link_libraries(feature_unit_tests
        GTest::GTest
        GTest::Main
        )
add_test(NAME ${PROJECT_NAME}_test COMMAND feature_unit_tests)