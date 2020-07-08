//
// Created by kiper220 on 07.07.2020.
//

#include <XWindow/RTL/PWindow/PWindow.h>
#include <cstdlib>

static int VisData[] = {
        GLX_RENDER_TYPE, GLX_RGBA_BIT,
        GLX_DRAWABLE_TYPE, GLX_WINDOW_BIT,
        GLX_DOUBLEBUFFER, True,
        GLX_RED_SIZE, 8,
        GLX_GREEN_SIZE, 8,
        GLX_BLUE_SIZE, 8,
        GLX_ALPHA_SIZE, 8,
        GLX_DEPTH_SIZE, 16,
        None
};

namespace RTL::RWindow{
    static Bool WaitForMapNotify(Display *d, XEvent *e, char *arg)
    {
        return d && e && arg && (e->type == MapNotify) && (e->xmap.window == *(Window*)arg);
    }
    static void fatalError(const char *why)
    {
        fprintf(stderr, "%s", why);
        exit(0x666);
    }
    PWindow::PWindow(){
        XEvent event;
        int attr_mask;
        XSizeHints hints;
        XWMHints *startup_state;
        XTextProperty textprop;
        XSetWindowAttributes attr = {0};

        this->display = XOpenDisplay(NULL);
        if (!this->display) {
            fatalError("Couldn't connect to X server\n");
        }
        this->xScreen = DefaultScreen(this->display);
        this->xRoot = RootWindow(this->display, this->xScreen);

        this->fbconfigs = glXChooseFBConfig(this->display, this->xScreen, VisData, &this->numfbconfigs);
        this->fbconfig = 0;

        for(int i = 0; i<numfbconfigs; i++) {
            this->visualInfo = (XVisualInfo*) glXGetVisualFromFBConfig(this->display, fbconfigs[i]);
            if(!this->visualInfo)
                continue;

            this->pictFormat = XRenderFindVisualFormat(this->display, this->visualInfo->visual);
            if(!this->pictFormat)
                continue;

            fbconfig = fbconfigs[i];
            if(this->pictFormat->direct.alphaMask > 0) {
                break;
            }
        }

        if(!fbconfig) {
            fatalError("No matching FB config found");
        }

        {
            int doublebuffer;
            int red_bits, green_bits, blue_bits, alpha_bits, depth_bits;

            glXGetFBConfigAttrib(this->display, this->fbconfig, GLX_DOUBLEBUFFER, &doublebuffer);
            glXGetFBConfigAttrib(this->display, this->fbconfig, GLX_RED_SIZE, &red_bits);
            glXGetFBConfigAttrib(this->display, this->fbconfig, GLX_GREEN_SIZE, &green_bits);
            glXGetFBConfigAttrib(this->display, this->fbconfig, GLX_BLUE_SIZE, &blue_bits);
            glXGetFBConfigAttrib(this->display, this->fbconfig, GLX_ALPHA_SIZE, &alpha_bits);
            glXGetFBConfigAttrib(this->display, this->fbconfig, GLX_DEPTH_SIZE, &depth_bits);

            fprintf(stderr, "FBConfig selected:\n"
                            "Doublebuffer: %s\n"
                            "Red Bits: %d, Green Bits: %d, Blue Bits: %d, Alpha Bits: %d, Depth Bits: %d\n",
                    doublebuffer == True ? "Yes" : "No",
                    red_bits, green_bits, blue_bits, alpha_bits, depth_bits);
        }

        this->colormap = XCreateColormap(this->display, this->xRoot, this->visualInfo->visual, AllocNone);

        attr.colormap = this->colormap;
        attr.background_pixmap = None;
        attr.border_pixmap = None;
        attr.border_pixel = 0;
        attr.event_mask =
                StructureNotifyMask |
                EnterWindowMask |
                LeaveWindowMask |
                ExposureMask |
                ButtonPressMask |
                ButtonReleaseMask |
                OwnerGrabButtonMask |
                KeyPressMask |
                KeyReleaseMask;

        attr_mask =
                //	CWBackPixmap|
                CWColormap|
                CWBorderPixel|
                CWEventMask;

        this->wSettings.Size.x = DisplayWidth(this->display, this->xScreen)/2;
        this->wSettings.Size.y = DisplayHeight(this->display, this->xScreen)/2;
        this->wSettings.Position.x = this->wSettings.Size.x / 2,
        this->wSettings.Position.y = this->wSettings.Size.x / 2;


        this->window_handle = XCreateWindow(this->display,
                                              this->xRoot,
                                              this->wSettings.Position.x, this->wSettings.Position.y,
                                              this->wSettings.Size.x, this->wSettings.Size.y,
                                              0,
                                              this->visualInfo->depth,
                                              InputOutput,
                                              this->visualInfo->visual,
                                              attr_mask, &attr);
        if( !window_handle ) {
            fatalError("Couldn't create the window\n");
        }
        glX_window_handle = window_handle;

        textprop.value = (unsigned char*)(const char*)this->wSettings.windowName;
        textprop.encoding = XA_STRING;
        textprop.format = 8;
        textprop.nitems = this->wSettings.windowName.Size();

        hints.x = this->wSettings.Position.x;
        hints.y = this->wSettings.Position.x;
        hints.width = this->wSettings.Size.x;
        hints.height = this->wSettings.Size.y;
        hints.flags = USPosition|USSize;

        startup_state = XAllocWMHints();
        startup_state->initial_state = NormalState;
        startup_state->flags = StateHint;

        XSetWMProperties(this->display, this->window_handle,&textprop, &textprop,
                         NULL, 0,
                         &hints,
                         startup_state,
                         NULL);

        XFree(startup_state);

        XMapWindow(this->display, window_handle);
        XIfEvent(this->display, &event, WaitForMapNotify, (char*)&this->window_handle);

        if ((del_atom = XInternAtom(this->display, "WM_DELETE_WINDOW", 0)) != None) {
            XSetWMProtocols(this->display, window_handle, &del_atom, 1);
        }
    }
    PWindow::PWindow(Settings settings): wSettings(settings){
        XEvent event;
        int attr_mask;
        XSizeHints hints;
        XWMHints *startup_state;
        XTextProperty textprop;
        XSetWindowAttributes attr = {0};

        this->display = XOpenDisplay(NULL);
        if (!this->display) {
            fatalError("Couldn't connect to X server\n");
        }
        this->xScreen = DefaultScreen(this->display);
        this->xRoot = RootWindow(this->display, this->xScreen);

        this->fbconfigs = glXChooseFBConfig(this->display, this->xScreen, VisData, &this->numfbconfigs);
        this->fbconfig = 0;

        for(int i = 0; i<numfbconfigs; i++) {
            this->visualInfo = (XVisualInfo*) glXGetVisualFromFBConfig(this->display, fbconfigs[i]);
            if(!this->visualInfo)
                continue;

            this->pictFormat = XRenderFindVisualFormat(this->display, this->visualInfo->visual);
            if(!this->pictFormat)
                continue;

            fbconfig = fbconfigs[i];
            if(this->pictFormat->direct.alphaMask > 0) {
                break;
            }
        }

        if(!fbconfig) {
            fatalError("No matching FB config found");
        }

        {
            int doublebuffer;
            int red_bits, green_bits, blue_bits, alpha_bits, depth_bits;

            glXGetFBConfigAttrib(this->display, this->fbconfig, GLX_DOUBLEBUFFER, &doublebuffer);
            glXGetFBConfigAttrib(this->display, this->fbconfig, GLX_RED_SIZE, &red_bits);
            glXGetFBConfigAttrib(this->display, this->fbconfig, GLX_GREEN_SIZE, &green_bits);
            glXGetFBConfigAttrib(this->display, this->fbconfig, GLX_BLUE_SIZE, &blue_bits);
            glXGetFBConfigAttrib(this->display, this->fbconfig, GLX_ALPHA_SIZE, &alpha_bits);
            glXGetFBConfigAttrib(this->display, this->fbconfig, GLX_DEPTH_SIZE, &depth_bits);

            fprintf(stderr, "FBConfig selected:\n"
                            "Doublebuffer: %s\n"
                            "Red Bits: %d, Green Bits: %d, Blue Bits: %d, Alpha Bits: %d, Depth Bits: %d\n",
                    doublebuffer == True ? "Yes" : "No",
                    red_bits, green_bits, blue_bits, alpha_bits, depth_bits);
        }

        this->colormap = XCreateColormap(this->display, this->xRoot, this->visualInfo->visual, AllocNone);

        attr.colormap = this->colormap;
        attr.background_pixmap = None;
        attr.border_pixmap = None;
        attr.border_pixel = 0;
        attr.event_mask =
                StructureNotifyMask |
                EnterWindowMask |
                LeaveWindowMask |
                ExposureMask |
                ButtonPressMask |
                ButtonReleaseMask |
                OwnerGrabButtonMask |
                KeyPressMask |
                KeyReleaseMask;

        attr_mask =
                //	CWBackPixmap|
                CWColormap|
                CWBorderPixel|
                CWEventMask;

        this->wSettings.Size.x = DisplayWidth(this->display, this->xScreen)/2;
        this->wSettings.Size.y = DisplayHeight(this->display, this->xScreen)/2;
        this->wSettings.Position.x = this->wSettings.Size.x / 2,
        this->wSettings.Position.y = this->wSettings.Size.y / 2;


        this->window_handle = XCreateWindow(this->display,
                                            this->xRoot,
                                            this->wSettings.Position.x, this->wSettings.Position.y,
                                            this->wSettings.Size.x, this->wSettings.Size.y,
                                            0,
                                            this->visualInfo->depth,
                                            InputOutput,
                                            this->visualInfo->visual,
                                            attr_mask, &attr);
        if( !window_handle ) {
            fatalError("Couldn't create the window\n");
        }
        glX_window_handle = window_handle;

        textprop.value = (unsigned char*)(const char*)this->wSettings.windowName;
        textprop.encoding = XA_STRING;
        textprop.format = 8;
        textprop.nitems = this->wSettings.windowName.Size();

        hints.x = this->wSettings.Position.x;
        hints.y = this->wSettings.Position.x;
        hints.width = this->wSettings.Size.x;
        hints.height = this->wSettings.Size.y;
        hints.flags = USPosition|USSize;

        startup_state = XAllocWMHints();
        startup_state->initial_state = NormalState;
        startup_state->flags = StateHint;

        XSetWMProperties(this->display, this->window_handle,&textprop, &textprop,
                         NULL, 0,
                         &hints,
                         startup_state,
                         NULL);

        XFree(startup_state);

        XMapWindow(this->display, window_handle);
        XIfEvent(this->display, &event, WaitForMapNotify, (char*)&this->window_handle);

        if ((del_atom = XInternAtom(this->display, "WM_DELETE_WINDOW", 0)) != None) {
            XSetWMProtocols(this->display, window_handle, &del_atom, 1);
        }
    }
}