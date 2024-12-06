
cmake_minimum_required(VERSION 3.5)
project(WuzeDesktopTool LANGUAGES CXX)

# set the project name and version
project(${PROJECT_NAME} VERSION 1.0)

set(CMAKE_BUILD_TYPE "MinSizeRel")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
# set(CMAKE_PREFIX_PATH "e:/Qt/6.6.0/mingw_64") # Qt Kit Dir
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# cmake 生成 VS2022 工程并编译时取消此段注释 
# add_compile_options("/permissive-")
# add_compile_options("/Zc:__cplusplus")
# add_compile_options("/source-charset:UTF-8")

# 没有添加 qt6config.cmake 的环境变量时，释放此段注释，
# 并手动指定qt对应的cmake配置文件路径
#list(APPEND CMAKE_PREFIX_PATH /Users/rosettailya/Qt/6.8.0/macos/lib/cmake)
find_package(Qt6 COMPONENTS Widgets REQUIRED) # Qt COMPONENTS

if(WIN32)
    if(MSVC)
        #set_target_properties(${PROJECT_NAME} PROPERTIES WIN32_EXECUTABLE YES LINK_FLAGS "/ENTRY:mainCRTStartup")
    elseif(CMAKE_COMPILER_IS_GNUCXX)
        SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mwindows") # Not tested
    else()
        message(SEND_ERROR "You are using an unsupported Windows compiler! (Not MSVC or GCC)")
    endif(MSVC)
elseif(APPLE)
    set_target_properties(${TARGET_NAME} PROPERTIES MACOSX_BUNDLE YES)
elseif(UNIX)
        # Nothing special required
else()
        message(SEND_ERROR "You are on an unsupported platform! (Not Win32, Mac OS X or Unix)")
endif(WIN32)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin) 
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib) 
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

FOREACH (this_dir
    MainFrameUi
    FunctionUi
    )
    add_subdirectory(${this_dir})
endforeach(this_dir)

include_directories("${CMAKE_CURRENT_LIST_DIR}/MainFrameUi/MainWindow/include")

set(CMAKE_DEBUG_POSTFIX "_d")    
set(CMAKE_RELEASE_POSTFIX "_r") 
set_target_properties(${TARGET_NAME} PROPERTIES DEBUG_POSTFIX "_d") 
set_target_properties(${TARGET_NAME} PROPERTIES RELEASE_POSTFIX "_r")

add_executable(${PROJECT_NAME} main.cpp Resource.rc)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets) # Qt5 Shared Library
target_link_libraries(${PROJECT_NAME} PUBLIC MainWindow)

set(resource_include ${CMAKE_BINARY_DIR}/bin/resource)
execute_process( COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/Resource ${resource_include})