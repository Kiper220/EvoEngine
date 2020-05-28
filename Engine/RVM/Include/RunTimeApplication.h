//
// Created by kiper220 on 19.05.2020.
//

#ifndef EVOENGINE_RUNTIMEAPPLICATION_H
#define EVOENGINE_RUNTIMEAPPLICATION_H
#include "RVM.h"
#include <vector>
#include <string>
#include <map>

namespace EvoEngine{
    namespace RVM{
        union stdRegister{
            stdRegister();
            void operator=(unsigned long int v);
            void operator=(unsigned int v);
            void operator=(unsigned short int v);
            void operator=(unsigned char v);
            ~stdRegister();

            unsigned long int RRX;
            unsigned int ERX;
            unsigned short int RX;
            struct {
                const char NONE[6];
                unsigned char RH;
                unsigned char RL;
            };
        };
        union minRegister{
            minRegister();
            void operator=(unsigned long int v);
            void operator=(unsigned int v);
            void operator=(unsigned short int v);
            void operator=(unsigned char v);
            ~minRegister();

            unsigned long int RRX;
            unsigned int ERX;
            unsigned short int RX;
            struct {
                const char NONE[7];
                unsigned char RXL;
            };
        };

        class RegisteredMemory{
        public:
            RegisteredMemory();

            ~RegisteredMemory();
            stdRegister         RAX;
            stdRegister         RBX;
            stdRegister         RCX;
            stdRegister         RDX;
            minRegister         RBP;
            minRegister         RSI;
            minRegister         RDI;
            minRegister         RSP;
            minRegister         RV[51];
            std::vector<char>   stack;
        };
        union InstructionData{
            InstructionData();
            Instruction         instruction;
            unsigned char       BB1;
            unsigned short int  BB2;
            unsigned int        BB4;
            unsigned long int   BB8;
        };

        class RunTimeRVMThread{
        public:
            RunTimeRVMThread();

            stdRegister         RAX;
            stdRegister         RBX;
            stdRegister         RCX;
            stdRegister         RDX;
            minRegister         RBP;
            minRegister         RSI;
            minRegister         RDI;
            minRegister         RSP;
            minRegister         RV[51];
        };
        class RunTimeRVMApplication {
        public:
            RunTimeRVMApplication();

            void LoadBin(const char* bin);
            void RunSym(const char* LabelSym, RegisteredMemory& MemoryShoot);

            ~RunTimeRVMApplication();

            std::vector<RunTimeRVMThread> Threads;
            std::map<std::string, std::vector<InstructionData>> Code;
            std::vector<char> data;
            const char* bin;
        };
    }
}

#endif //EVOENGINE_RUNTIMEAPPLICATION_H
