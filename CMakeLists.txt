cmake_minimum_required(VERSION 3.0)
project(Sorting)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall")
set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/source")

set(HEADERS ${INCLUDE_DIR}/sort.hpp ${INCLUDE_DIR}/usefull_funcs.hpp)
set(SOURCES ${SOURCE_DIR}/main.cpp ${SOURCE_DIR}/sort.cpp ${SOURCE_DIR}/usefull_funcs.cpp)

add_executable(Sorting ${SOURCES} ${HEADERS})
target_include_directories(Sorting PRIVATE ${INCLUDE_DIR})
