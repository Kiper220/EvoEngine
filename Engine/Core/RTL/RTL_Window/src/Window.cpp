//
// Created by kiper220 on 07.07.2020.
//

#include <RTL/Window/Window.h>

namespace RTL::RWindow{

    int STDWindowWidth = 600;
    int STDWindowHeight = 400;
#ifdef linux
    const char* STDWindowName = "X11 Window";
#else
#ifdef WIN32
    const char* STDWindowName = "WINAPI Window";
    #endif
#endif


    Window::Window() {

    }
}