cmake_minimum_required(VERSION 3.0.0)
project(chap_3rd VERSION 0.1.0)

include(CTest)
enable_testing()

add_definitions(-std=c++11)

add_executable(chap_3rd_13_1 src/chap_3rd_13_1.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
