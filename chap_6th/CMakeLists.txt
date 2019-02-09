cmake_minimum_required(VERSION 3.0.0)
project(chap_6th VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_CXX_FLAGS 
#    ${CMAKE_CXX_FLAGS} "-Weffc++")
  ${CMAKE_CXX_FLAGS} "-Weffc++ -Wall -Wextra -pedantic -Wconversion -Wdouble-promotion")

add_definitions(-std=c++11)

add_executable(chap_6th_33_1 src/chap_6th_33_1.cpp)
add_executable(chap_6th_33_2 src/chap_6th_33_2.cpp)
add_executable(chap_6th_33_3 src/chap_6th_33_3.cpp)
add_executable(chap_6th_34_1 src/chap_6th_34_1.cpp)
add_executable(chap_6th_34_2 src/chap_6th_34_2.cpp)
add_executable(chap_6th_34_3 src/chap_6th_34_3.cpp)
add_executable(chap_6th_35_1 src/chap_6th_35_1.cpp)
add_executable(chap_6th_35_2 src/chap_6th_35_2.cpp)
add_executable(chap_6th_35_3 src/chap_6th_35_3.cpp)
add_executable(chap_6th_35_4 src/chap_6th_35_4.cpp)
add_executable(chap_6th_35_5 src/chap_6th_35_5.cpp)
add_executable(chap_6th_39_1 src/chap_6th_39_1.cpp)
add_executable(chap_6th_39_2 src/chap_6th_39_2.cpp)
add_executable(chap_6th_39_3 src/chap_6th_39_3.cpp)
add_executable(chap_6th_39_4 src/chap_6th_39_4.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
