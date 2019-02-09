cmake_minimum_required(VERSION 3.0.0)
project(chap_6th VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_CXX_FLAGS 
  ${CMAKE_CXX_FLAGS} "-Weffc++ -Wall -Wextra -pedantic -Wconversion -Wdouble-promotion")

add_definitions(-std=c++11)

add_executable(chap_7th_42_1 src/chap_7th_42_1.cpp)
add_executable(chap_7th_42_2 src/chap_7th_42_2.cpp)
add_executable(chap_7th_43_1 src/chap_7th_43_1.cpp)
add_executable(chap_7th_43_2 src/chap_7th_43_2.cpp)
add_executable(chap_7th_44_1 src/chap_7th_44_1.cpp)
add_executable(chap_7th_44_2 src/chap_7th_44_2.cpp)
add_executable(chap_7th_44_3 src/chap_7th_44_3.cpp)
add_executable(chap_7th_44_4 src/chap_7th_44_4.cpp)
add_executable(chap_7th_44_5 src/chap_7th_44_5.cpp)
add_executable(chap_7th_44_6 src/chap_7th_44_6.cpp)
add_executable(chap_7th_46_1 src/chap_7th_46_1.cpp)
add_executable(chap_7th_46_2 src/chap_7th_46_2.cpp)
add_executable(chap_7th_46_3 src/chap_7th_46_3.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
