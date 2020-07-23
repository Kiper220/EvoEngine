

add_library(rtl_window SHARED
        src/PWindow.cpp
        src/Window.cpp
        src/Cursor.cpp)

add_library(RTL::Window ALIAS rtl_window)
target_link_libraries(rtl_window RTL::Types RTL::Math X11 Xrender glad GLX)
target_include_directories(rtl_window PUBLIC include ${RTL_SOURCE_DIR})

set_target_properties(rtl_window
        PROPERTIES
        EXECUTABLE_OUTPUT_PATH "${EngineSourceDirectory}/BIN/EvoEngine"
        LIBRARY_OUTPUT_DIRECTORY "${EngineSourceDirectory}/BIN/EvoEngine/lib"
        RUNTIME_OUTPUT_DIRECTORY  "${EngineSourceDirectory}/BIN/EvoEngine"
        )