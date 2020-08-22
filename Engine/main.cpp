#include <iostream>
#include <RTL/Pointer.h>
#include <RTL/JElement.h>

using namespace RTL::Types;

int main(){
    JElement jElement;
    jElement.setType(RTL::Types::JElementType::JRecord);
    jElement["value1"] = JElement(127);
    jElement["value2"] = JElement(53);
    jElement["Object"] = JElement(Map<String, JElement>(
                {
                        {"test1", JElement(532)},
                        {"test2", JElement(142.422)}
                    }
                    ));
    jElement["Array"] = JElement(Vector<JElement>(
            {
                JElement("test1"),
                JElement("test2")
            }));

    std::cout << (String)jElement;
    return 0;
}