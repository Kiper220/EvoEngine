//
// Created by kiper220 on 13.11.2020.
//

#ifndef GAME_EXCEPTION_H
#define GAME_EXCEPTION_H

#include "RTL/String.h"

// TODO: Check and refactor instance of exception data. Add comments

namespace RTL{
    namespace Types{
        class Exception{
            enum Level{
                info,
                warning,
                error,
                critical_error,
            };

            virtual String what();
            virtual int code();
            virtual Level levelOfCritical();
        };
    }
}

#endif //GAME_EXCEPTION_H
