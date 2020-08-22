//
// Created by kiper220 on 09.07.2020.
//

#ifndef GAME_MUTEX_H
#define GAME_MUTEX_H

#if defined(linux)

#include <pthread.h>

namespace RTL {
    namespace Types{
        class Mutex{
        public:
            Mutex();
            void Lock();
            void UnLock();
            bool TryLock();
            ~Mutex();

        private:
            pthread_mutex_t mtx;
        };
    }
}

#else

#endif

#endif //GAME_MUTEX_H
