
#define PRIVATE
#include "RTL/JElement.h"
#include <iostream>
#include <string>
#include <utility>


namespace RTL{
    namespace Types{

        JString::JString() = default;
        JString::JString(String s): jString(s) {}
        JString::JString(const JString& jString1): jString(jString1.jString) {}
        JString& JString::operator =(String s){
            this->jString = std::move(s);
            return *this;
        }

        String JString::getFormattedData(){
            return String("\"") + this->jString + "\"";
        }
        String JString::getFormattedData(int &i){
            return String("\"") + this->jString + "\"";
        }
        String JString::getStringData(){
            return this->jString;
        }
        int JString::getIntegerData(){
            return atoi(this->jString);
        }
        double JString::getDoubleData(){
            return atof(this->jString);
        }
        bool JString::getBoolData(){
            return this->jString == "true";
        }
        JElementType::Type JString::getType(){
            return JElementType::JString;
        }


        JInteger::JInteger() = default;
        JInteger::JInteger(int i){
            this->jInteger = i;
        }
        JInteger::JInteger(const JInteger& jInteger1){
            this->jInteger = jInteger1.jInteger;
        }
        JInteger& JInteger::operator =(int i){
            this->jInteger = i;
            return *this;
        }

        String JInteger::getFormattedData(){
            return String(std::to_string(this->jInteger).data());
        }
        String JInteger::getFormattedData(int &i){
            return String(std::to_string(this->jInteger).data());
        }
        String JInteger::getStringData(){
            return String(std::to_string(this->jInteger).data());
        }
        int JInteger::getIntegerData(){
            return this->jInteger;
        }
        double JInteger::getDoubleData(){
            return this->jInteger;
        }
        bool JInteger::getBoolData(){
            return this->jInteger;
        }
        JElementType::Type JInteger::getType(){
            return JElementType::JInteger;
        }


        JDouble::JDouble() = default;
        JDouble::JDouble(double d){
            this->jDouble = d;
        }
        JDouble::JDouble(const JDouble& jDouble1){
            this->jDouble = jDouble1.jDouble;
        }
        JDouble& JDouble::operator=(double d){
            this->jDouble = d;
            return *this;
        }

        String JDouble::getFormattedData(){
            return String(std::to_string(this->jDouble).data());
        }
        String JDouble::getFormattedData(int &i){
            return String(std::to_string(this->jDouble).data());
        }
        String JDouble::getStringData(){
            return String(std::to_string(this->jDouble).data());
        }
        int JDouble::getIntegerData(){
            return this->jDouble;
        }
        double JDouble::getDoubleData(){
            return this->jDouble;
        }
        bool JDouble::getBoolData(){
            return this->jDouble;
        }
        JElementType::Type JDouble::getType(){
            return JElementType::JDouble;
        }


        JBool::JBool() = default;
        JBool::JBool(bool b){
            this->jBool = b;
        }
        JBool::JBool(const JBool& jBool1){
            this->jBool = jBool1.jBool;
        }
        JBool& JBool::operator =(bool b){
            this->jBool = b;
            return *this;
        }

        String JBool::getFormattedData(){
            return (this->jBool ? "true" : "false");
        }
        String JBool::getFormattedData(int &i){
            return (this->jBool ? "true" : "false");
        }
        String JBool::getStringData(){
            return (this->jBool ? "true" : "false");
        }
        int JBool::getIntegerData(){
            return this->jBool;
        }
        double JBool::getDoubleData(){
            return this->jBool;
        }
        bool JBool::getBoolData(){
            return this->jBool;
        }
        JElementType::Type JBool::getType(){
            return JElementType::JBool;
        }


        JRecord::JRecord(){

        }
        JRecord::JRecord(Map<String, JElement> r){
            this->jRecord.Clear();
            for(auto e: r)
                this->jRecord[e.x] = (Pointer<IJElement>)e.y;
        }
        JRecord::JRecord(const JRecord& jRecord1){
            this->jRecord = jRecord1.jRecord;
        }
        JRecord& JRecord::operator =(const JRecord& jRecord1){
            this->jRecord = jRecord1.jRecord;
            return *this;
        }
        JRecord& JRecord::operator =(Map<String, JElement> r){
            this->jRecord.Clear();
            for(auto e: r)
                this->jRecord[e.x] = (Pointer<IJElement>)e.y;
            return *this;
        }

        String JRecord::getFormattedData() {
            int i = 1;
            String s = "{";
            bool first = true;
            for(auto& e: this->jRecord){
                if(first) first = false;
                else s += ",";

                s += "\n";

                for(int j = 0; j < i; j++) s += "\t";

                s += String("\"") + e.x + "\"" + ": " + ((IJElement*)e.y)->getFormattedData(i);
            }
            s += "\n}";
            return s;
        }
        String JRecord::getFormattedData(int &i) {
            String s = "{";
            bool first = true;
            i++;
            for(auto& e: this->jRecord){
                if(first) first = false;
                else s += ",";

                s += "\n";

                for(int j = 0; j < i; j++) s += "\t";

                s += String("\"") + e.x + "\"" + ": " + ((IJElement*)e.y)->getFormattedData(i);
            }
            i--;
            s += "\n";
            for(int j = 0; j < i; j++) s += "\t";
            s += "}";
            return s;
        }
        String JRecord::getStringData(){
            return this->getFormattedData();
        }
        int JRecord::getIntegerData(){
            return 0;
        }
        double JRecord::getDoubleData(){
            return 0;
        }
        bool JRecord::getBoolData(){
            return 0;
        }
        JElementType::Type JRecord::getType(){
            return JElementType::JRecord;
        }
        Pair<String, Pointer<IJElement>>* JRecord::begin(){
            return this->jRecord.begin();
        }
        Pair<String, Pointer<IJElement>>* JRecord::end(){
            return this->jRecord.end();
        }


        JArray::JArray(){}
        JArray::JArray(Vector<JElement> a){
            this->jArray.Clear();

            for(auto e: a)
                this->jArray.Push_Back((Pointer<IJElement>)e);

        }
        JArray::JArray(const JArray& jArray1){
            this->jArray.Clear();
            this->jArray = jArray1.jArray;
        }
        JArray& JArray::operator =(Vector<JElement> a){
            this->jArray.Clear();

            for(auto e: a)
                this->jArray.Push_Back((Pointer<IJElement>)e);

            return *this;
        }

        String JArray::getFormattedData(){
            int i = 1;
            String s = "[";
            bool first = true;
            for(auto e: this->jArray){
                if(first) first = false;
                else s += ",";

                s += "\n";

                for(int j = 0; j < i; j++) s += "\t";

                s += (*e).getFormattedData(i);
            }
            s += "\n]";
            return s;
        }
        String JArray::getFormattedData(int &i){
            String s = "[";
            bool first = true;
            i++;
            for(auto e: this->jArray){
                if(first) first = false;
                else s += ",";

                s += "\n";

                for(int j = 0; j < i; j++) s += "\t";

                s += (*e).getFormattedData(i);
            }
            i--;
            s += "\n";
            for(int j = 0; j < i; j++) s += "\t";
            s += "]";
            return s;
        }
        String JArray::getStringData(){
            return this->getFormattedData();
        }
        int JArray::getIntegerData(){
            return 0;
        }
        double JArray::getDoubleData(){
            return 0;
        }
        bool JArray::getBoolData(){
            return false;
        }
        JElementType::Type JArray::getType(){
            return JElementType::JArray;
        }

        JElement::JElement() = default;
        JElement::JElement(String str){
            this->ptr = new JString();
            ((JString&)*this->ptr) = std::move(str);
        }
        JElement::JElement(const char* str){
            this->ptr = new JString();
            ((JString&)*this->ptr) = str;
        }
        JElement::JElement(int i){
            this->ptr = new JInteger;
            ((JInteger&)*this->ptr) = i;
        }
        JElement::JElement(double d){
            this->ptr = new JDouble;
            ((JDouble&)*this->ptr) = d;
        }
        JElement::JElement(bool b){
            this->ptr = new JBool;
            ((JBool&)*this->ptr) = b;
        }
        JElement::JElement(Map<String, JElement> jRecord){
            this->ptr = new JRecord;
            ((JRecord&)*this->ptr) = std::move(jRecord);
        }
        JElement::JElement(Vector<JElement> jArray){
            this->ptr = new JArray;
            ((JArray&)*this->ptr) = std::move(jArray);
        }
        JElement::JElement(Pointer<IJElement> ijElement1){
            this->ptr = std::move(ijElement1);
        }
        JElement::JElement(const JElement& jElement){
            this->ptr = jElement.ptr;
        }
        JElement::JElement(JElement&& jElement){
            this->ptr = jElement.ptr;
        }

        void JElement::setType(JElementType::Type type){
            switch (type) {
                case JElementType::JString:
                    this->ptr = new JString();
                    break;
                case JElementType::JInteger:
                    this->ptr = new JInteger();
                    break;
                case JElementType::JDouble:
                    this->ptr = new JDouble();
                    break;
                case JElementType::JBool:
                    this->ptr = new JDouble();
                    break;
                case JElementType::JRecord:
                    this->ptr = new JRecord();
                    break;
                case JElementType::JArray:
                    this->ptr = new JArray();
                    break;
                default:
                    fprintf(stderr, "Error: Invalid RTL::Types::JElementType value in JElement::setType()");
                    throw -11;
            }
        }

        JElement& JElement::operator=(String str){
            this->ptr = new JString();
            ((JString&)*this->ptr) = std::move(str);
            return *this;
        }
        JElement& JElement::operator=(int i){
            this->ptr = new JInteger();
            ((JInteger&)*this->ptr) = i;
            return *this;
        }
        JElement& JElement::operator=(double d){
            this->ptr = new JDouble();
            ((JDouble&)*this->ptr) = d;
            return *this;
        }
        JElement& JElement::operator=(bool b){
            this->ptr = new JBool();
            ((JBool&)*this->ptr) = b;
            return *this;
        }
        JElement& JElement::operator=(Map<String, JElement> jRecord){
            this->ptr = new JRecord();
            ((JRecord&)*this->ptr) = std::move(jRecord);
            return *this;
        }
        JElement& JElement::operator=(Vector<JElement> jArray){
            this->ptr = new JArray();
            ((JArray&)*this->ptr) = std::move(jArray);
            return *this;
        }
        JElement& JElement::operator=(Vector<Pair<JElement, JElement>> jArray){
            Map<String, JElement> tmp;
            for(auto jRecord: jArray){
                if((*jRecord.x.ptr).getType() == JElementType::JRecord || (*jRecord.x.ptr).getType() == JElementType::JArray){
                    return *this;
                }
                tmp[jRecord.x] = jRecord.y;
            }
            *this = tmp;
            return *this;
        }
        JElement& JElement::operator=(IJElement* ijElement1){
            this->ptr = ijElement1;
            return *this;
        }
        JElement& JElement::operator=(const JElement& jElement){
            this->ptr = jElement.ptr;
            return *this;
        }
        JElement& JElement::operator=(JElement&& jElement){
            this->ptr = jElement.ptr;
            jElement.ptr = nullptr;
            return *this;
        }

        void JElement::operator()(String str){
            *this = std::move(str);
        }
        void JElement::operator()(int i) {
            *this = i;
        }
        void JElement::operator()(double d){
            *this = d;
        }
        void JElement::operator()(bool b){
            *this = b;
        }
        void JElement::operator()(Map<String, JElement> jRecord) {
            *this = std::move(jRecord);
        }
        void JElement::operator()(Vector<JElement> jArray){
            *this = std::move(jArray);
        }
        void JElement::operator()(Pointer<IJElement> ijElement1){
            *this = (IJElement*)ijElement1;
        }
        void JElement::operator()(const JElement& jElement){
            *this = jElement;
        }
        void JElement::operator()(JElement&& jElement){
            *this = jElement;
        }

        JElement JElement::operator[](const String& str){
            if (!this->ptr.isEmpty()) {
                if ((*this->ptr).getType() == JElementType::JRecord)
                    return ((*((JRecord *) (IJElement *) this->ptr)).jRecord[str]);
                if ((*this->ptr).getType() == JElementType::JArray)
                    return (*((JArray *) (IJElement *) this->ptr)).jArray[atoi(str)];
            }

            this->setType(JElementType::JRecord);
            return (*((JRecord*)(IJElement*)this->ptr)).jRecord[str];
        }
        JElement JElement::operator[](const char* str){
            if (!this->ptr.isEmpty()){
                if(((IJElement*)this->ptr)->getType() == JElementType::JRecord)
                    return (*((JRecord*)(IJElement*)this->ptr)).jRecord[str];
                if((*this->ptr).getType() == JElementType::JArray)
                    return (*((JArray*)(IJElement*)this->ptr)).jArray[atoi(str)];
            }

            this->setType(JElementType::JRecord);
            return (*((JRecord*)(IJElement*)this->ptr)).jRecord[str];
        }
        JElement JElement::operator[](int i){
            if (!this->ptr.isEmpty()) {
                if ((*this->ptr).getType() == JElementType::JRecord)
                    return (*((JRecord *) (IJElement *) this->ptr)).jRecord[std::to_string(i).data()];
                if ((*this->ptr).getType() == JElementType::JArray)
                    return (*((JArray *) (IJElement *) this->ptr)).jArray[i];
            }

            this->setType(JElementType::JArray);
            return (*((JArray*)(IJElement*)this->ptr)).jArray[i];
        }
        JElement JElement::operator[](JElement jElement){
            if (!this->ptr.isEmpty()) {
                if ((*this->ptr).getType() == JElementType::JRecord)
                    return (*((JRecord *) (IJElement *) this->ptr)).jRecord[jElement];
                if ((*this->ptr).getType() == JElementType::JArray)
                    return (*((JArray *) (IJElement *) this->ptr)).jArray[(int) jElement];
            }

            if(!jElement.ptr.isEmpty()){
                switch((*jElement.ptr).getType()){
                    case JElementType::JString:
                        this->setType(JElementType::JRecord);
                        return (*((JRecord*)(IJElement*)this->ptr)).jRecord[jElement];

                    case JElementType::JInteger:
                        this->setType(JElementType::JArray);
                        return (*((JArray*)(IJElement*)this->ptr)).jArray[(int)jElement];

                    case JElementType::JDouble:
                        this->setType(JElementType::JArray);
                        return (*((JArray*)(IJElement*)this->ptr)).jArray[(int)jElement];

                    case JElementType::JBool:
                        // Error
                        break;
                    case JElementType::JRecord:
                        // Error
                        break;
                    case JElementType::JArray:
                        // Error
                        break;
                }
            }
            exit(-1);
        }

        JElement::operator String(){
            return ((IJElement*)this->ptr)->getStringData();
        }
        JElement::operator int(){
            return ((IJElement*)this->ptr)->getIntegerData();
        }
        JElement::operator double() {
            return ((IJElement*)this->ptr)->getDoubleData();
        }
        JElement::operator bool() {
            return ((IJElement*)this->ptr)->getBoolData();
        }
        JElement::operator Map<String, JElement>(){
            if((*this->ptr).getType() == JElementType::JRecord){
                Map<String, JElement> ret;
                for(const auto& e: (*((JRecord*)(IJElement*)this->ptr)).jRecord)
                    ret[e.x] = JElement(e.y);
                return ret;
            }
            return Map<String, JElement>();
        }
        JElement::operator Vector<JElement>(){
            if((*this->ptr).getType() == JElementType::JArray){
                Vector<JElement> ret;
                for(const auto& e: (*((JArray*)(IJElement*)this->ptr)).jArray)
                    ret.Push_Back(e);
                return ret;
            }
            return Vector<JElement>();
        }

        JElement::operator Pointer<IJElement>(){
            return this->ptr;
        }

        JElement::~JElement() = default;
    }
}