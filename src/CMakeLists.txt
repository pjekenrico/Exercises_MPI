## ##############################
## Project name
## ##############################

project(pi_rm_lib)

## ##############################
## Sources
## ##############################

set(${PROJECT_NAME}_HEADERS
  funcs.h)

set(${PROJECT_NAME}_SOURCES
  funcs.cpp)

## ##############################
## Build rules
## ##############################

add_library(${PROJECT_NAME} SHARED ${${PROJECT_NAME}_SOURCES} ${${PROJECT_NAME}_HEADERS})

