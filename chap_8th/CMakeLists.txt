cmake_minimum_required(VERSION 3.0.0)
project(chap_6th VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_CXX_FLAGS 
  ${CMAKE_CXX_FLAGS} "-Weffc++ -Wall -Wextra -pedantic -Wconversion -Wdouble-promotion")

add_definitions(-std=c++11)

add_executable(chap_8th_52_1 src/chap_8th_52_1.cpp)
add_executable(chap_8th_52_2 src/chap_8th_52_2.cpp)
add_executable(chap_8th_52_3 src/chap_8th_52_3.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
