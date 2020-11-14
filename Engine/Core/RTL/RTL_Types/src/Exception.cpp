//
// Created by kiper220 on 13.11.2020.
//

#include "RTL/Exception.h"

namespace RTL{
    namespace Types{

        String Exception::what(){
            return "empty Exception!";
        }
        int Exception::code(){
            return 0;
        }
        Exception::Level Exception::levelOfCritical(){
            return Exception::info;
        }
    }
}