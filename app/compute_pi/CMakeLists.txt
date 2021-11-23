## ##############################
## Project name
## ##############################

project(compute_pi)

## ##############################
## Input
## ##############################

set(${PROJECT_NAME}_SOURCES
    main.cpp)

## ##############################
## Build rules
## ##############################

add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_SOURCES})

## ##############################
## Include rules
## ##############################

include_directories(${pi_rm_lib_SOURCE_DIR})

## ##############################
## Link rules
## ##############################

target_link_libraries(${PROJECT_NAME} pi_rm_lib)
