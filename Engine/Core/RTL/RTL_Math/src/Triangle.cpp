//
// Created by kiper220 on 19.05.2020.
//

#include "RTL_Math/include/RTL/Math/Triangle.h"
#include "RTL_Math/include/RTL/Math/Quaternion.h"

namespace RTL::Math{
    namespace Collision{
        Triangle::Triangle():
                LocalTriangleData{{0,0,0},{0,0,0},{0,0,0}}{}
        Triangle::Triangle(const Vector3& vector31, const Vector3& vector32, const Vector3& vector33):
                LocalTriangleData{vector31, vector32, vector33}{}
        Triangle::Triangle(const Triangle& triangle):
                LocalTriangleData{triangle.LocalTriangleData[0], triangle.LocalTriangleData[1], triangle.LocalTriangleData[2]}{}

        Triangle& Triangle::operator =(const Triangle& triangle){
            this->LocalTriangleData[0] = triangle.LocalTriangleData[0];
            this->LocalTriangleData[1] = triangle.LocalTriangleData[1];
            this->LocalTriangleData[2] = triangle.LocalTriangleData[2];
        }
        void Triangle::operator()(const Triangle& triangle){
            this->LocalTriangleData[0] = triangle.LocalTriangleData[0];
            this->LocalTriangleData[1] = triangle.LocalTriangleData[1];
            this->LocalTriangleData[2] = triangle.LocalTriangleData[2];
        }
        void Triangle::operator()(const Vector3& vector31, const Vector3& vector32, const Vector3& vector33){
            this->LocalTriangleData[0] = vector31;
            this->LocalTriangleData[1] = vector32;
            this->LocalTriangleData[2] = vector33;
        }
        Triangle Triangle::getGlobalTriangle(const Vector3& GlobalLocation, const Quaternion& GlobalRotation, const Vector3& GlobalScale){
            return {
                    (this->LocalTriangleData[0].RotateVectorAboutAngleAndAxis(GlobalRotation.s, GlobalRotation.v)).scale(GlobalScale) + GlobalLocation,
                    (this->LocalTriangleData[1].RotateVectorAboutAngleAndAxis(GlobalRotation.s, GlobalRotation.v)).scale(GlobalScale) + GlobalLocation,
                    (this->LocalTriangleData[2].RotateVectorAboutAngleAndAxis(GlobalRotation.s, GlobalRotation.v)).scale(GlobalScale) + GlobalLocation,
            };
        }

        Triangle::operator String(){
            return String("{\n\t") + (String)this->LocalTriangleData[0] + "\n\t" + (String)this->LocalTriangleData[1] + "\n\t" + (String)this->LocalTriangleData[2] + "\n};";
        }

        Triangle::~Triangle(){}
    }
}