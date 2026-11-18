cmake_minimum_required(VERSION 3.16)
project(cpp_text_analyzer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(text_input src/text_input.cpp src/word_counts.cpp src/file_reader.cpp)
target_include_directories(text_input PUBLIC include)

if(MSVC)
    target_compile_options(text_input PRIVATE /W4)
else()
    target_compile_options(text_input PRIVATE -Wall -Wextra -pedantic)
endif()

add_executable(text_analyzer src/main.cpp)
target_link_libraries(text_analyzer PRIVATE text_input)

enable_testing()
add_executable(test_text_input tests/test_text_input.cpp)
target_link_libraries(test_text_input PRIVATE text_input)
add_test(NAME text_input_baseline COMMAND test_text_input)

add_executable(test_word_counts tests/test_word_counts.cpp)
target_link_libraries(test_word_counts PRIVATE text_input)
add_test(NAME word_counts_baseline COMMAND test_word_counts)

add_executable(test_file_reader tests/test_file_reader.cpp)
target_link_libraries(test_file_reader PRIVATE text_input)
add_test(NAME file_reader_baseline COMMAND test_file_reader)
set_tests_properties(file_reader_baseline PROPERTIES WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}")

add_test(NAME cli_multifile COMMAND ${CMAKE_COMMAND}
    -DPROGRAM=$<TARGET_FILE:text_analyzer>
    -DFIXTURES=${CMAKE_CURRENT_SOURCE_DIR}/tests
    -P ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_cli.cmake)
