//
// Created by kiper220 on 24.05.2020.
//

#ifndef GAME_THREAD_H
#define GAME_THREAD_H

#include <pthread.h>

namespace RTL::Types {

    template<typename arg>
    void functor_deleter(arg arg1){
        delete arg1;
    }

/**
 * \brief Helper Thread Functor Deleter
 */
    template<typename arg, typename ...args>
    void functor_deleter(arg arg1, args* ...other){
        delete arg1;
        functor_deleter(other...);
    }

/**
 * \brief Helper Thread Functor Caller
 */
    template<typename ret, typename ...args>
    void* function_caller(void* data){
        void** data1 = (void**)data;
        ret(*func)(args...) = (ret(*)(args...))(*data1);

        data1 += sizeof...(args) + 1;

        func(**(args**)(--data1)...);
        data1 += sizeof...(args);
        functor_deleter(*(args**)(--data1)...);

        data1--;
        delete [] data1;
    }

    class Thread{
    public:
        /**
         * \brief Thread creation
         */
        template<typename ret, typename ...args>
        Thread(ret(*func)(args...), args ...arg){
            void** data = new void*[sizeof...(arg) + 1];
            data[0] = (void*)func;
            data++;
            Parse(data, arg...);
            data--;
            pthread_attr_init(&thread_attr);
            pthread_create(&this->thread, &thread_attr, function_caller<ret, args...>, (void*)data);
        }

        /**
         * \brief Helper Thread Function
         */
        template<typename arg1, typename ...args>
        void Parse(void** parseTarget, arg1 arg){
            *parseTarget = new arg1;
            *(arg1*)(*parseTarget) = arg;
        }
        /**
         * \brief Helper Thread Function
         */
        template<typename arg1, typename ...args>
        void Parse(void** parseTarget, arg1 arg, args ...other){
            *parseTarget = new arg1;
            *(arg1*)(*parseTarget) = arg;
            parseTarget++;
            Parse(parseTarget, other...);
        }
        /**
         * \brief Thread join function
         */
        void Join(){
            pthread_join(this->thread, NULL);
        }
        /**
         * \brief Thread detach function
         */
        void Detach(){
            pthread_detach(this->thread);
        }
        /**
         * \brief Standart destructor
         */
        ~Thread(){
            pthread_detach(this->thread);
            pthread_attr_destroy(&thread_attr);
        }
    private:
        pthread_t thread;
        pthread_attr_t thread_attr;
    };
}

#endif //GAME_THREAD_H
