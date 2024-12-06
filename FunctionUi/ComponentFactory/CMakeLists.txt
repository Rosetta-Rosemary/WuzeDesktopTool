cmake_minimum_required(VERSION 3.14)

project(ComponentFactory LANGUAGES CXX)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin) 
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib) 
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if(WIN32)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib) 
elseif(APPLE)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin) 
elseif(UNIX)
        # Nothing special required
else()
        message(SEND_ERROR "You are on an unsupported platform! (Not Win32, Mac OS X or Unix)")
endif(WIN32)

set(CMAKE_DEBUG_POSTFIX "_d")    
set(CMAKE_RELEASE_POSTFIX "_r") 
set_target_properties(${TARGET_NAME} PROPERTIES DEBUG_POSTFIX "_d") 
set_target_properties(${TARGET_NAME} PROPERTIES RELEASE_POSTFIX "_r")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools)

include_directories("${CMAKE_CURRENT_LIST_DIR}/include/")

FILE(GLOB_RECURSE CODE_SRC "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp"
                                "${CMAKE_CURRENT_LIST_DIR}/include/*.hpp"
                                "${CMAKE_CURRENT_LIST_DIR}/include/*.h")

add_library(${PROJECT_NAME} SHARED ${CODE_SRC})

target_link_libraries(${PROJECT_NAME} PRIVATE  Qt6::Widgets WidgetFactory)


target_compile_definitions(${PROJECT_NAME} PRIVATE COMPONENTFACTORY_LIB WIDGETFACTORY_LIB)

set(resource_include ${CMAKE_BINARY_DIR}/bin/resource)
execute_process( COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/res ${resource_include})
