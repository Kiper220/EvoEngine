#include <iostream>
#include <RTL/JElement.h>

using namespace RTL::Types;

int main(){
    JElement jElement;
    jElement.setType(RTL::Types::JElementType::JRecord);
    jElement["test"] = 143;
    jElement["ges"] = 53;

    std::cout << (String)jElement;

    return 0;
}