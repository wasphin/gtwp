cmake_minimum_required(VERSION 2.8.8)

if(POLICY CMP0048)
  cmake_policy(SET CMP0048 OLD)
endif()

project(gtwp
  LANGUAGES CXX)

option(GTWP_ENABLE_TESTS "Enable Tests" OFF)

add_library(gtwp INTERFACE)
file(GLOB_RECURSE GTWP_HDRS "include/*.h")
target_sources(gtwp INTERFACE ${GTWP_HDRS})

# make headers visible to IDE
add_custom_target(gtwp.headers SOURCES ${GTWP_HDRS})

target_include_directories(gtwp SYSTEM INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

macro(GTWP_ADD_TEST TST)
  file(GLOB _${TST}_SRCS "${TST}.cc" "${TST}.cpp" "${TST}.cxx")
  add_executable(${TST} ${_${TST}_SRCS} ${ARGN})
  target_link_libraries(${TST} gtwp gtest_main)
  add_test(${TST} ${TST})
endmacro()

if(GTWP_ENABLE_TESTS)
  enable_testing()

  if(EXISTS 3rd-party/googletest)
    add_subdirectory(3rd-party/googletest)
    add_subdirectory(test)
  endif()

  include(CTest)
endif()
