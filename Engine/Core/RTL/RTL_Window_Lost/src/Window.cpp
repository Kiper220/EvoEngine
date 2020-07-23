//
// Created by kiper220 on 07.07.2020.
//

#include <RTL/Window/Window.h>
#include <RTL/Thread.h>

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

    Window::Window(): PWindow(GLWindow){

    }
    Window::Window(WindowType windowType): PWindow(windowType){

    }
    void Window::MakeGLContext(){
        PWindow::MakeGLContext();
    }
    void Window::GLSetThisWindow(){
        PWindow::GLSetThisWindow();
    }
    void Window::GLSwapBuffer(){
        PWindow::GLSwapBuffer();
    }
    bool Window::IsOpen(){
        return this->wSettings.IsOpen;
    }
    void Window::Close(){
        PWindow::Close();
    }
    void Window::Open(){
        PWindow::Open(PWindow::WindowType::GLWindow);
    }
    void Window::Open(WindowType windowType){
        PWindow::Open(windowType);
    }

    Math::IVector2 Window::GetWindowSize(){
        return this->wSettings.Size;
    }
    Window::WindowEvent Window::NextEvent(){
        WindowEvent event;
        event.WindowEventType = WindowEvent::WindowEventType_T::NONE;
        if(!this->EventList.IsEmpty()){
            event = this->EventList[0];
            this->EventList.Erase(0);
        }
        return event;
    }

}