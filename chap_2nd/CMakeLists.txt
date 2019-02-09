cmake_minimum_required(VERSION 3.0.0)
project(chap_2nd VERSION 0.1.0)

include(CTest)
enable_testing()

add_compile_options(--std=c++11)

set(CMAKE_CXX_FLAGS 
  ${CMAKE_CXX_FLAGS} "-Weffc++ -Wall -Wextra -pedantic -Wconversion -Wdouble-promotion")

add_executable(chap_2nd_5_1  src/chap_2nd_5_1.cpp)
add_executable(chap_2nd_5_2  src/chap_2nd_5_2.cpp)
add_executable(chap_2nd_5_3  src/chap_2nd_5_3.cpp)
add_executable(chap_2nd_6_1  src/chap_2nd_6_1.cpp)
add_executable(chap_2nd_6_2  src/chap_2nd_6_2.cpp)
add_executable(chap_2nd_7_1  src/chap_2nd_7_1.cpp)
add_executable(chap_2nd_10_1 src/chap_2nd_10_1.cpp)
add_executable(chap_2nd_10_2 src/chap_2nd_10_2.cpp)
add_executable(chap_2nd_12_1 src/chap_2nd_12_1.cpp)
add_executable(chap_2nd_12_2 src/chap_2nd_12_2.cpp)
add_executable(chap_2nd_12_3 src/chap_2nd_12_3.cpp)
add_executable(chap_2nd_12_4 src/chap_2nd_12_4.cpp)
add_executable(chap_2nd_12_5 src/chap_2nd_12_5.cpp)
add_executable(chap_2nd_12_6 src/chap_2nd_12_6.cpp)
add_executable(chap_2nd_12_7 src/chap_2nd_12_7.cpp)
add_executable(chap_2nd_12_8 src/chap_2nd_12_8.cpp)
add_executable(chap_2nd_12_9 src/chap_2nd_12_9.cpp)
add_executable(chap_2nd_12_10 src/chap_2nd_12_10.cpp)
add_executable(chap_2nd_12_11 src/chap_2nd_12_11.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
