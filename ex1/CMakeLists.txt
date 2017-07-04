cmake_minimum_required(VERSION 3.2)

#  Library 
set(LIBRARY_SOURCE_FILES 
    src/CountWordFrequency.cpp
    src/StripPunctuation.cpp)
add_library(count_word_frequency ${LIBRARY_SOURCE_FILES})
target_include_directories(count_word_frequency PUBLIC include)

#  Executable 
set(EXECUTABLE_SOURCE_FILES ${LIBRARY_SOURCE_FILES} src/main.cpp)
add_executable(count_word_frequency_exe ${EXECUTABLE_SOURCE_FILES})
target_include_directories(count_word_frequency_exe PUBLIC include)

#  Tests
set(LIBRARY_TEST_SOURCE_FILES 
    test/CountWordFrequencyTest.cpp
    test/DiscardWhitespaceTest.cpp
    test/StripPunctuationTest.cpp
    test/TakeWordTest.cpp
    test/PairRangeToOrderedVectorTest.cpp)
add_executable(count_word_frequency_test ${LIBRARY_TEST_SOURCE_FILES})
target_include_directories(count_word_frequency_test PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}}/include")
message(STATUS "SOURCE_DIR: ***${CMAKE_CURRENT_SOURCE_DIR}/include")

target_include_directories(count_word_frequency_test PRIVATE test "${gtest_SOURCE_DIR}/include")
target_link_libraries(count_word_frequency_test count_word_frequency gtest_main)

target_include_directories(count_word_frequency_test PRIVATE "${gmock_SOURCE_DIR}/include")
target_link_libraries(count_word_frequency_test gmock)

add_test(NAME count_word_frequency_test COMMAND count_word_frequency_test)
