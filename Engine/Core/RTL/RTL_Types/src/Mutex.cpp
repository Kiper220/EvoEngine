//
// Created by kiper220 on 09.07.2020.
//

#include <RTL/Mutex.h>

#if defined(linux)

namespace RTL::Types {

    Mutex::Mutex() {
        pthread_mutex_init(&mtx, NULL);
    }

    void Mutex::Lock() {
        pthread_mutex_lock(&mtx);
    }

    void Mutex::UnLock() {
        pthread_mutex_unlock(&mtx);
    }

    bool Mutex::TryLock() {
        return !pthread_mutex_trylock(&mtx);
    }

    Mutex::~Mutex() {
        pthread_mutex_destroy(&mtx);
    }
}

#else

#endif