
#define PRIVATE
#include "RTL/JElement.h"
#include <string>
#include <utility>


namespace RTL{
    namespace Types{
        JString::JString() {}
        JString::JString(String s) {
            this->jString = std::move(s);
        }
        JString::JString(const JString& jString1) {
            this->jString = jString1.jString;
        }
        void JString::operator =(String s) {
            this->jString = std::move(s);
        }

        String JString::getFormattedData() {
            if(this->jString.Size() != 0)
                return String("\"") + this->jString + String("\"");
            return "null";
        }
        String JString::getStringData() {
            return this->jString;
        }
        int JString::getIntegerData() {
            return atoi(this->jString);
        }
        double JString::getDoubleData() {
            return atof(this->jString);
        }
        bool JString::getBoolData() {
            return jString == "true";
        }
        JElementType::Type JString::getType() {
            return JElementType::JString;
        }


        JInteger::JInteger() {}
        JInteger::JInteger(int i) {
            this->jInteger = i;
        }
        JInteger::JInteger(const JInteger& jInteger1) {
            this->jInteger = jInteger1.jInteger;
        }
        void JInteger::operator =(int i) {
            this->jInteger = i;
        }

        String JInteger::getFormattedData() {
            return " ";
            //return String(std::to_string(this->jInteger).data());
        }
        String JInteger::getStringData() {
            return " ";
            //return String(std::to_string(this->jInteger).data());
        }
        int JInteger::getIntegerData() {
            return this->jInteger;
        }
        double JInteger::getDoubleData() {
            return this->jInteger;
        }
        bool JInteger::getBoolData() {
            return this->jInteger > 0;
        }
        JElementType::Type JInteger::getType() {
            return JElementType::JInteger;
        }


        JDouble::JDouble() {}
        JDouble::JDouble(double d) {
            this->jDouble = d;
        }
        JDouble::JDouble(const JDouble& jDouble1) {
            this->jDouble = jDouble1.jDouble;
        }
        void JDouble::operator =(double d) {
            this->jDouble = d;
        }

        String JDouble::getFormattedData() {
            return std::to_string(this->jDouble).data();
        }
        String JDouble::getStringData() {
            return std::to_string(this->jDouble).data();
        }
        int JDouble::getIntegerData() {
            return this->jDouble;
        }
        double JDouble::getDoubleData() {
            return this->jDouble;
        }
        bool JDouble::getBoolData() {
            return this->jDouble > 0;
        }
        JElementType::Type JDouble::getType() {
            return JElementType::JDouble;
        }


        JBool::JBool() {}
        JBool::JBool(bool b) {
            this->jBool = b;
        }
        JBool::JBool(const JBool& jBool1) {
            this->jBool = jBool1.jBool;
        }
        void JBool::operator =(bool b) {
            this->jBool = b;
        }

        String JBool::getFormattedData() {
            if(this->jBool)
                return "true";
            return "false";
        }
        String JBool::getStringData() {
            if(this->jBool)
                return "true";
            return "false";
        }
        int JBool::getIntegerData() {
            if(this->jBool) return 1;
            return 0;
        }
        double JBool::getDoubleData() {
            if(this->jBool) return 1;
            return 0;
        }
        bool JBool::getBoolData() {
            return this->jBool;
        }
        JElementType::Type JBool::getType() {
            return JElementType::JBool;
        }


        JRecord::JRecord() {}
        JRecord::JRecord(Map<String, IJElement*> r) {
            this->jRecord = r;
        }
        JRecord::JRecord(const JRecord& jRecord1) {
            this->jRecord = jRecord1.jRecord;
        }
        void JRecord::operator =(Map<String, IJElement*> r) {
            this->jRecord = r;
        }

        String JRecord::getFormattedData() {
            String str = "{ ";
            bool first = true;
            for(auto t : this->jRecord){
                if(first){
                    str += t.x + ": " + t.y->getFormattedData();
                    first = false;
                }
                str += ", ";
                str += t.x + ": " + t.y->getFormattedData();
            }
            str += " }";
            return str;
        }
        String JRecord::getStringData() {
            String str = "{ ";
            bool first = true;
            for(auto &t : this->jRecord){
                if(first){
                    str += t.x + ": ";
                    str += t.y->getStringData();
                    first = false;
                }
                else{
                    str += ", ";
                    str += t.x + ": " + t.y->getFormattedData();
                }
            }
            str += " }";
            return str;
        }
        int JRecord::getIntegerData() {
            return 0;
        }
        double JRecord::getDoubleData() {
            return 0;
        }
        bool JRecord::getBoolData() {
            return false;
        }
        JElementType::Type JRecord::getType() {
            return JElementType::JRecord;
        }
        Pair<String, IJElement*>* JRecord::begin(){
            this->jRecord.begin();
        }
        Pair<String, IJElement*>* JRecord::end(){
            this->jRecord.begin();
        }


        JArray::JArray() {}
        JArray::JArray(Vector<IJElement*> a) {
            this->jArray = std::move(a);
        }
        JArray::JArray(const JArray& jArray1) {
            this->jArray = jArray1.jArray;
        }
        void JArray::operator =(Vector<IJElement*> a) {
            this->jArray = std::move(a);
        }

        String JArray::getFormattedData() {
            String str = "[ ";
            bool first = true;
            for(auto t : this->jArray){
                if(first){
                    str += t->getFormattedData();
                    first = false;
                }
                str += ", ";
                str += t->getFormattedData();
            }
            str += " ]";
            return str;
        }
        String JArray::getStringData() {
            String str = "[ ";
            bool first = true;
            for(auto t : this->jArray){
                if(first){
                    str += t->getFormattedData();
                    first = false;
                }
                str += ", ";
                str += t->getFormattedData();
            }
            str += " ]";
            return str;
        }
        int JArray::getIntegerData() {
            return 0;
        }
        double JArray::getDoubleData() {
            return 0;
        }
        bool JArray::getBoolData() {
            return false;
        }
        JElementType::Type JArray::getType() {
            return JElementType::JArray;
        }
        //TODO Refactoring of class JElement and optimization of algorithms

        JElement::JElement(): none(true), ptr(false) {this->ijElementUnion.ijElement = nullptr;}
        JElement::JElement(String str): none(false), ptr(false) {this->ijElementUnion.ijElement = new JString(std::move(str));}
        JElement::JElement(int i): none(false), ptr(false) {this->ijElementUnion.ijElement = new JInteger(i);}
        JElement::JElement(double d): none(false), ptr(false) {this->ijElementUnion.ijElement = new JDouble(d);}
        JElement::JElement(bool b): none(false), ptr(false) {this->ijElementUnion.ijElement = new JBool(b);}
        JElement::JElement(Map<String, JElement> jRecord): none(false) {
            Map<String, IJElement*> element;
            for(auto &t: jRecord){
                element[t.x] = (IJElement*)t.y;
            }
            this->ptr = false;
            this->ijElementUnion.ijElement = new JRecord(std::move(element));
        }
        JElement::JElement(Vector<JElement> jArray): none(false){
            Vector<IJElement*> element;
            for(auto &t: jArray){
                element.Push_Back((IJElement*)t);
            }
            this->ptr = false;
            this->ijElementUnion.ijElement = new JArray(std::move(element));
        }
        JElement::JElement(IJElement* ijElement1): none(false){
            this->ptr = false;
            this->ijElementUnion.ijElement = ijElement1;
        }
        JElement::JElement(IJElement** ijElement1): none(false){
            this->ptr = true;
            this->ijElementUnion.pIjElement = ijElement1;
        }
        JElement::JElement(const JElement& jElement): none(false), ptr(false){
            if(!jElement.ptr){
                switch (jElement.ijElementUnion.ijElement->getType()) {
                    case JElementType::JString:
                        this->ijElementUnion.ijElement = new JString(((JString*)jElement.ijElementUnion.ijElement)->jString);
                        break;
                    case JElementType::JInteger:
                        this->ijElementUnion.ijElement = new JInteger(((JInteger*)jElement.ijElementUnion.ijElement)->jInteger);
                        break;
                    case JElementType::JDouble:
                        this->ijElementUnion.ijElement = new JDouble(((JDouble*)jElement.ijElementUnion.ijElement)->jDouble);
                        break;
                    case JElementType::JBool:
                        this->ijElementUnion.ijElement = new JBool(((JBool*)jElement.ijElementUnion.ijElement)->jBool);
                        break;
                    case JElementType::JRecord:
                        this->ijElementUnion.ijElement = new JRecord(((JRecord*)jElement.ijElementUnion.ijElement)->jRecord);
                        break;
                    case JElementType::JArray:
                        this->ijElementUnion.ijElement = new JArray(((JArray*)jElement.ijElementUnion.ijElement)->jArray);
                        break;
                }
                return;
            }
            switch (jElement.ijElementUnion.ijElement->getType()){
                case JElementType::JString:
                    this->ijElementUnion.ijElement = new JString(((JString*)*jElement.ijElementUnion.pIjElement)->jString);
                    break;
                case JElementType::JInteger:
                    this->ijElementUnion.ijElement = new JInteger(((JInteger*)*jElement.ijElementUnion.pIjElement)->jInteger);
                    break;
                case JElementType::JDouble:
                    this->ijElementUnion.ijElement = new JDouble(((JDouble*)*jElement.ijElementUnion.pIjElement)->jDouble);
                    break;
                case JElementType::JBool:
                    this->ijElementUnion.ijElement = new JBool(((JBool*)*jElement.ijElementUnion.pIjElement)->jBool);
                    break;
                case JElementType::JRecord:
                    this->ijElementUnion.ijElement = new JRecord(((JRecord*)*jElement.ijElementUnion.pIjElement)->jRecord);
                    break;
                case JElementType::JArray:
                    this->ijElementUnion.ijElement = new JArray(((JArray*)*jElement.ijElementUnion.pIjElement)->jArray);
                    break;
            }
        }
        JElement::JElement(JElement&& jElement){
            this->ijElementUnion = jElement.ijElementUnion;
            this->ptr = jElement.ptr;
            this->ptr = jElement.none;

            jElement.ijElementUnion.ijElement = nullptr;
            jElement.none = true;
            jElement.ptr = false;
        }
        void JElement::setType(JElementType::Type type){
            if(!this->ptr){
                if (!none) delete this->ijElementUnion.ijElement;
                else this->none = false;

                switch (type) {

                    case JElementType::JString:
                        this->ijElementUnion.ijElement = new JString;
                        break;
                    case JElementType::JInteger:
                        this->ijElementUnion.ijElement = new JInteger;
                        break;
                    case JElementType::JDouble:
                        this->ijElementUnion.ijElement = new JDouble;
                        break;
                    case JElementType::JBool:
                        this->ijElementUnion.ijElement = new JBool;
                        break;
                    case JElementType::JRecord:
                        this->ijElementUnion.ijElement = new JRecord;
                        break;
                    case JElementType::JArray:
                        this->ijElementUnion.ijElement = new JArray;
                        break;
                }
            }
        }

        void JElement::operator=(String str) {
            if(!this->ptr){
                if (!none){
                    if(typeid(this->ijElementUnion.ijElement) == typeid(JString)){
                        *(JString*)(this->ijElementUnion.ijElement) = str;
                        return;
                    }else  delete this->ijElementUnion.ijElement;
                }
                else this->none = false;

                this->ijElementUnion.ijElement = new JString(std::move(str));
                return;
            }else{
                if (!none){
                    if(typeid(*this->ijElementUnion.pIjElement) == typeid(JString)){
                        *(JString*)(*this->ijElementUnion.pIjElement) = str;
                        return;
                    }else  delete *this->ijElementUnion.pIjElement;
                }
                else this->none = false;

                *this->ijElementUnion.pIjElement = new JString(std::move(str));
                return;
            }
        }
        void JElement::operator=(int i) {
            if(!this->ptr){
                if (!none){
                    if(typeid(this->ijElementUnion.ijElement) == typeid(JInteger)){
                        *(JInteger*)(this->ijElementUnion.ijElement) = i;
                        return;
                    }else  delete this->ijElementUnion.ijElement;
                }
                else this->none = false;

                this->ijElementUnion.ijElement = new JInteger(i);
                return;
            }else{
                if (!none){
                    if(typeid(*this->ijElementUnion.pIjElement) == typeid(JInteger)){
                        *(JInteger*)(*this->ijElementUnion.pIjElement) = i;
                        return;
                    }else  delete *this->ijElementUnion.pIjElement;
                }
                else this->none = false;

                *this->ijElementUnion.pIjElement = new JInteger(i);
                return;
            }
        }
        void JElement::operator=(double d) {
            if(!this->ptr){
                if (!none){
                    if(typeid(this->ijElementUnion.ijElement) == typeid(JDouble)){
                        *(JDouble*)(this->ijElementUnion.ijElement) = d;
                        return;
                    }else  delete this->ijElementUnion.ijElement;
                }
                else this->none = false;

                this->ijElementUnion.ijElement = new JDouble(d);
                return;
            }else{
                if (!none){
                    if(typeid(*this->ijElementUnion.pIjElement) == typeid(JDouble)){
                        *(JDouble*)(*this->ijElementUnion.pIjElement) = d;
                        return;
                    }else  delete *this->ijElementUnion.pIjElement;
                }
                else this->none = false;

                *this->ijElementUnion.pIjElement = new JDouble(d);
                return;
            }
        }
        void JElement::operator=(bool b) {
            if(!this->ptr){
                if (!none){
                    if(typeid(this->ijElementUnion.ijElement) == typeid(JBool)){
                        *(JBool*)(this->ijElementUnion.ijElement) = b;
                        return;
                    }else  delete this->ijElementUnion.ijElement;
                }
                else this->none = false;

                this->ijElementUnion.ijElement = new JBool(b);
                return;
            }else{
                if (!none){
                    if(typeid(*this->ijElementUnion.pIjElement) == typeid(JBool)){
                        *(JBool*)(*this->ijElementUnion.pIjElement) = b;
                        return;
                    }else  delete *this->ijElementUnion.pIjElement;
                }
                else this->none = false;

                *this->ijElementUnion.pIjElement = new JBool(b);
                return;
            }
        }
        void JElement::operator=(Map<String, JElement> jRecord) {
            if(!this->ptr){
                if (!none) delete this->ijElementUnion.ijElement;
                else this->none = false;

                Map<String, IJElement*> element;
                for(auto &t: jRecord){
                    element[t.x] = (IJElement*)t.y;
                }
                this->ijElementUnion.ijElement = new JRecord(element);
                return;
            }else{
                if (!none) delete *this->ijElementUnion.pIjElement;
                else this->none = false;

                Map<String, IJElement*> element;
                for(auto &t: jRecord){
                    element[t.x] = (IJElement*)t.y;
                }
                *this->ijElementUnion.pIjElement = new JRecord(element);

                return;
            }
        }
        void JElement::operator=(Vector<JElement> jArray) {
            if(!this->ptr){
                if (!none) delete this->ijElementUnion.ijElement;
                else this->none = false;

                Vector<IJElement*> element;
                for(auto &t: jArray){
                    element.Push_Back((IJElement*)t);
                }
                this->ijElementUnion.ijElement = new JArray(element);
                return;
            }else{
                if (!none) delete *this->ijElementUnion.pIjElement;
                else this->none = false;

                Vector<IJElement*> element;
                for(auto &t: jArray){
                    element.Push_Back((IJElement*)t);
                }
                *this->ijElementUnion.pIjElement = new JArray(element);

                return;
            }
        }
        void JElement::operator=(IJElement* ijElement1) {
            if(!this->ptr && !this->none) delete this->ijElementUnion.ijElement;
            else if(this->ptr && !this->none) delete this->ijElementUnion.ijElement;

            this->ijElementUnion.ijElement = ijElement1;
            this->ptr = false;
            this->none = false;
        }
        void JElement::operator=(const JElement& jElement) {
            if(!this->ptr && !this->none) delete this->ijElementUnion.ijElement;
            else if(this->ptr && !this->none) delete this->ijElementUnion.ijElement;

            else this->none = false;
            this->ptr = false;

            if(!jElement.ptr){
                switch (jElement.ijElementUnion.ijElement->getType()) {
                    case JElementType::JString:
                        this->ijElementUnion.ijElement = new JString(((JString*)jElement.ijElementUnion.ijElement)->jString);
                        break;
                    case JElementType::JInteger:
                        this->ijElementUnion.ijElement = new JInteger(((JInteger*)jElement.ijElementUnion.ijElement)->jInteger);
                        break;
                    case JElementType::JDouble:
                        this->ijElementUnion.ijElement = new JDouble(((JDouble*)jElement.ijElementUnion.ijElement)->jDouble);
                        break;
                    case JElementType::JBool:
                        this->ijElementUnion.ijElement = new JBool(((JBool*)jElement.ijElementUnion.ijElement)->jBool);
                        break;
                    case JElementType::JRecord:
                        this->ijElementUnion.ijElement = new JRecord(((JRecord*)jElement.ijElementUnion.ijElement)->jRecord);
                        break;
                    case JElementType::JArray:
                        this->ijElementUnion.ijElement = new JArray(((JArray*)jElement.ijElementUnion.ijElement)->jArray);
                        break;
                }
                return;
            }
            switch (jElement.ijElementUnion.ijElement->getType()){
                case JElementType::JString:
                    this->ijElementUnion.ijElement = new JString(((JString*)*jElement.ijElementUnion.pIjElement)->jString);
                    break;
                case JElementType::JInteger:
                    this->ijElementUnion.ijElement = new JInteger(((JInteger*)*jElement.ijElementUnion.pIjElement)->jInteger);
                    break;
                case JElementType::JDouble:
                    this->ijElementUnion.ijElement = new JDouble(((JDouble*)*jElement.ijElementUnion.pIjElement)->jDouble);
                    break;
                case JElementType::JBool:
                    this->ijElementUnion.ijElement = new JBool(((JBool*)*jElement.ijElementUnion.pIjElement)->jBool);
                    break;
                case JElementType::JRecord:
                    this->ijElementUnion.ijElement = new JRecord(((JRecord*)*jElement.ijElementUnion.pIjElement)->jRecord);
                    break;
                case JElementType::JArray:
                    this->ijElementUnion.ijElement = new JArray(((JArray*)*jElement.ijElementUnion.pIjElement)->jArray);
                    break;
            }
        }
        void JElement::operator=(JElement&& jElement) {
            this->ijElementUnion = jElement.ijElementUnion;
            this->none = jElement.none;
            this->ptr = jElement.ptr;

            jElement.ijElementUnion.ijElement = nullptr;
            jElement.none = true;
            jElement.ptr = false;
        }

        void JElement::operator()(String str) {
            *this = std::move(str);
        }
        void JElement::operator()(int i) {
            *this = i;
        }
        void JElement::operator()(double d) {
            *this = d;
        }
        void JElement::operator()(bool b) {
            *this = b;
        }
        void JElement::operator()(Map<String, JElement> jRecord) {
            *this = jRecord;
        }
        void JElement::operator()(Vector<JElement> jArray) {
            *this = jArray;
        }
        void JElement::operator()(IJElement* ijElement1) {
            *this = ijElement1;
        }
        void JElement::operator()(const JElement& jElement) {
            *this = jElement;
        }
        void JElement::operator()(JElement&& jElement) {
            *this = jElement;
        }

        //TODO Refactoring array and record functions (auto convert to JRecord and optimization of algorithms)

        JElement JElement::operator[](String str) {
            if(!this->ptr){
                if(this->ijElementUnion.ijElement->getType() == JElementType::JRecord) {
                    return (IJElement**)((JRecord*) this->ijElementUnion.ijElement)->jRecord[str];
                }
                else if(this->ijElementUnion.ijElement->getType() == JElementType::JArray)
                    return (IJElement**)((JArray*)this->ijElementUnion.ijElement)->jArray[atoi(str)];
                return JElement();
            }
            else{
                if((*this->ijElementUnion.pIjElement)->getType() == JElementType::JRecord) {
                    return (IJElement**)((JRecord*)(*this->ijElementUnion.pIjElement))->jRecord[str];
                }
                else if((*this->ijElementUnion.pIjElement)->getType() == JElementType::JArray)
                    return (IJElement**)((JArray*)(*this->ijElementUnion.pIjElement))->jArray[atoi(str)];
                return JElement();
            }
        }
        JElement JElement::operator[](const char* str) {
            if(!this->ptr){
                if(this->ijElementUnion.ijElement->getType() == JElementType::JRecord) {
                    return (IJElement**)((JRecord*) this->ijElementUnion.ijElement)->jRecord[str];
                }
                else if(this->ijElementUnion.ijElement->getType() == JElementType::JArray)
                    return (IJElement**)((JArray*)this->ijElementUnion.ijElement)->jArray[atoi(str)];
                return JElement();
            }
            else{
                if((*this->ijElementUnion.pIjElement)->getType() == JElementType::JRecord) {
                    return (IJElement**)((JRecord*)(*this->ijElementUnion.pIjElement))->jRecord[str];
                }
                else if((*this->ijElementUnion.pIjElement)->getType() == JElementType::JArray)
                    return (IJElement**)((JArray*)(*this->ijElementUnion.pIjElement))->jArray[atoi(str)];
                return JElement();
            }
        }
        JElement JElement::operator[](int i) {
            if(!this->ptr){
                if(this->ijElementUnion.ijElement->getType() == JElementType::JRecord) {
                    return (IJElement**)((JRecord*) this->ijElementUnion.ijElement)->jRecord[std::to_string(i).data()];
                }
                else if(this->ijElementUnion.ijElement->getType() == JElementType::JArray)
                    return (IJElement**)((JArray*)this->ijElementUnion.ijElement)->jArray[i];
                return JElement();
            }
            else{
                if((*this->ijElementUnion.pIjElement)->getType() == JElementType::JRecord) {
                    return (IJElement**)((JRecord*)(*this->ijElementUnion.pIjElement))->jRecord[std::to_string(i).data()];
                }
                else if((*this->ijElementUnion.pIjElement)->getType() == JElementType::JArray)
                    return (IJElement**)((JArray*)(*this->ijElementUnion.pIjElement))->jArray[i];
                return JElement();
            }
        }
        JElement JElement::operator[](JElement jElement) {
            switch (((IJElement*)jElement)->getType()) {
                case JElementType::JString:{
                    if(((IJElement*)(*this))->getType() == JElementType::JRecord) {
                        return &(IJElement&)((JRecord*) ((IJElement*)(*this)))->jRecord[((JString*)((IJElement*)jElement))->jString];
                    }
                    else if(((IJElement*)(*this))->getType() == JElementType::JArray)
                        return &(IJElement&)((JArray*)((IJElement*)(*this)))->jArray[atoi(((JString*)((IJElement*)jElement))->jString)];
                    return *this;
                }
                case JElementType::JInteger: {
                    if(((IJElement*)(*this))->getType() == JElementType::JRecord) {
                        return &(IJElement&)((JRecord*) ((IJElement*)(*this)))->jRecord[std::to_string(((JInteger *) ((IJElement*)jElement))->jInteger).data()];
                    }
                    else if(((IJElement*)(*this))->getType() == JElementType::JArray)
                        return &(IJElement&)((JArray*)((IJElement*)(*this)))->jArray[((JInteger *) ((IJElement*)jElement))->jInteger];
                    return *this;
                }
                case JElementType::JDouble: {
                    if(((IJElement*)(*this))->getType() == JElementType::JRecord) {
                        return &(IJElement&)((JRecord*) ((IJElement*)(*this)))->jRecord[std::to_string(((JDouble *) ((IJElement*)jElement))->jDouble).data()];
                    }
                    else if(((IJElement*)(*this))->getType() == JElementType::JArray)
                        return &(IJElement&)((JArray*)((IJElement*)(*this)))->jArray[((JDouble *) ((IJElement*)jElement))->jDouble];
                    return *this;
                }
            }
            return *this;
        }

        JElement::operator String() {
            return ((IJElement*)(*this))->getStringData();
        }
        JElement::operator int() {
            return ((IJElement*)(*this))->getIntegerData();
        }
        JElement::operator double() {
            return ((IJElement*)(*this))->getDoubleData();
        }
        JElement::operator bool() {
            return ((IJElement*)(*this))->getBoolData();
        }
        JElement::operator Map<String, JElement>() {
            if (((IJElement*)(*this))->getType() == JElementType::JRecord) {
                JRecord* jRecord = (JRecord*)((IJElement*)(*this));
                Map<String, JElement> record;
                for(auto &t: jRecord->jRecord)
                    record[t.x] = t.y;
                return record;
            }
            return JElement();
        }
        JElement::operator Vector<JElement>() {
            if (((IJElement*)(*this))->getType() == JElementType::JRecord) {
                JArray* jArray = (JArray*)((IJElement*)(*this));
                Vector<JElement> array;
                for(auto &t: jArray->jArray)
                    array.Push_Back(t);
                return array;
            }
            return JElement();
        }
        JElement::operator IJElement*() {
            if(this->ptr) return *this->ijElementUnion.pIjElement;
            return this->ijElementUnion.ijElement;
        }

        JElement::~JElement() {
            if (!none) delete ((IJElement*)(*this));
            if(this->ptr) {
                *this->ijElementUnion.pIjElement = nullptr;
            }
            this->none = true;
        }
    }
}