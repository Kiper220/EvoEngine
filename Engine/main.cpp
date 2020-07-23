#include <iostream>
#include <RTL/Window/Window.h>
#include <glad/glad.h>
#include <unistd.h>
#include <cmath>

int main(){
    RTL::Window::PWindow::Settings stngs;
    stngs.Title = "Test Window";
    RTL::Window::PWindow pWindow;
    pWindow.Create();

    RTL::Window::PWindow pWindow1;
    pWindow1.Create();

    pWindow.SetRenderWindowThis();
    gladLoadGL();
    glDrawBuffer(GL_BACK);
    glClearColor(1,1,1,1);
    pWindow1.SetRenderWindowThis();
    glDrawBuffer(GL_BACK);
    glClearColor(1,1,1,1);

    while (true) {
        pWindow.SetRenderWindowThis();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        pWindow.SwapBuffer();

        pWindow1.SetRenderWindowThis();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        pWindow1.SwapBuffer();
    }
}