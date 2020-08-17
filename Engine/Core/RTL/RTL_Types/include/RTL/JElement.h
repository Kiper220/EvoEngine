

#ifndef GAME_JELEMENT_H
#define GAME_JELEMENT_H

#include <stdio.h>
#include <RTL/private/IJElement.h>

namespace RTL{
    namespace Types {

        class JElement {
        public:
            JElement();
            JElement(String str);
            JElement(int i);
            JElement(double d);
            JElement(bool b);
            JElement(Map<String, JElement> jRecord);
            JElement(Vector<JElement> jArray);
            JElement(IJElement* ijElement1);
            JElement(IJElement** ijElement1);
            JElement(const JElement& jElement);
            JElement(JElement&& jElement);

            void setType(JElementType::Type type);

            void operator=(String str);
            void operator=(int i);
            void operator=(double d);
            void operator=(bool b);
            void operator=(Map<String, JElement> jRecord);
            void operator=(Vector<JElement> jArray);
            void operator=(IJElement* ijElement1);
            void operator=(const JElement& jElement);
            void operator=(JElement&& jElement);

            void operator()(String str);
            void operator()(int i);
            void operator()(double d);
            void operator()(bool b);
            void operator()(Map<String, JElement> jRecord);
            void operator()(Vector<JElement> jArray);
            void operator()(IJElement* ijElement1);
            void operator()(const JElement& jElement);
            void operator()(JElement&& jElement);

            JElement operator[](String str);
            JElement operator[](const char* str);
            JElement operator[](int i);
            JElement operator[](JElement jElement);

            operator String();
            operator int();
            operator double();
            operator bool();
            operator Map<String, JElement>();
            operator Vector<JElement>();
            explicit operator IJElement*();

            ~JElement();

        private:
            union {
                IJElement* ijElement = nullptr;
                IJElement** pIjElement;
            } ijElementUnion;
            bool none = true;
            bool ptr = false;
        };
    }
}

#endif