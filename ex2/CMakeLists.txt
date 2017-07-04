cmake_minimum_required(VERSION 3.2)

#  Library 
set(LIBRARY_SOURCE_FILES
    src/Shape.cpp 
    src/Triangle.cpp
    src/Circle.cpp
    src/Square.cpp
    src/Rectangle.cpp
    src/ShapeSorter.cpp)

add_library(shape_sorter ${LIBRARY_SOURCE_FILES})
target_include_directories(shape_sorter PUBLIC include)

#  Executable 
set(EXECUTABLE_SOURCE_FILES ${LIBRARY_SOURCE_FILES} src/main.cpp)
add_executable(shape_sorter_exe ${EXECUTABLE_SOURCE_FILES})
target_include_directories(shape_sorter_exe PUBLIC include)

#  Tests
set(LIBRARY_TEST_SOURCE_FILES 
    test/TriangleTest.cpp
    test/CircleTest.cpp
    test/SquareTest.cpp
    test/RectangleTest.cpp
    test/ShapeSorterTest.cpp)

add_executable(shape_sorter_test ${LIBRARY_TEST_SOURCE_FILES})
target_include_directories(shape_sorter_test PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}}/include")
message(STATUS "SOURCE_DIR: ***${CMAKE_CURRENT_SOURCE_DIR}/include")

target_include_directories(shape_sorter_test PRIVATE test "${gtest_SOURCE_DIR}/include")
target_link_libraries(shape_sorter_test shape_sorter gtest_main)

target_include_directories(shape_sorter_test PRIVATE "${gmock_SOURCE_DIR}/include")
target_link_libraries(shape_sorter_test gmock)

add_test(NAME shape_sorter_test COMMAND shape_sorter_test)
