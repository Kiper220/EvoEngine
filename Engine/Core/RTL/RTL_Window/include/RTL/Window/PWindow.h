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

    }
}

#endif //GAME_PWINDOW_H