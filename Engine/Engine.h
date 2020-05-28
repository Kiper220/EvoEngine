//
// Created by kiper220 on 15.05.2020.
//

#ifndef EVOENGINE_ENGINE_H
#define EVOENGINE_ENGINE_H

#if defined(_MSC_VER)
//  Microsoft
    #define EXPORT __declspec(dllexport)
    #define IMPORT __declspec(dllimport)
#elif defined(__GNUC__)
//  GCC
#define EXPORT __attribute__((visibility("default")))
#define IMPORT
#else
    #define EXPORT
    #define IMPORT
    #pragma warning Unknown dynamic link import/export semantics.
#endif

#ifdef DLL_EXPORT
#define DLL_PREFIX EXPORT
#else
#define DLL_PREFIX IMPORT
#endif // DLL_EXPORT

#include <string>

namespace EvoEngine{
    namespace Math{
        class Vector2;
        class Vector3;
        class Matrix3n;
        class Quaternion;
        namespace Collision{
            class Triangle;
        }
    }
    using String = std::string;
}

#endif //EVOENGINE_ENGINE_H
