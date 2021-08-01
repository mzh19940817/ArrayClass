CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

include("config.cmake")

PROJECT(${proj_name})

INCLUDE_DIRECTORIES( 
"${CMAKE_CURRENT_SOURCE_DIR}/include"
)

if(${c_type} STREQUAL "64Bits")
    message("-- compile this project as 64Bits")
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -m64 ")
ELSE()
    message("-- copmile this porject as 32Bits")
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -m32")
ENDIF()

FILE(GLOB_RECURSE all_files 
include/*.h
include/*.hpp
include/*.tcc
src/*.cpp
src/*.cc
src/*.c
test/*.h
test/*.hpp
test/*.tcc
test/*.cpp
test/*.cc
test/*.c)

set(CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE})

add_executable(${proj_name} ${all_files})

if(${c_type} STREQUAL "64Bits")
    message("-- links this project as 64Bits")
    target_link_libraries(${proj_name} pthread stdc++)
else()
    message("-- links this project as 32Bits")
    target_link_libraries(${proj_name} pthread stdc++)
endif()

