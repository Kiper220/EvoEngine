//
// Created by kiper220 on 16.05.2020.
//

#include "Engine/RTMath/Include/Matrix3.h"
#include "Engine/RTMath/Include/Vector3.h"

namespace EvoEngine{
    namespace Math{
        Matrix3::Matrix3(){
            for(float& a: this->matrixData)
                a = 0.0;

            this->matrixData[0] = this->matrixData[4] = this->matrixData[8]=1.0f;
        }
        Matrix3::Matrix3(float m0, float m3, float m6, float m1, float m4, float m7, float m2, float m5, float m8){
            matrixData[0] = m0;
            matrixData[3] = m3;
            matrixData[6] = m6;

            matrixData[1] = m1;
            matrixData[4] = m4;
            matrixData[7] = m7;

            matrixData[2] = m2;
            matrixData[5] = m5;
            matrixData[8] = m8;
        }
        Matrix3::Matrix3(const Matrix3& Matrix3){
            matrixData[0] = Matrix3.matrixData[0];
            matrixData[3] = Matrix3.matrixData[3];
            matrixData[6] = Matrix3.matrixData[6];

            matrixData[1] = Matrix3.matrixData[1];
            matrixData[4] = Matrix3.matrixData[4];
            matrixData[7] = Matrix3.matrixData[7];

            matrixData[2] = Matrix3.matrixData[2];
            matrixData[5] = Matrix3.matrixData[5];
            matrixData[8] = Matrix3.matrixData[8];
        }

        Matrix3& Matrix3::operator=(const Matrix3& Matrix3){
            matrixData[0] = Matrix3.matrixData[0];
            matrixData[3] = Matrix3.matrixData[3];
            matrixData[6] = Matrix3.matrixData[6];

            matrixData[1] = Matrix3.matrixData[1];
            matrixData[4] = Matrix3.matrixData[4];
            matrixData[7] = Matrix3.matrixData[7];

            matrixData[2] = Matrix3.matrixData[2];
            matrixData[5] = Matrix3.matrixData[5];
            matrixData[8] = Matrix3.matrixData[8];

            return *this;
        }
        Matrix3 Matrix3::operator+(const Matrix3& Matrix3) const{
            EvoEngine::Math::Matrix3 Matrix31;
            Matrix31 = *this;
            Matrix31.matrixData[0] += Matrix3.matrixData[0];
            Matrix31.matrixData[1] += Matrix3.matrixData[1];
            Matrix31.matrixData[2] += Matrix3.matrixData[2];
            Matrix31.matrixData[3] += Matrix3.matrixData[3];
            Matrix31.matrixData[4] += Matrix3.matrixData[4];
            Matrix31.matrixData[5] += Matrix3.matrixData[5];
            Matrix31.matrixData[6] += Matrix3.matrixData[6];
            Matrix31.matrixData[7] += Matrix3.matrixData[7];
            Matrix31.matrixData[8] += Matrix3.matrixData[8];

            return Matrix31;
        }
        Matrix3 Matrix3::operator*(const Matrix3& Matrix3) const{
            return EvoEngine::Math::Matrix3(
                    this->matrixData[0] * Matrix3.matrixData[0] + this->matrixData[3] * Matrix3.matrixData[1] + this->matrixData[6] * Matrix3.matrixData[2],
                    this->matrixData[0] * Matrix3.matrixData[3] + this->matrixData[3] * Matrix3.matrixData[4] + this->matrixData[6] * Matrix3.matrixData[5],
                    this->matrixData[0] * Matrix3.matrixData[6] + this->matrixData[3] * Matrix3.matrixData[7] + this->matrixData[6] * Matrix3.matrixData[8],

                    this->matrixData[1] * Matrix3.matrixData[0] + this->matrixData[4] * Matrix3.matrixData[1] + this->matrixData[7] * Matrix3.matrixData[2],
                    this->matrixData[1] * Matrix3.matrixData[3] + this->matrixData[4] * Matrix3.matrixData[4] + this->matrixData[7] * Matrix3.matrixData[5],
                    this->matrixData[1] * Matrix3.matrixData[6] + this->matrixData[4] * Matrix3.matrixData[7] + this->matrixData[7] * Matrix3.matrixData[8],

                    this->matrixData[2] * Matrix3.matrixData[0] + this->matrixData[5] * Matrix3.matrixData[1] + this->matrixData[8] * Matrix3.matrixData[2],
                    this->matrixData[2] * Matrix3.matrixData[3] + this->matrixData[5] * Matrix3.matrixData[4] + this->matrixData[8] * Matrix3.matrixData[5],
                    this->matrixData[2] * Matrix3.matrixData[6] + this->matrixData[5] * Matrix3.matrixData[7] + this->matrixData[8] * Matrix3.matrixData[8]);
        }
        Matrix3 Matrix3::operator*(float scalar) const{
            Matrix3 Matrix31;
            Matrix31 = *this;
            Matrix31.matrixData[0] *= scalar;
            Matrix31.matrixData[1] *= scalar;
            Matrix31.matrixData[2] *= scalar;
            Matrix31.matrixData[3] *= scalar;
            Matrix31.matrixData[4] *= scalar;
            Matrix31.matrixData[5] *= scalar;
            Matrix31.matrixData[6] *= scalar;
            Matrix31.matrixData[7] *= scalar;
            Matrix31.matrixData[8] *= scalar;

            return Matrix31;
        }
        Vector3 Matrix3::operator*(const Vector3& vector3) const{
            return Vector3(this->matrixData[0] * vector3.x + this->matrixData[3] * vector3.y + this->matrixData[6] * vector3.z,
                           this->matrixData[1] * vector3.x + this->matrixData[4] * vector3.y + this->matrixData[7] * vector3.z,
                           this->matrixData[2] * vector3.x + this->matrixData[5] * vector3.y + this->matrixData[8] * vector3.z);
        }

        void Matrix3::operator+=(const Matrix3& Matrix3){
            this->matrixData[0] += Matrix3.matrixData[0];
            this->matrixData[1] += Matrix3.matrixData[1];
            this->matrixData[2] += Matrix3.matrixData[2];
            this->matrixData[3] += Matrix3.matrixData[3];
            this->matrixData[4] += Matrix3.matrixData[4];
            this->matrixData[5] += Matrix3.matrixData[5];
            this->matrixData[6] += Matrix3.matrixData[6];
            this->matrixData[7] += Matrix3.matrixData[7];
            this->matrixData[8] += Matrix3.matrixData[8];
        }
        void Matrix3::operator*=(const Matrix3& Matrix3){
            float t1;
            float t2;
            float t3;

            t1 = this->matrixData[0] * Matrix3.matrixData[0] + this->matrixData[3] * Matrix3.matrixData[1] + this->matrixData[6] * Matrix3.matrixData[2];
            t2 = this->matrixData[0] * Matrix3.matrixData[3] + this->matrixData[3] * Matrix3.matrixData[4] + this->matrixData[6] * Matrix3.matrixData[5];
            t3 = this->matrixData[0] * Matrix3.matrixData[6] + this->matrixData[3] * Matrix3.matrixData[7] + this->matrixData[6] * Matrix3.matrixData[8];

            this->matrixData[0]=t1;
            this->matrixData[3]=t2;
            this->matrixData[6]=t3;

            t1 = this->matrixData[1] * Matrix3.matrixData[0] + this->matrixData[4] * Matrix3.matrixData[1] + this->matrixData[7] * Matrix3.matrixData[2];
            t2 = this->matrixData[1] * Matrix3.matrixData[3] + this->matrixData[4] * Matrix3.matrixData[4] + this->matrixData[7] * Matrix3.matrixData[5];
            t3 = this->matrixData[1] * Matrix3.matrixData[6] + this->matrixData[4] * Matrix3.matrixData[7] + this->matrixData[7] * Matrix3.matrixData[8];

            this->matrixData[1]=t1;
            this->matrixData[4]=t2;
            this->matrixData[7]=t3;


            t1 = this->matrixData[2] * Matrix3.matrixData[0] + this->matrixData[5] * Matrix3.matrixData[1] + this->matrixData[8] * Matrix3.matrixData[2];
            t2 = this->matrixData[2] * Matrix3.matrixData[3] + this->matrixData[5] * Matrix3.matrixData[4] + this->matrixData[8] * Matrix3.matrixData[5];
            t3 = this->matrixData[2] * Matrix3.matrixData[6] + this->matrixData[5] * Matrix3.matrixData[7] + this->matrixData[8] * Matrix3.matrixData[8];

            this->matrixData[2]=t1;
            this->matrixData[5]=t2;
            this->matrixData[8]=t3;
        }
        void Matrix3::operator*=(float scalar){
            this->matrixData[0] *= scalar;
            this->matrixData[1] *= scalar;
            this->matrixData[2] *= scalar;
            this->matrixData[3] *= scalar;
            this->matrixData[4] *= scalar;
            this->matrixData[5] *= scalar;
            this->matrixData[6] *= scalar;
            this->matrixData[7] *= scalar;
            this->matrixData[8] *= scalar;
        }

        void Matrix3::setMatrixAsIdentityMatrix(){
            for (float &i : this->matrixData)
                i=0.0f;

            this->matrixData[0] = this->matrixData[4] = this->matrixData[8]=1.0f;
        }
        void Matrix3::setMatrixAsInverseOfGivenMatrix(const Matrix3& Matrix3){
            float t1=Matrix3.matrixData[0]*Matrix3.matrixData[4];
            float t2=Matrix3.matrixData[0]*Matrix3.matrixData[7];
            float t3=Matrix3.matrixData[3]*Matrix3.matrixData[1];
            float t4=Matrix3.matrixData[6]*Matrix3.matrixData[1];
            float t5=Matrix3.matrixData[3]*Matrix3.matrixData[2];
            float t6=Matrix3.matrixData[6]*Matrix3.matrixData[2];

            //calculate the determinant

            float det=(t1*Matrix3.matrixData[8]-t2*Matrix3.matrixData[5]-t3*Matrix3.matrixData[8]+t4*Matrix3.matrixData[5]+t5*Matrix3.matrixData[7]-t6*Matrix3.matrixData[4]);

            //make sure the det is non-zero
            if (det==0.0) return;

            float invd=1.0f/det;

            float m0=(Matrix3.matrixData[4]*Matrix3.matrixData[8]-Matrix3.matrixData[7]*Matrix3.matrixData[5])*invd;
            float m3=-(Matrix3.matrixData[3]*Matrix3.matrixData[8]-Matrix3.matrixData[6]*Matrix3.matrixData[5])*invd;

            float m6=(Matrix3.matrixData[3]*Matrix3.matrixData[7]-Matrix3.matrixData[6]*Matrix3.matrixData[4])*invd;

            float m1=-(Matrix3.matrixData[1]*Matrix3.matrixData[8]-Matrix3.matrixData[7]*Matrix3.matrixData[2])*invd;

            float m4=(Matrix3.matrixData[0]*Matrix3.matrixData[8]-t6)*invd;

            float m7=-(t2-t4)*invd;

            float m2=(Matrix3.matrixData[1]*Matrix3.matrixData[5]-Matrix3.matrixData[4]*Matrix3.matrixData[2])*invd;

            float m5=-(Matrix3.matrixData[0]*Matrix3.matrixData[5]-t5)*invd;

            float m8=(t1-t3)*invd;

            this->matrixData[0]=m0;
            this->matrixData[3]=m3;
            this->matrixData[6]=m6;

            this->matrixData[1]=m1;
            this->matrixData[4]=m4;
            this->matrixData[7]=m7;

            this->matrixData[2]=m2;
            this->matrixData[5]=m5;
            this->matrixData[8]=m8;
        }
        Matrix3 Matrix3::getInverseOfMatrix() const{
            Matrix3 returnValue;
            returnValue.setMatrixAsInverseOfGivenMatrix(*this);
            return returnValue;
        }
        void Matrix3::setMatrixAsTransposeOfGivenMatrix(const Matrix3& Matrix3){
            this->matrixData[0] = Matrix3.matrixData[0];
            this->matrixData[3] = Matrix3.matrixData[1];
            this->matrixData[6] = Matrix3.matrixData[2];

            this->matrixData[1] = Matrix3.matrixData[3];
            this->matrixData[4] = Matrix3.matrixData[4];
            this->matrixData[7] = Matrix3.matrixData[5];

            this->matrixData[2] = Matrix3.matrixData[6];
            this->matrixData[5] = Matrix3.matrixData[7];
            this->matrixData[8] = Matrix3.matrixData[8];
        }

        Matrix3 Matrix3::getTransposeOfMatrix() const{
            Matrix3 returnValue;
            returnValue.setMatrixAsTransposeOfGivenMatrix(*this);
            return returnValue;
        }
        void Matrix3::invertMatrix(){
            setMatrixAsInverseOfGivenMatrix(*this);
        }

        Vector3 Matrix3::transformVectorByMatrix(const Vector3& vector3) const{
            return (*this) * vector3;
        }


        Matrix3::operator String() const{
            return
                    String("[") + std::to_string(matrixData[0]) + String(",") + std::to_string(matrixData[3]) +
                    String(",") + std::to_string(matrixData[6]) + String(",\n ") +
                    std::to_string(matrixData[1]) + String(",") + std::to_string(matrixData[4]) +
                    String(",") + std::to_string(matrixData[7]) + String(",\n ") +
                    std::to_string(matrixData[2]) + String(",") + std::to_string(matrixData[5]) +
                    String(",") + std::to_string(matrixData[8]) + String("]");
        }

        Matrix3::~Matrix3(){

        }
    }
}