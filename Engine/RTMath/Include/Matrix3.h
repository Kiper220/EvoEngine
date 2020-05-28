//
// Created by kiper220 on 16.05.2020.
//

#include "Engine/Engine.h"

#ifndef EVOENGINE_Matrix3_H
#define EVOENGINE_Matrix3_H


namespace EvoEngine{
    namespace Math{
        class Matrix3 {
        public:
            /**
             * \brief Standart zero constructor
             */
            Matrix3();
            /**
             * \brief Standart set constructor
             */
            Matrix3(float m0, float m3, float m6, float m1, float m4, float m7, float m2, float m5, float m8);
            /**
             * \brief Standart copy constructor
             */
            Matrix3(const Matrix3& Matrix3);

            /**
             * \brief Standart copy operator
             * \return this class reference
             */
            Matrix3& operator=(const Matrix3& Matrix3);

            /**
             * \brief Matrix overload operator+(const Matrix3x&)
             * \arg Matrix3 - target;
             * \return result of a mathematical operation
             */
            Matrix3 operator+(const Matrix3& Matrix3) const;
            /**
             * \brief Matrix overload operator*(const Matrix3x&)
             * \arg Matrix3 - target;
             * \return result of a mathematical operation
             */
            Matrix3 operator*(const Matrix3& Matrix3) const;
            /**
             * \brief Matrix overload operator*(float)
             * \arg Matrix3 - target;
             * \return result of a mathematical operation
             */
            Matrix3 operator*(float scalar) const;
            /**
             * \brief Matrix overload operator+(const Vector3&)
             * \arg Matrix3 - target;
             * \return result of a mathematical operation(Vector3)
             */
            Vector3 operator*(const Vector3& vector3) const;

            /**
             * \brief Matrix overload operator+=(const Matrix3&)
             * \return this class reference
             */
            void operator+=(const Matrix3& Matrix3);
            /**
             * \brief Matrix overload operator*=(const Matrix3&)
             * \return this class reference
             */
            void operator*=(const Matrix3& Matrix3);
            /**
             * \brief Matrix overload operator*=(float)
             * \return this class reference
             */
            void operator*=(float scalar);

            /**
             * \brief Set matrix as identity matrix function
             */
            void setMatrixAsIdentityMatrix();
            /**
             * \brief Set matrix as inverse of given matrix function
             */
            void setMatrixAsInverseOfGivenMatrix(const Matrix3& Matrix3);
            /**
             * \brief Get inverse of matrix(const)
             */
            Matrix3 getInverseOfMatrix() const;
            /**
             * \brief Get transpose of matrix(const)
             */
            Matrix3 getTransposeOfMatrix() const;
            /**
             * \brief Set matrix as transpose of given matrix(const Matrix&)
             */
            void setMatrixAsTransposeOfGivenMatrix(const Matrix3& Matrix3);
            /**
             * \brief Transform vector by matrix(const Vector3&)(const)
             */
            Vector3 transformVectorByMatrix(const Vector3& vector3) const;
            /**
             * \brief Invert matrix()
             */
            void invertMatrix();

            /**
             * \brief Overload operator String(const)
             */
            operator String() const;

            /**
             * \brief Standart destructor
             */
            ~Matrix3();

            /**
             * \brief Matrix Data
             */
            float matrixData[9] = {0.0};
        };
    }
}


#endif //EVOENGINE_Matrix3_H
