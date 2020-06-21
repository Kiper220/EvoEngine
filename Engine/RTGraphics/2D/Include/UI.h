//
// Created by kiper220 on 03.06.2020.
//

#ifndef GAME_UI_H
#define GAME_UI_H
#include <Vector.h>
#include <String.h>
#include <Vector2.h>
#include <Quaternion.h>

class UElement{
    enum BorderType{
        Solid,
        Doted
    };

    EvoEngine::Math::Vector2 Position;
    EvoEngine::Math::Vector2 Scale;
    EvoEngine::Math::Quaternion Rotation;

    BorderType BorderLeftType;
    BorderType BorderTopType;
    BorderType BorderRightType;
    BorderType BorderBottomType;

    float BorderLeftWeight;
    float BorderTopWeight;
    float BorderRightWeight;
    float BorderBottomWeight;

    float BorderLeftTopRadius;
    float BorderRightTopRadius;
    float BorderRightBottomRadius;
    float BorderLeftBottomRadius;

    EvoEngine::Math::Vector3 BorderColor_RGB;
    float BorderColor_Alpha;

    EvoEngine::Math::Vector3 BackgroundColor_RGB;
    float BackgroundColor_Alpha;
};

struct UITreeElement{
    UElement *element;
    RTL::Vector<UITreeElement> array;
    unsigned int ElementId;
    RTL::String ElementClass;
    char TreeType;
};

class UIConstructor{

    UITreeElement root;
};

#endif //GAME_UI_H
