//
// Created by kiper220 on 16.05.2020.
//

#include "RTL_Math/include/RTL/Math/IVector2.h"
#include <math.h>
#include <string>

#define DegreesToRad(angle) angle*M_PI/180
#define RadToDegrees(angle) angle*180/M_PI


namespace RTL::Math{
    IVector2::IVector2(): x(0), y(0){}
    IVector2::IVector2(int uX, int uY): x(uX), y(uY){}
    IVector2::IVector2(const IVector2& vector2): x(vector2.x), y(vector2.y){}

    IVector2& IVector2::operator()(int uX, int uY){
        this->x = uX;
        this->y = uY;
    }
    IVector2& IVector2::operator()(const IVector2& vector2){
        this->x = vector2.x;
        this->y = vector2.y;
    }
    IVector2& IVector2::operator =(const IVector2& vector2){
        this->x = vector2.x;
        this->y = vector2.y;
    }

    IVector2& IVector2::operator+=(const IVector2& vector2){
        this->x += vector2.x;
        this->y += vector2.x;
    }
    IVector2& IVector2::operator-=(const IVector2& vector2){
        this->x -= vector2.x;
        this->y -= vector2.y;
    }
    void IVector2::operator*=(int s) {
        this->x *= s;
        this->y *= s;
    }
    void IVector2::operator /=(int s){
        this->x /= s;
        this->y /= s;
    }

    IVector2 IVector2::operator +(const IVector2& vector2){
        return {this->x + vector2.x,this->x + vector2.y};
    }
    IVector2 IVector2::operator -(const IVector2& vector2){
        return {this->x - vector2.x,this->y - vector2.y};
    }
    int IVector2::operator *(const IVector2& vector2) const{
        return this->x * vector2.x + this->y * vector2.y;
    }
    IVector2 IVector2::operator*(int s) const{
        return {this->x / s, this->y / s};
    }
    float IVector2::operator %(const IVector2& vector2){
        return vector2.cross(vector2);
    }
    IVector2 IVector2::operator /(int s){
        return {this->x / s, this->y / s};
    }

    IVector2 IVector2::RotateVectorAboutAngle(float uAngle) const{
        return {static_cast<int>(cosf(DegreesToRad(uAngle)) * this->x - cosf(DegreesToRad(uAngle)) * this->y),  static_cast<int>(sinf(DegreesToRad(uAngle)) * this->x + cosf(DegreesToRad(uAngle)) * this->y)};
    }
    float IVector2::cross(const IVector2& vector2) const{
        return this->x * vector2.y - this->y * vector2.x;
    }
    float IVector2::magnitude() const{
        return sqrtf(this->x * this->x + this->y * this->y);
    }
    void IVector2::normalize(){
        float magnitude = this->magnitude();

        if(magnitude > 0.0f){
            float oneOverMagnitude= 1.0f / magnitude;

            this->x = this->x * oneOverMagnitude;
            this->y = this->y * oneOverMagnitude;
        }
    }

    bool IVector2::operator ==(const IVector2& vector2) const{
        float r = this->x - vector2.x + this->y - vector2.y;
        return fabsf(r) < 0.0001;
    }
    bool IVector2::operator !=(const IVector2& vector2) const{
        float r = this->x - vector2.x + this->y - vector2.y;
        return fabsf(r) < 0.0001;
    }

    IVector2::operator String(){
        return String("X: ") + std::to_string(this->x) + String(", Y: ") + std::to_string(this->y) + ";";
    }

    IVector2::~IVector2(){

    }
}