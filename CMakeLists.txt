cmake_minimum_required(VERSION 3.5)

## ##############################
## Project name
## ##############################

project(pi_rm_project)

## ##############################
## Path setup
## ##############################

include(GNUInstallDirs)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

## ##############################
## Build rules
## ##############################

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

## ##############################
## MPI linking
## ##############################

find_package(MPI REQUIRED)
include_directories(SYSTEM ${MPI_INCLUDE_PATH})
link_libraries(${MPI_CXX_LIBRARIES})

## ##############################
## Input
## ##############################

add_subdirectory(src)
add_subdirectory(app)
