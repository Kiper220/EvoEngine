//
// Created by kiper220 on 15.07.2020.
//

#ifndef GAME_CURSOR_H
#define GAME_CURSOR_H

#include <RTL/Types.h>
#include <RTL/Math/IVector2.h>

namespace RTL {
    namespace Window {
        namespace Utils{
            class Cursor{
            public:
                enum Type{
                    Arrow, ArrowWait, Wait,
                    Text, Hand, SizeHorizontal,
                    SizeVertical, SizeTopLeftBottomRight,
                    SizeBottomLeftTopRight, SizeAll, Cross,
                    Help, NotAllowed,
                };
                Cursor();
                Cursor(Type type);
                Cursor(const Types::uint8 pixels, Math::IVector2 size);
                bool loadFromPixels(const Types::uint8 pixels, Math::IVector2 size);
                bool loadFromSystem(Type type);
                ~Cursor();
            };
        }
    }
}

#endif //GAME_CURSOR_H
