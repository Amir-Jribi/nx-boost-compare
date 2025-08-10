cmake_minimum_required(VERSION 3.27)
project(fastgraph)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Find Python 3 interpreter and development files (headers + libraries)
find_package(Python3 COMPONENTS Development Interpreter REQUIRED)



# Optional: Print Python version and include dir to verify
message(STATUS "Python3 version: ${Python3_VERSION}")
message(STATUS "Python3 include dir: ${Python3_INCLUDE_DIRS}")

if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/ext/nanobind)
nanobind_add_module(fastgraph fastgraph.cpp)
target_include_directories(fastgraph
    PRIVATE
        ${Python3_INCLUDE_DIRS}
)

# Nanobind
#include(FetchContent)
#FetchContent_Declare(
#  nanobind
#  GIT_REPOSITORY https://github.com/wjakob/nanobind.git
#  GIT_TAG        master
#)
#FetchContent_MakeAvailable(nanobind)

#add_subdirectory(_deps/nanobind-src)
#add_library(fastgraph MODULE fastgraph.cpp)

#target_include_directories(fastgraph PRIVATE ${CMAKE_SOURCE_DIR}/build/_deps/nanobind-src/include)
#target_include_directories(fastgraph PRIVATE nanobind::nanobind Python3::Python)

#target_link_libraries(fastgraph PRIVATE nanobind::nanobind)

#set_target_properties(fastgraph PROPERTIES PREFIX "" SUFFIX ".so")

