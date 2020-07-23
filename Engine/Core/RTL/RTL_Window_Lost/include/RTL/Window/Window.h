//
// Created by kiper220 on 07.07.2020.
//

#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include <RTL/PWindow/PWindow.h>
#include <RTL/Thread.h>
#include <RTL/Mutex.h>
#include <ostream>

namespace RTL::RWindow {

    class Window : public PWindow {
    public:
        typedef PWindow::WindowEvent WindowEvent;

        Window();
        Window(WindowType windowType);

        void MakeGLContext();

        void GLSetThisWindow();
        void GLSwapBuffer();

        void Open();
        void Open(WindowType windowType);
        void Close();

        bool IsOpen();

        WindowEvent NextEvent();
        Math::IVector2 GetWindowSize();

    private:
    };
}
#endif //GAME_WINDOW_H
