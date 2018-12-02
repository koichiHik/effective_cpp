cmake_minimum_required(VERSION 3.0.0)
project(chap_4th VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_CXX_FLAGS 
  ${CMAKE_CXX_FLAGS} "-Wall -Wextra -pedantic -Wconversion -Wdouble-promotion")

add_executable(chap_4th_21_1 src/chap_4th_21_1.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
