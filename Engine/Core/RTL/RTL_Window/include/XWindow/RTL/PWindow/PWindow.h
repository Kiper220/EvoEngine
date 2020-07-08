//
// Created by kiper220 on 07.07.2020.
//

#ifndef GAME_PWINDOW_H
#define GAME_PWINDOW_H

#include <stdint.h>

#include <GL/gl.h>
#include <GL/glx.h>
#include <X11/Xatom.h>
#include <X11/extensions/Xrender.h>
#include <X11/Xutil.h>
#include <RTL/Vector.h>
#include <RTL_Math/include/RTL/Math/IVector2.h>
#include <RTL/Map.h>
#include <RTL/String.h>
#include <RTL/Types.h>

namespace RTL::RWindow {
    extern int STDWindowWidth;
    extern int STDWindowHeight;
    extern const char *STDWindowName;

    class PWindow{
    public:
        typedef struct {
            Math::IVector2  Size             =  {STDWindowWidth, STDWindowHeight};
            Math::IVector2  Position         =  {0,0};
            Types::int32    MonitorIndex     =  -1;
            Types::String   windowName       = "Test Window";

            bool            FullScreen       =  false;
            bool            IsOpen           =  false;
            bool            DragToResize     =  true;
            bool            BorderLessWindow =  false;
            bool            Quit             =  false;
            bool            CloseWindowEvent =  true;
        }Settings;

        PWindow();
        PWindow(Settings windowSettings);


    private:
        Settings            wSettings;

        int                 xScreen;
        Atom                del_atom;
        Colormap            colormap;
        Display             *display;

        XVisualInfo         *visualInfo;
        XRenderPictFormat   *pictFormat;
        GLXFBConfig         *fbconfigs,
                            fbconfig;

        int                 numfbconfigs;

        static GLXContext   render_context;
        static bool         GLContextIsMake;

        Window              xRoot, window_handle;
        GLXWindow           glX_window_handle;
    };
}

#endif //GAME_PWINDOW_H
