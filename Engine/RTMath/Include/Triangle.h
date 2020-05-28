//
// Created by kiper220 on 19.05.2020.
//

#include "Engine/Engine.h"
#include "Vector3.h"

#ifndef EVOENGINE_TRIANGLE_H
#define EVOENGINE_TRIANGLE_H

namespace EvoEngine{
    namespace Math{
        namespace Collision{
            class Triangle{
            public:
                /**
                 * \brief Standart zero constructor
                 */
                Triangle();
                /**
                 * \brief Standart data constructor
                 */
                Triangle(const Vector3& vector31, const Vector3& vector32, const Vector3& vector33);
                /**
                 * \brief Standart copy constructor
                 */
                Triangle(const Triangle& triangle);

                /**
                 * \brief Standart copy operator
                 */
                Triangle& operator =(const Triangle& triangle);
                /**
                 * \brief Standart copy operator()
                 */
                void operator()(const Triangle& triangle);
                /**
                 * \brief Standart data operator()
                 */
                void operator()(const Vector3& vector31, const Vector3& vector32, const Vector3& vector33);
                /**
                 * \brief Get global triangle function
                 * \return Global Triangle
                 */
                Triangle getGlobalTriangle(const Vector3& GlobalLocation, const Quaternion& GlobalRotation, const Vector3& GlobalScale);

                /**
                 * \brief Overload operator String(const)
                 */
                operator String();

                /**
                 * \brief Standart destructor
                 */
                ~Triangle();

                /**
                 * \brief Triangle data
                 */
                Vector3 LocalTriangleData[3];
            };
        }
    }
}

#endif //EVOENGINE_TRIANGLE_H
