cmake_minimum_required(VERSION 3.0.0)
project(chap_2nd VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_CXX_FLAGS 
  ${CMAKE_CXX_FLAGS} "-Wall -Wextra -pedantic -Wconversion -Wdouble-promotion")

add_executable(chap_2nd_5_1  src/chap_2nd_5_1.cpp)
add_executable(chap_2nd_5_2  src/chap_2nd_5_2.cpp)
add_executable(chap_2nd_5_3  src/chap_2nd_5_3.cpp)
add_executable(chap_2nd_7_1  src/chap_2nd_7_1.cpp)
add_executable(chap_2nd_10_1 src/chap_2nd_10_1.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
