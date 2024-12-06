include_directories("${CMAKE_CURRENT_LIST_DIR}/../MainFrameUi/WidgetFactory/include/")
include_directories("${CMAKE_CURRENT_LIST_DIR}/ComponentFactory/include/")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib) 
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/plugin) 
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/plugin)

if(WIN32)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/plugin)
elseif(APPLE)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/plugin) 
elseif(UNIX)
        # Nothing special required
else()
        message(SEND_ERROR "You are on an unsupported platform! (Not Win32, Mac OS X or Unix)")
endif(WIN32)


FOREACH (this_dir
    ComponentFactory
    FunctionPage
    )
    add_subdirectory(${this_dir})
endforeach(this_dir)
