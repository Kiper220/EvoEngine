//
// Created by kiper220 on 14.07.2020.
//

#include <cstdlib>
#if defined(linux)
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xatom.h>
#include <X11/extensions/Xrender.h>
#include <glad/glad.h>
#include <GL/glx.h>
typedef Window XWindow;
#endif
#include <RTL/Window/PWindow.h>

namespace RTL {
    namespace Window{

        #if defined(linux)
        static int VisDataGL[] = {
                GLX_RENDER_TYPE, GLX_RGBA_BIT,
                GLX_DRAWABLE_TYPE, GLX_WINDOW_BIT,
                GLX_DOUBLEBUFFER, True,
                GLX_RED_SIZE, 8,
                GLX_GREEN_SIZE, 8,
                GLX_BLUE_SIZE, 8,
                GLX_ALPHA_SIZE, 8,
                GLX_DEPTH_SIZE, 16,
                GLX_SAMPLE_BUFFERS  , 1,
                GLX_SAMPLES         , 16,
                None
        };
        struct GLLinux{
            int                 xScreen;
            Atom                del_atom;
            Colormap            colormap;
            Display*            display;

            XVisualInfo*        visualInfo;
            XRenderPictFormat*  pictFormat;
            GLXFBConfig*        fbconfigs,
                                fbconfig;

            int                 numfbconfigs;

            GLXContext          render_context;
            bool                GLContextIsMake = false;

            XWindow             xRoot,
                                window_handle;
            GLXWindow           glX_window_handle;
        };
        struct GLES2Linux{

        };
        struct GLES3Linux{

        };
        struct VKLinux{

        };
        static Bool WaitForMapNotify(Display *d, XEvent *e, char *arg)
        {
            return d && e && arg && (e->type == MapNotify) && (e->xmap.window == *(XWindow*)arg);
        }

        #elif defined(WIN32)
        struct GLWindows;
        struct GLES2Windows;
        struct GLES3Windows;
        struct VKWindows;
        struct DX12Windows;

        #elif defined (__APPLE__)
        struct MTLOSX;
        #else
        #error "This platform not supported"
        #endif



        PWindow::PWindow(){
            #if defined(WIN32)
            this->glWindows = new GLWindows;
            #elif defined(linux)
            this->glLinux = new GLLinux;
            #elif defined(__APPLE__)
            this->mtlOSX = new MTLOSX;
            #endif
        }
        PWindow::PWindow(Settings WindowSettings): wSettings(WindowSettings){
            switch (WindowSettings.ContextType) {
                case Settings::OpenGL: {
                    #if defined(WIN32)
                    this->glWindows = new GLWindows;
                    #elif defined(linux)
                    this->glLinux = new GLLinux;
                    #endif
                }
                case Settings::OpenGLES2: {
                    #if defined(WIN32)
                    this->gles2Windows = new GLES2Windows;
                    #elif defined(linux)
                    this->gles2Linux = new GLES2Linux;
                    #endif
                }
                case Settings::OpenGLES3: {
                    #if defined(WIN32)
                    this->gles3Windows = new GLES3Windows;
                    #elif defined(linux)
                    this->gles3Linux = new GLES3Linux;
                    #endif
                }
                case Settings::Vulkan: {
                    #if defined(WIN32)
                    this->vkWindows = new VKWindows;
                    #elif defined(linux)
                    this->vkLinux = new VKLinux;
                    #endif
                }
                #if defined(__APPLE__)
                case Settings::Metal: {
                    this->mtlOSX = new MTOSX;
                }
                #endif
                #if defined(WIN32)
                case Settings::DirectX12: {
                    this->dx12Windows= new DX12Windows;
                }
                #endif
            }
        }

        void PWindow::Create(){
            switch (this->wSettings.ContextType) {
                case Settings::OpenGL:
                #if defined(WIN32)
                {}
                #elif defined(linux)
                {
                    XEvent event;
                    int attr_mask;
                    XSizeHints hints;
                    XWMHints *startup_state;
                    XTextProperty textprop;
                    XSetWindowAttributes attr = {0};


                    this->glLinux->display = XOpenDisplay(nullptr);
                    if (!this->glLinux->display){
                        fprintf(stderr, "%s", "Couldn't connect to X server\n");
                        exit(0x666);
                    }
                    this->glLinux->xScreen = DefaultScreen(this->glLinux->display);


                    this->glLinux->xRoot = RootWindow(this->glLinux->display, this->glLinux->xScreen);

                    this->glLinux->fbconfigs = glXChooseFBConfig(this->glLinux->display, this->glLinux->xScreen, VisDataGL, &this->glLinux->numfbconfigs);
                    this->glLinux->fbconfig = 0;

                    for(int i = 0; i < this->glLinux->numfbconfigs; i++) {
                        this->glLinux->visualInfo = (XVisualInfo*) glXGetVisualFromFBConfig(this->glLinux->display, this->glLinux->fbconfigs[i]);
                        if(!this->glLinux->visualInfo)
                            continue;

                        this->glLinux->pictFormat = XRenderFindVisualFormat(this->glLinux->display, this->glLinux->visualInfo->visual);
                        if(!this->glLinux->pictFormat)
                            continue;

                        this->glLinux->fbconfig = this->glLinux->fbconfigs[i];
                        if(this->glLinux->pictFormat->direct.alphaMask > 0) {
                            break;
                        }
                    }

                    if(!this->glLinux->fbconfig) {
                        fprintf(stderr, "%s", "No matching FB config found");
                        exit(0x666);
                    }

                    {
                        int doublebuffer;
                        int red_bits, green_bits, blue_bits, alpha_bits, depth_bits;

                        glXGetFBConfigAttrib(this->glLinux->display, this->glLinux->fbconfig, GLX_DOUBLEBUFFER, &doublebuffer);
                        glXGetFBConfigAttrib(this->glLinux->display, this->glLinux->fbconfig, GLX_RED_SIZE, &red_bits);
                        glXGetFBConfigAttrib(this->glLinux->display, this->glLinux->fbconfig, GLX_GREEN_SIZE, &green_bits);
                        glXGetFBConfigAttrib(this->glLinux->display, this->glLinux->fbconfig, GLX_BLUE_SIZE, &blue_bits);
                        glXGetFBConfigAttrib(this->glLinux->display, this->glLinux->fbconfig, GLX_ALPHA_SIZE, &alpha_bits);
                        glXGetFBConfigAttrib(this->glLinux->display, this->glLinux->fbconfig, GLX_DEPTH_SIZE, &depth_bits);

                        fprintf(stderr, "FBConfig selected:\n"
                                        "Doublebuffer: %s\n"
                                        "Red Bits: %d, Green Bits: %d, Blue Bits: %d, Alpha Bits: %d, Depth Bits: %d\n",
                                doublebuffer == True ? "Yes" : "No",
                                red_bits, green_bits, blue_bits, alpha_bits, depth_bits);
                    }

                    this->glLinux->colormap = XCreateColormap(this->glLinux->display, this->glLinux->xRoot, this->glLinux->visualInfo->visual, AllocNone);

                    attr.colormap = this->glLinux->colormap;
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

                    this->wSettings.Size.x = DisplayWidth(this->glLinux->display, this->glLinux->xScreen)/2;
                    this->wSettings.Size.y = DisplayHeight(this->glLinux->display, this->glLinux->xScreen)/2;
                    this->wSettings.Position.x = this->wSettings.Size.x / 2,
                            this->wSettings.Position.y = this->wSettings.Size.x / 2;


                    this->glLinux->window_handle = XCreateWindow(this->glLinux->display,
                                                                 this->glLinux->xRoot,
                                                        this->wSettings.Position.x, this->wSettings.Position.y,
                                                        this->wSettings.Size.x, this->wSettings.Size.y,
                                                        0,
                                                        this->glLinux->visualInfo->depth,
                                                        InputOutput,
                                                        this->glLinux->visualInfo->visual,
                                                        attr_mask, &attr);
                    if( !this->glLinux->window_handle ) {
                        fprintf(stderr, "s", "Couldn't create the window\n");
                    }
                    this->glLinux->glX_window_handle = this->glLinux->window_handle;

                    textprop.value = (unsigned char*)(const char*)this->wSettings.Title;
                    textprop.encoding = XA_STRING;
                    textprop.format = 8;
                    textprop.nitems = this->wSettings.Title.Size();

                    hints.x = this->wSettings.Position.x;
                    hints.y = this->wSettings.Position.x;
                    hints.width = this->wSettings.Size.x;
                    hints.height = this->wSettings.Size.y;
                    hints.flags = USPosition|USSize;

                    startup_state = XAllocWMHints();
                    startup_state->initial_state = NormalState;
                    startup_state->flags = StateHint;

                    XSetWMProperties(this->glLinux->display, this->glLinux->window_handle,&textprop, &textprop,
                                     NULL, 0,
                                     &hints,
                                     startup_state,
                                     NULL);

                    XFree(startup_state);

                    XMapWindow(this->glLinux->display, this->glLinux->window_handle);
                    XIfEvent(this->glLinux->display, &event, WaitForMapNotify, (char*)&this->glLinux->window_handle);

                    if ((this->glLinux->del_atom = XInternAtom(this->glLinux->display, "WM_DELETE_WINDOW", 0)) != None) {
                        XSetWMProtocols(this->glLinux->display, this->glLinux->window_handle, &this->glLinux->del_atom, 1);
                    }
                    this->wSettings.IsOpen = true;

                    int dummy;
                    if (!glXQueryExtension(this->glLinux->display, &dummy, &dummy)) {
                        fprintf(stderr, "%s", "OpenGL not supported by X server\n");
                        exit(0x666);
                    }
                    fprintf(stderr, "Making Gl Context\n");

                    {
                        this->glLinux->render_context = glXCreateNewContext(this->glLinux->display, this->glLinux->fbconfig, GLX_RGBA_TYPE, 0, True);
                        glXMakeCurrent(this->glLinux->display, this->glLinux->glX_window_handle, this->glLinux->render_context);
                    }
                    this->glLinux->GLContextIsMake = true;
                }
                #elif defined(__APPLE__)
                {}
                #endif
            }
        }
        void PWindow::Close(){
            XLockDisplay(this->glLinux->display);

            glXDestroyContext(this->glLinux->display, this->glLinux->render_context);
            glXDestroyWindow(this->glLinux->display, this->glLinux->glX_window_handle);
            XDestroyWindow(this->glLinux->display, this->glLinux->window_handle);
            XFreeColormap(this->glLinux->display, this->glLinux->colormap);

            XUnlockDisplay(this->glLinux->display);

            XFlush(this->glLinux->display);
            XCloseDisplay(this->glLinux->display);
        }
        bool PWindow::pollEvent(Event &event) const{

        }
        const PWindow::Settings& PWindow::getWindowSettings() const{

        }
        bool PWindow::isFocused() const{

        }
        bool PWindow::isOpen() const{

        }
        void PWindow::SetRenderWindowThis(){
        #if defined(linux)
            switch (this->wSettings.ContextType) {
                case Settings::OpenGL:{
                    if (!glXMakeContextCurrent(
                            this->glLinux->display, this->glLinux->glX_window_handle,
                            this->glLinux->glX_window_handle, this->glLinux->render_context)) {
                        fprintf(stderr, "%s", "glXMakeCurrent failed for window\n");
                    }
                }
                case Settings::OpenGLES2:{

                }
                case Settings::OpenGLES3:{

                }
                case Settings::Vulkan:{

                }
                #if defined(WIN32)
                case Settings::DirectX12:{

                }
                #elif defined(__APPLE__)
                case Settings::Metal:{

                }
                #endif
            }
            #elif defined(WIN32)

            #elif defined(__APPLE__)

            #endif
        }
        void PWindow::SwapBuffer() {
            switch (this->wSettings.ContextType) {

                case Settings::OpenGL: {
                    glXSwapBuffers(this->glLinux->display, this->glLinux->glX_window_handle);
                }
                case Settings::OpenGLES2: {

                }
                case Settings::OpenGLES3: {

                }
                case Settings::Vulkan: {

                }
                #if defined(WIN32)
                    case Settings::DirectX12:{

                        }
                #elif defined(__APPLE__)
                    case Settings::Metal:{

                        }
                #endif
            }
        }
        void PWindow::setIcon(Math::IVector2 size, const Types::uint8* pixels){

        }
        void PWindow::setJoystickThreshold(float threshold){

        }
        void PWindow::setKeyRepeatEnabled(bool repeat){

        }
        void PWindow::setMouseCursor(const Utils::Cursor& cursor){

        }
        void PWindow::setMouseCursorGrabbed(bool cursorGrabbed){

        }
        void PWindow::setMouseCursorVisible(bool visible){

        }
        void PWindow::setPosition(Math::IVector2 position){

        }
        void PWindow::setSize(Math::IVector2 size){

        }
        void PWindow::setTitle(Types::String Title){

        }
        void PWindow::setVerticalSyncEnabled(bool enabled){

        }
        void PWindow::setVisible(bool visible){

        }
        bool PWindow::waitEvent(Event &event){

        }
        Math::IVector2 PWindow::getWindowSize(){

        }

        PWindow::~PWindow(){

        }
    }
}