//
// Created by kiper220 on 14.07.2020.
//

#ifndef GAME_PWINDOW_H
#define GAME_PWINDOW_H

#include <RTL/Math/IVector2.h>
#include <RTL/String.h>
#include <RTL/Types.h>
#include <RTL/Pair.h>
#include <RTL/Window/Utils/Cursor.h>


namespace Keyboard{
    enum Key{
        Unknown,
        A,
        B,
        C,
        D,
        E,
        F,
        G,
        H,
        I,
        K,
        L,
        M,
        N,
        O,
        P,
        Q,
        R,
        S,
        T,
        V,
        X,
        Y,
        Z,
        Num0,
        Num1,
        Num2,
        Num3,
        Num4,
        Num5,
        Num6,
        Num7,
        Num8,
        Num9,
        Escape,
        LControl,
        LShift,
        LAlt,
        LSystem,
        RControl,
        RShift,
        RAlt,
        RSystem,
        Menu,
        LBracket,
        RBracket,
        SemiColon,
        Comma,
        Period,
        Quote,
        Slash,
        BackSlash,
        Tilde,
        Equal,
        Dash,
        Space,
        Return,
        BackSpace,
        Tab,
        PageUp,
        PageDown,
        End,
        Home,
        Insert,
        Delete,
        Add,
        Subtract,
        Multiply,
        Divide,
        Left,
        Right,
        Up,
        Down,
        Numpad0,
        Numpad1,
        Numpad2,
        Numpad3,
        Numpad4,
        Numpad5,
        Numpad6,
        Numpad7,
        Numpad8,
        Numpad9,
        F1,
        F2,
        F3,
        F4,
        F5,
        F6,
        F7,
        F8,
        F9,
        F10,
        F11,
        F12,
        F14,
        F15,
        Pause,
        KeyCount
    };
}
namespace Mouse {
    enum Button {
        LeftButton,
        RightButton,
        MiddleButton,
        XButton1,
        XButton2,
        ButtonCount,
    };
}
namespace Mouse {
    enum Wheel {
        VerticalWheel,
        HorizontalWheel
    };
}
namespace Joystick {
    enum Axis {
        X,
        Y,
        Z,
        R,
        U,
        V,
        PovX,
        PovY,
    };
}
namespace Sensor{
    enum Type{
        Accelerometer,
        Gyroscope,
        Magnetometer,
        Gravity,
        UserAcceleration,
        Orientation,
        Count,
    };
}

namespace RTL {
    namespace Window {
        struct GLLinux;
        struct GLWindows;

        struct GLES2Linux;
        struct GLES2Windows;
        struct GLES3Linux;
        struct GLES3Windows;

        struct VKLinux;
        struct VKWindows;

        struct DX12Windows;
        struct MTLOSX;

        class PWindow{
        public:
            struct Settings{
                Math::IVector2 Size;
                Math::IVector2 Position;
                Types::String Title;
                bool IsOpen = false;
                bool IsFullscreen = false;
                bool IsMinimized = false;
                bool IsMaximized = false;
                bool IsContexted = false;
                Types::Pair<Math::IVector2, Types::uint8*> Icon;
                float JoystickThreshold = 0.1f;
                Utils::Cursor cursor = Utils::Cursor::Arrow;
                bool keyRepeat = true;
                bool cursorGrabbed = false;
                bool mouseCursorVisible = true;
                bool verticalSyncEnabled = true;
                enum ApiType{
                    OpenGL,
                    OpenGLES2,
                    OpenGLES3,
                    Vulkan,
#if defined(__APPLE__)
                    Metal,
#endif
#if defined(WIN32)
                    DirectX12,
#endif
                } ContextType = OpenGL;
            };

            struct SizeEvent
            {
                unsigned int width;
                unsigned int height;
            };

            struct KeyEvent
            {
                Keyboard::Key code;
                bool          alt;
                bool          control;
                bool          shift;
                bool          system;
            };

            struct TextEvent
            {
                Types::uint32 unicode;
            };

            struct MouseMoveEvent
            {
                int x;
                int y;
            };

            struct MouseButtonEvent
            {
                Mouse::Button button;
                int           x;
                int           y;
            };

            struct MouseWheelEvent
            {
                int delta;
                int x;
                int y;
            };

            struct MouseWheelScrollEvent
            {
                Mouse::Wheel wheel;
                float        delta;
                int          x;
                int          y;
            };

            struct JoystickConnectEvent
            {
                unsigned int joystickId;
            };

            struct JoystickMoveEvent
            {
                unsigned int   joystickId;
                Joystick::Axis axis;
                float          position;
            };

            struct JoystickButtonEvent
            {
                unsigned int joystickId;
                unsigned int button;
            };

            struct TouchEvent
            {
                unsigned int finger;
                int x;
                int y;
            };

            struct SensorEvent
            {
                Sensor::Type type;
                float x;
                float y;
                float z;
            };

            struct Event{
                enum{
                    Closed,
                    Resized,
                    LostFocus,
                    GainedFocus,
                    TextEntered,
                    KeyPressed,
                    KeyReleased,
                    MouseWheelMoved,
                    MouseWheelScrolled,
                    MouseButtonPressed,
                    MouseButtonReleased,
                    MouseMoved,
                    MouseEntered,
                    MouseLeft,
                    JoystickButtonPressed,
                    JoystickButtonReleased,
                    JoystickMoved,
                    JoystickConnected,
                    JoystickDisconnected,
                    TouchBegan,
                    TouchMoved,
                    TouchEnded,
                    SensorChanged,

                    Count

                } EventType;

                union{
                    SizeEvent               size;
                    KeyEvent                key;
                    TextEvent               text;
                    MouseMoveEvent          mouseMove;
                    MouseButtonEvent        mouseButton;
                    MouseWheelEvent         mouseWheel;
                    MouseWheelScrollEvent   mouseWheelScroll;
                    JoystickMoveEvent       joystickMove;
                    JoystickButtonEvent     joystickButton;
                    JoystickConnectEvent    joystickConnect;
                    TouchEvent              touch;
                    SensorEvent             sensor;
                }EventData;
            };

            PWindow();
            PWindow(Settings WindowSettings);

            void Create();
            void Close();
            bool pollEvent(Event &event) const;
            const Settings& getWindowSettings() const;
            bool isFocused() const;
            bool isOpen() const;
            bool waitEvent(Event &event);
            Math::IVector2 getWindowSize();

            void SetRenderWindowThis();
            void SwapBuffer();
            void setIcon(Math::IVector2 size, const Types::uint8* pixels);
            void setJoystickThreshold(float threshold = 0.1f);
            void setKeyRepeatEnabled(bool repeat = true);
            void setMouseCursor(const Utils::Cursor& cursor);
            void setMouseCursorGrabbed(bool cursorGrabbed = false);
            void setMouseCursorVisible(bool visible = true);
            void setPosition(Math::IVector2 position);
            void setSize(Math::IVector2 size);
            void setTitle(Types::String Title);
            void setVerticalSyncEnabled(bool enabled = true);
            void setVisible(bool visible = true);

            ~PWindow();

        private:
            Settings wSettings;
            union {
                GLLinux* glLinux;
                GLWindows* glWindows;

                GLES2Linux* gles2Linux;
                GLES2Windows* gles2Windows;

                GLES3Linux* gles3Linux;
                GLES3Windows* gles3Windows;

                VKLinux* vkLinux;
                VKWindows* vkWindows;

                DX12Windows* dx12Windows;
                MTLOSX* mtlOSX;
            };
        };
    }
}

#endif //GAME_PWINDOW_H