cmake_minimum_required(VERSION 3.14)

project(MainToolBox LANGUAGES CXX)

set(CMAKE_DEBUG_POSTFIX "_d")    
set(CMAKE_RELEASE_POSTFIX "_r") 
set_target_properties(${TARGET_NAME} PROPERTIES DEBUG_POSTFIX "_d") 
set_target_properties(${TARGET_NAME} PROPERTIES RELEASE_POSTFIX "_r")

set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools)

include_directories("${CMAKE_CURRENT_LIST_DIR}/..//WidgetFactory/include/")
include_directories("${CMAKE_SOURCE_DIR}/FunctionUi/FunctionPage/include/")
include_directories("${CMAKE_SOURCE_DIR}/FunctionUi/NavigationPage/include/")
include_directories("${CMAKE_SOURCE_DIR}/FunctionUi/MappathCalcPage/include/")



include_directories("${CMAKE_CURRENT_LIST_DIR}/include/")

FILE(GLOB_RECURSE MAINTOOLBOX_SRC "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp"
                                "${CMAKE_CURRENT_LIST_DIR}/include/*.hpp"
                                "${CMAKE_CURRENT_LIST_DIR}/include/*.h")

add_library(${PROJECT_NAME} SHARED ${MAINTOOLBOX_SRC})

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets) # Qt6 Shared Library
target_link_libraries(${PROJECT_NAME} PUBLIC WidgetFactory) # Qt6 Shared Library
target_compile_definitions(${PROJECT_NAME} PRIVATE MAINTOOLBOX_LIB WIDGETFACTORY_LIB)

