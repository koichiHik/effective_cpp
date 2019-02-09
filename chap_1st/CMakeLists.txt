cmake_minimum_required(VERSION 3.0.0)
project(chap_1st VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_CXX_FLAGS 
  ${CMAKE_CXX_FLAGS} "-Wall -Wextra -pedantic -Wconversion -Wdouble-promotion")

add_definitions(-std=gnu++0x)

add_executable(chap_1st_1_1 src/chap_1st_1_1.cpp)
add_executable(chap_1st_3_1 src/chap_1st_3_1.cpp)
add_executable(chap_1st_3_2 src/chap_1st_3_2.cpp)
add_executable(chap_1st_3_3 src/chap_1st_3_3.cpp)

#target_compile_options(
#  1st_chap_1
#  PRIVATE
#  $<$<CXX_COMPILER_ID:Clang>:-Wall -Weverything -Wno-c++98-compat -Wno-c++98-compat-pedantic>
#  $<$<CXX_COMPILER_ID:GNU>:-pedantic -Wno-long-long -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused>
#  $<$<CXX_COMPILER_ID:MSVC>:/W4>
#)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
