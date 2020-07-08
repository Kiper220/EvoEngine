//
// Created by kiper220 on 08.07.2020.
//

#ifndef EVOENGINE_RTL_H
#define EVOENGINE_RTL_H

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

namespace RTL::Types{
    class String;
    class FSEntity;
    class Directory;

    template<typename key, typename value>
    class Map;
    template<typename first, typename last>
    class Pair;
    template<typename t>
    class Vector;
    class Thread;
}
namespace RTL::Math{
    class Vector2;
    class Vector3;
    class Matrix3;
    class Quaternion;
    namespace Collision{
        class Triangle;
    }
    using String = std::string;
}

#endif //EVOENGINE_RTL_H
