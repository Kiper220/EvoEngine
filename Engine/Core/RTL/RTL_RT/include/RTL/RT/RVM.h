//
// Created by kiper220 on 08.07.2020.
//

#ifndef GAME_RVM_H
#define GAME_RVM_H
#include <RTL/Types.h>
#include <RTL/Pair.h>
#include <RTL/Vector.h>
#include <RTL/String.h>

namespace RTL::RT{
    enum Operator : Types::uint64{
        R0, R1, R2, R3, R4, R5, R6,
        R7, R8, R9, R10,R11,R12,R13,
        R14,R15,R16,R17,R18,R19,R20,
        R21,R22,R23,R24,R25,R26,R27,
        R28,R29,R30,R31,R32,R33,R34,
        R35,R36,R37,R38,R39,R40,R41,
        R42,R43,R44,R45,R46,R47,R48,
        R49,R50,

        STACK,
        RResult,
        RJMPName,

        REnd,

        pushR,
        popR,

        call,
        je,
        jne,

        jl,
        jle,
        jg,
        jge,

        jnl,
        jnle,
        jng,
        jnge,


        movRR,
        movRS,movSR,movSS,
        movRD,movSD,movND,movPD,
        movRN,movNR,movNN,
        movRP,movPR,movNP,movPN,movPP,
        movSN,movNS,

        addRR,
        addRS,addSR,addSS,
        addRD,addSD,addND,addPD,
        addRN,addNR,addNN,
        addRP,addPR,addNP,addPN,addPP,
        addSN,addNS,

        subRR,
        subRS,subSR,subSS,
        subRD,subSD,subND,subPD,
        subRN,subNR,subNN,
        subRP,subPR,subNP,subPN,subPP,
        subSN,subNS,

        mulRR,
        mulRS,mulSR,mulSS,
        mulRD,mulSD,mulND,mulPD,
        mulRN,mulNR,mulNN,
        mulRP,mulPR,mulNP,mulPN,mulPP,
        mulSN,mulNS,

        divRR,
        divRS,divSR,divSS,
        divRD,divSD,divND,divPD,
        divRN,divNR,divNN,
        divRP,divPR,divNP,divPN,divPP,
        divSN,divNS,

        remRR,
        remRS,remSR,remSS,
        remRD,remSD,
        remRN,remNR,remNN,
        remRP,remPR,remNP,remPN,remPP,
        remSN,remNS,

        newR,newS,newD,newN,newP,
        deleteR,deleteS,deleteN,deleteP,
        returnR,returnS,returnN,returnP,returnD,

        b8,b16,b32,b64,
        ptr,
    };
    class RVM{
    public:
        union RegisterType{
            Types::uint64   ui64;
            Types::int64    i64;

            Types::uint32   ui32;
            Types::int32    i32;

            Types::uint16   ui16;
            Types::int16    i16;

            Types::uint8    ui8;
            Types::int8     i8;

            char*           str;
            void*           ptr;
        };
        enum RegisterTypeEnum : Types::uint8 {
            ui64,
            i64,

            ui32,
            i32,

            ui16,
            i16,

            ui8,
            i8,

            str,
            ptr,
        };
        RVM(Types::Vector<Operator> operators){
            this->stack.SetSize(1024*1024*3);
            this->Lesser = false;
            this->Below = false;
            this->Equel = true;
            enum{
                NONE,
                MOV,
            } RVMSwitch;

            for(auto op : operators){
                switch(RVMSwitch){
                    default:
                        if(op > REnd){
                            if(op < movRR){
                                switch(op){
                                    case pushR:{

                                    }
                                    case popR:{

                                    }
                                    case call:{

                                    }
                                    case je:{

                                    }
                                    case jne:{

                                    }
                                    case jl:{

                                    }
                                    case jle:{

                                    }
                                    case jg:{

                                    }
                                    case jge:{

                                    }
                                    case jnl:{

                                    }
                                    case jnle:{

                                    }
                                    case jng:{

                                    }
                                    case jnge:{

                                    }
                                }
                            }
                            else if(op <= movNS){ //17
                                Types::uint64 g = op;
                                g -= Operator::movRR;
                                switch(g){
                                    case 0:{

                                    }
                                    case 1: {

                                    }
                                    case 2: {

                                    }
                                    case 3: {

                                    }
                                    case 4: {

                                    }
                                    case 5: {

                                    }
                                    case 6: {

                                    }
                                    case 7: {

                                    }
                                    case 8: {

                                    }
                                    case 9: {

                                    }
                                    case 10: {

                                    }
                                    case 11: {

                                    }
                                    case 12: {

                                    }
                                    case 13: {

                                    }
                                    case 14: {

                                    }
                                    case 15: {

                                    }
                                    case 16: {

                                    }
                                    case 17: {

                                    }
                                }
                            }
                            else if(op <= addNS){

                            }
                            else if(op <= subNS){

                            }
                            else if(op <= divNS){

                            }
                            else if(op <= remNS){

                            }
                            else if(op <= newP){

                            }
                            else if(op <= deleteP){

                            }
                            else if(op <= returnD){

                            }
                            else{
                                std::cout << "Error, confused operator!";
                                this->stack.Clear();
                                return;
                            }
                        }
                        else{
                            std::cout << "Error, confused operator!";
                            this->stack.Clear();
                            return;
                        }
                        break;
                }
            }

            this->stack.Clear();
        }
    private:
        Types::Pair<RegisterType, RegisterTypeEnum> R[51];
        Types::Pair<RegisterType, RegisterTypeEnum> Result;
        Types::String JMPName;

        bool Lesser : 1;
        bool Below : 1;
        bool Equel : 1;

        Types::Vector<char> stack;
    };
}

#endif //GAME_RVM_H
