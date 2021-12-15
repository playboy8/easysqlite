cmake_minimum_required(VERSION 3.0.0)

set(name  easysqlit)
project (${name})

set(vendor_dir /home/wangli/code/some_tools/gen_vendor/vendor )
set(boost_inc_dir ${vendor_dir}/boost/boost_1_77_0/boost_out/lib )
set(boost_lib_dir ${vendor_dir}/boost/boost_1_77_0/boost_out/include )
set(boost_libs )

set( src_dir   .    )
file( GLOB  sources  ${CMAKE_SOURCE_DIR}  ${CMAKE_SOURCE_DIR}/*  )


#set(CMAKE_CXX_FLAGS " -pthread " )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -ldl  -std=c++11 -pthread ")

#link_directories("${CMAKE_SOURCE_DIR}/build")

#include_directories("${CMAKE_SOURCE_DIR}/include")

 
add_library(${name}  ${sources} )

#target_link_libraries(${name}    PUBLIC       ${CMAKE_SOURCE_DIR}/hiredis.so   )

message(STATUS "\n\
     info :     ${CMAKE_SOURCE_DIR}\n
     sources:    ${sources} \n
")

