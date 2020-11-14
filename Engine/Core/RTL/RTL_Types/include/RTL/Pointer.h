//
// Created by kiper220 on 19.08.2020.
//

#ifndef GAME_POINTER_H
#define GAME_POINTER_H
#include <RTL/Mutex.h>

// TODO: Check, refactor and adding exception processing. Add comments

namespace RTL{
    namespace Types{
        template <typename t>
        class Pointer{
        public:

            Pointer() {}
            Pointer(t* pointer) {
                this->usage = new size_t(1);
                ptr = pointer;
            }
            Pointer(const Pointer& pointer1) {
                if(pointer1.ptr == nullptr) return;
                this->usage = pointer1.usage;
                (*this->usage)++;
                this->ptr = pointer1.ptr;
            }
            Pointer(Pointer&& pointer1) {
                if(pointer1.ptr == nullptr) return;
                this->usage = pointer1.usage;
                pointer1.usage = nullptr;

                (*this->usage)++;
                this->ptr = pointer1.ptr;
                pointer1.ptr = nullptr;
            }

            Pointer& operator=(t* pointer1) {
                if(this->ptr != nullptr)
                    if(--(*this->usage) == 0){
                        delete this->usage;
                        delete this->ptr;
                    }

                this->usage = new size_t(1);
                this->ptr = pointer1;
            }
            Pointer& operator=(const Pointer& pointer1) {
                if(this->ptr != nullptr)
                    if(--(*this->usage) == 0){
                        delete this->usage;
                        delete this->ptr;
                        this->ptr = nullptr;
                        this->usage = nullptr;
                    }
                if(pointer1.ptr == nullptr) return *this;

                this->usage = pointer1.usage;
                (*this->usage)++;
                this->ptr = pointer1.ptr;
            }
            Pointer& operator=(Pointer&& pointer1) {
                if(this->ptr != nullptr)
                    if(--(*this->usage) == 0){
                        delete this->usage;
                        delete this->ptr;
                        this->ptr = nullptr;
                        this->usage = nullptr;
                    }
                if(pointer1.ptr == nullptr) return *this;

                this->usage = pointer1.usage;
                pointer1.usage = nullptr;

                (*this->usage)++;
                this->ptr = pointer1.ptr;
                pointer1.ptr = nullptr;
            }
            t& operator[](size_t element){
                return this->ptr[element];
            }

            bool isEmpty(){
                return this->ptr == nullptr;
            }

            t& operator*(){
                return *this->ptr;
            }

            operator t*(){
                return this->ptr;
            }

            ~Pointer(){
                if(this->ptr != nullptr)
                    if(--(*this->usage) == 0){
                        delete this->usage;
                        delete this->ptr;
                    }
                this->ptr = nullptr;
                this->usage = nullptr;
            }

        private:
            size_t* usage = nullptr;
            t* ptr = nullptr;
        };
        template <typename t>
        class PointerA{
        public:

            PointerA() {}
            PointerA(t* pointer) {
                this->usage = new size_t(1);
                ptr = pointer;
            }
            PointerA(const PointerA& pointer1) {
                if(pointer1.ptr == nullptr) return;
                this->usage = pointer1.usage;
                (*this->usage)++;
                this->ptr = pointer1.ptr;
            }
            PointerA(PointerA&& pointer1) {
                if(pointer1.ptr == nullptr) return;
                this->usage = pointer1.usage;
                pointer1.usage = nullptr;

                (*this->usage)++;
                this->ptr = pointer1.ptr;
                pointer1.ptr = nullptr;
            }

            PointerA& operator=(t* pointer1) {
                if(this->ptr != nullptr)
                    if(--(*this->usage) == 0){
                        delete this->usage;
                        delete [] this->ptr;
                    }

                this->usage = new size_t(1);
                this->ptr = pointer1;
            }
            PointerA& operator=(const PointerA& pointer1) {
                if(this->ptr != nullptr)
                    if(--(*this->usage) == 0){
                        delete this->usage;
                        delete [] this->ptr;
                        this->ptr = nullptr;
                        this->usage = nullptr;
                    }
                if(pointer1.ptr == nullptr) return *this;

                this->usage = pointer1.usage;
                (*this->usage)++;
                this->ptr = pointer1.ptr;
            }
            PointerA& operator=(PointerA&& pointer1) {
                if(this->ptr != nullptr)
                    if(--(*this->usage) == 0){
                        delete this->usage;
                        delete [] this->ptr;
                        this->ptr = nullptr;
                        this->usage = nullptr;
                    }
                if(pointer1.ptr == nullptr) return *this;

                this->usage = pointer1.usage;
                pointer1.usage = nullptr;

                (*this->usage)++;
                this->ptr = pointer1.ptr;
                pointer1.ptr = nullptr;
            }
            t& operator[](size_t element){
                return this->ptr[element];
            }

            bool isEmpty(){
                return this->ptr == nullptr;
            }

            t& operator*(){
                return *this->ptr;
            }

            operator t*(){
                return this->ptr;
            }

            ~PointerA(){
                if(this->ptr != nullptr)
                    if(--(*this->usage) == 0){
                        delete this->usage;
                        delete [] this->ptr;
                    }
                this->ptr = nullptr;
                this->usage = nullptr;
            }

        private:
            size_t* usage = nullptr;
            t* ptr = nullptr;
        };
    }
}


#endif //GAME_POINTER_H
