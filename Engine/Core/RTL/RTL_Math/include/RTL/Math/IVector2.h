//
// Created by kiper220 on 16.05.2020.
//
#include "RTL.h"

#ifndef EVOENGINE_VECTOR2_H
#define EVOENGINE_VECTOR2_H

namespace RTL::Math{
    DLL_PREFIX class IVector2 {
    public:
        /**
         * \brief Standart zero constructor
         */
        IVector2();
        /**
         * \brief Standart data constructor
         */
        IVector2(int uX, int uY);
        /**
         * \brief Standart copy constructor
         */
        IVector2(const IVector2& iVector2);

        /**
         * \brief Vector2 overload operator()(float, float)
         */
        IVector2& operator()(int uX, int uY);
        /**
         * \brief Vector2 overload operator()(const Vector2&)
         */
        IVector2& operator()(const IVector2& iVector2);
        /**
         * \brief Vector2 overload operator=(const Vector2&)
         */
        IVector2& operator =(const IVector2& iVector2);

        /**
         * \brief Vector2 overload operator+=(const Vector2&)
         */
        IVector2& operator+=(const IVector2& iVector2);
        /**
         * \brief Vector2 overload operator-=(const Vector2&)
         */
        IVector2& operator-=(const IVector2& iVector2);
        /**
         * \brief Vector2 overload operator*=(float)
         */
        void operator*=(int s);
        /**
         * \brief Vector2 overload operator/=(float)
         */
        void operator /=(int s);

        /**
         * \brief Vector2 overload operator+(const Vector2&)
         * \return result of mathematical operation
         */
        IVector2 operator +(const IVector2& iVector2);
        /**
         * \brief Vector2 overload operator-(const Vector2&)
         * \return result of mathematical operation
         */
        IVector2 operator -(const IVector2& iVector2);
        /**
         * \brief Vector2 overload operator*(const Vector2&)
         * \return result of mathematical operation
         */
        int operator *(const IVector2& iVector2) const;
        /**
         * \brief Vector2 overload operator*(float)
         * \return result of mathematical operation
         */
        IVector2 operator*(int s) const;
        /**
         * \brief Vector2 overload operator*(const Vector2&)
         * \return result of mathematical operation
         */
        float operator %(const IVector2& iVector2);
        /**
         * \brief Vector2 overload operator/(float)
         * \return result of mathematical operation
         */
        IVector2 operator /(int s);

        /**
         * \brief Rotate vector about angle(float)(const)
         * \return result of mathematical operation
         */
        IVector2 RotateVectorAboutAngle(float uAngle) const;
        /**
         * \brief Vector2 cross (const Vector2&)(const)
         * \return result of mathematical operation
         */
        float cross(const IVector2& IVector2) const;
        /**
         * \brief Vector2 magnitude (const)
         * \return result of mathematical operation
         */
        float magnitude() const;
        /**
         * \brief Vector2 normalize
         * \return result of mathematical operation
         */
        void normalize();

        /**
         * \brief Vector2 overload operator==(const Vector2&)(const)
         * \return bool
         */
        bool operator ==(const IVector2& iVector2) const;
        /**
         * \brief Vector2 overload operator==(const Vector2&)(const)
         * \return bool
         */
        bool operator !=(const IVector2& iVector2) const;

        /**
         * \brief Overload operator String(const)
         */
        operator String();

        /**
         * \brief Standart destructor
         */
        ~IVector2();

        /**
         * \brief Vector2 data
         */
        int x, y;
    };
}


#endif //EVOENGINE_VECTOR2_H
