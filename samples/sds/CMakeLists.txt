
project(list)

cmake_minimum_required(VERSION 2.8)

#set(list_src main.c utils.h sds.h sds.c)
aux_source_directory(./ list_src)

message(STATUS "${list_src}")

set(CMAKE_BUILD_TYPE DEBUG)

set(CMAKE_C_FLAGS_DEBUG "-g -Wall")


add_definitions(-DDEBUG)

add_executable(list ${list_src})


INSTALL( TARGETS list
         RUNTIME DESTINATION bin
         )

