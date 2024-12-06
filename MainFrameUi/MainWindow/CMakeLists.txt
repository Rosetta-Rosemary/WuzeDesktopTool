cmake_minimum_required(VERSION 3.14)

project(MainWindow LANGUAGES CXX)

set(CMAKE_DEBUG_POSTFIX "_d")    
set(CMAKE_RELEASE_POSTFIX "_r") 
set_target_properties(${TARGET_NAME} PROPERTIES DEBUG_POSTFIX "_d") 
set_target_properties(${TARGET_NAME} PROPERTIES RELEASE_POSTFIX "_r")

set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools)

include_directories("${CMAKE_CURRENT_LIST_DIR}/../MainToolBox/include/")
include_directories("${CMAKE_CURRENT_LIST_DIR}/include/")


FILE(GLOB_RECURSE MAINWINDOW_SRC "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp"
                                "${CMAKE_CURRENT_LIST_DIR}/include/*.hpp"
                                "${CMAKE_CURRENT_LIST_DIR}/include/*.h")

add_library(${PROJECT_NAME} SHARED ${MAINWINDOW_SRC})

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets) # Qt6 Shared Library
target_link_libraries(${PROJECT_NAME} PUBLIC MainToolBox)
target_compile_definitions(${PROJECT_NAME} PRIVATE MAINWINDOW_LIB MAINTOOLBOX_LIB)

set(resource_include ${CMAKE_BINARY_DIR}/bin/resource)
execute_process( COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/res ${resource_include})

