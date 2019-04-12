cmake_minimum_required(VERSION 2.8.8)

project(gtwp CXX)

add_library(gtwp INTERFACE)
file(GLOB_RECURSE GTWP_HDRS "*.h")
target_sources(gtwp INTERFACE ${GTWP_HDRS})

add_custom_target(gtwp.headers SOURCES ${GTWP_HDRS})

target_include_directories(gtwp SYSTEM INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

add_dependencies(gtwp googletest)
