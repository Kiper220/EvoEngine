//
// Created by kiper220 on 19.05.2020.
//

#include "Engine/RVM/Include/RunTimeApplication.h"


namespace EvoEngine{
    namespace RVM{

        stdRegister::stdRegister(): RRX(0){}
        void stdRegister::operator=(unsigned long int v){
            this->RRX = v;
        }
        void stdRegister::operator=(unsigned int v){
            this->ERX = v;
        }
        void stdRegister::operator=(unsigned short int v){
            this->RX = v;
        }
        void stdRegister::operator=(unsigned char v){
            this->RL = v;
        }
        stdRegister::~stdRegister(){
            this->RRX = 0;
        }

        minRegister::minRegister(): RRX(0){}
        void minRegister::operator=(unsigned long int v){
            this->RRX = v;
        }
        void minRegister::operator=(unsigned int v){
            this->ERX = v;
        }
        void minRegister::operator=(unsigned short int v){
            this->RX = v;
        }
        void minRegister::operator=(unsigned char v){
            this->RXL = v;
        }
        minRegister::~minRegister(){
            this->RRX = 0;
        }

        RunTimeRVMThread::RunTimeRVMThread()
        {

        }
        RunTimeRVMApplication::RunTimeRVMApplication(){

        }

        void RunTimeRVMApplication::LoadBin(const char* bin){

        }
        void RunTimeRVMApplication::RunSym(const char* LabelSym, RegisteredMemory& MemoryShoot){

        }


        RunTimeRVMApplication::~RunTimeRVMApplication(){

        }

    }
}