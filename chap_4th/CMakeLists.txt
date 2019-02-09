cmake_minimum_required(VERSION 3.0.0)
project(chap_4th VERSION 0.1.0)

include(CTest)
enable_testing()

add_compile_options(-std=c++11)

set(CMAKE_CXX_FLAGS 
  ${CMAKE_CXX_FLAGS} "-Weffc++ -Wall -Wextra -pedantic -Wconversion -Wdouble-promotion")

add_executable(chap_4th_21_1 src/chap_4th_21_1.cpp)
add_executable(chap_4th_24_1 src/chap_4th_24_1.cpp)
add_executable(chap_4th_24_2 src/chap_4th_24_2.cpp)
add_executable(chap_4th_24_3 src/chap_4th_24_3.cpp)
add_executable(chap_4th_24_4 src/chap_4th_24_4.cpp)
add_executable(chap_4th_25_1 src/chap_4th_25_1.cpp)
add_executable(chap_4th_25_2 src/chap_4th_25_2.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
