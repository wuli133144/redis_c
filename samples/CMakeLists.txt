
project(list)

cmake_minimum_required(VERSION 2.8)


set(LIST_SRC main.c adlist.h adlist.c utils.h)
#aux_source_directory(./ list_src)

set(CMAKE_BUILD_TYPE "Debug")
add_definitions(-DDEBUG)


add_executable(list ${LIST_SRC})


INSTALL( TARGETS list
         RUNTIME DESTINATION bin
    )
