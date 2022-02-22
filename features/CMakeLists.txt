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
add_executable(exercise_operations 08-operators/main.cpp)
add_executable(exercise_loops 09-loops/main.cpp)
add_executable(exercise_decision 10-decision/main.cpp)
add_executable(exercise_functions 11-functions/main.cpp)
add_executable(exercise_math 12-math/main.cpp)
add_executable(exercise_arrays 13-arrays/main.cpp)
add_executable(exercise_strings 14-strings/main.cpp)
add_executable(exercise_pointer 15-pointer/main.cpp)

# enable CTest testing
enable_testing()

add_executable(feature_unit_tests 01-basic/main_test.cpp)
find_package(GTest REQUIRED)

target_link_libraries(feature_unit_tests
        GTest::GTest
        GTest::Main
        )
add_test(NAME ${PROJECT_NAME}_test COMMAND feature_unit_tests)