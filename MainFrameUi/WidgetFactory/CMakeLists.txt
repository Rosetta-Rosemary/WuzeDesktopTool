cmake_minimum_required(VERSION 3.14)

project(WidgetFactory LANGUAGES CXX)

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

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets) # Qt6 Shared Library
target_compile_definitions(${PROJECT_NAME} PRIVATE WIDGETFACTORY_LIB)

