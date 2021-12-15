cmake_minimum_required(VERSION 3.0.0)

set(name  sqlit_demo)
project (${name})


set(vendor_dir /home/wangli/code/some_tools/gen_vendor/vendor )
set(boost_inc_dir ${vendor_dir}/boost/boost_1_77_0/boost_out/lib )
set(boost_lib_dir ${vendor_dir}/boost/boost_1_77_0/boost_out/include )
set(boost_libs   )


if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        set (lib "hiredis-d.so")
else()
        set (lib "hiredis.so")
endif()

file( GLOB  sources  ${CMAKE_SOURCE_DIR}    ./*.cpp   ${CMAKE_SOURCE_DIR}/easySQLite/* ./UnitTest++/src/* ./UnitTest++/src/Posix/*     )
#file( GLOB  header  ${CMAKE_SOURCE_DIR}    ./*.cpp   ${CMAKE_SOURCE_DIR}/easySQLite/*  ./UnitTest++/src/*  )

#if used  boost  KDB
# add_definitions(-DKXVER=3) 
add_definitions(-DLINUX)
#add_definitions(-DBOOST_ALL_DYN_LINK)

#set(CMAKE_CXX_FLAGS " -pthread " ) -Werror  
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb3 -m64 -Wno-unused-parameter  -std=c++11    -MMD -Wall  -fPIC -Wno-unknown-pragmas" ) 

#link_directories("${CMAKE_SOURCE_DIR}/build")


#include_directories("${CMAKE_SOURCE_DIR}/include")
 

add_executable(  ${name}  ${sources}  )

#target_link_libraries(${name}    PUBLIC       ${CMAKE_SOURCE_DIR}/hiredis.so       )
target_link_libraries(${name} PUBLIC dl pthread )

message(STATUS "\n\
     info :     ${CMAKE_SOURCE_DIR}\n
     sources:    ${sources} \n
")

