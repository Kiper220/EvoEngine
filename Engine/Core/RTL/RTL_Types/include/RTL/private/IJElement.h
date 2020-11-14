//
// Created by kiper220 on 17.08.2020.
//

#ifndef GAME_IJELEMENT_H
#define GAME_IJELEMENT_H

#include <RTL/Pointer.h>
#include <RTL/String.h>
#include <RTL/Map.h>

namespace RTL{
    namespace Types{

        namespace JElementType{
            enum Type{
                JString,
                JInteger,
                JDouble,
                JBool,
                JRecord,
                JArray
            };
        }
#if not defined(PRIVATE)
        class IJElement;
        class JString;
        class JInteger;
        class JDouble;
        class JBool;
        class JRecord;
        class JArray;
#else
        class JElement;
        class IJElement {
        public:
            virtual String getFormattedData() = 0;
            virtual String getFormattedData(int &i) = 0;
            virtual String getStringData() = 0;
            virtual int getIntegerData() = 0;
            virtual double getDoubleData() = 0;
            virtual bool getBoolData() = 0;
            virtual JElementType::Type getType() = 0;
            virtual ~IJElement() = default;
        };
        class JString : public IJElement{
        public:
            JString();
            JString(String s);
            JString(const JString& jString1);
            JString& operator =(String s);

            String getFormattedData() override;
            String getFormattedData(int &i) override;
            String getStringData() override;
            int getIntegerData() override;
            double getDoubleData() override;
            bool getBoolData() override;
            JElementType::Type getType() override;

            friend class JElement;
        private:
            String jString;
        };
        class JInteger : public IJElement{
        public:
            JInteger();
            JInteger(int i);
            JInteger(const JInteger& jInteger1);
            JInteger& operator =(int i);

            String getFormattedData() override;
            String getFormattedData(int &i) override;
            String getStringData() override;
            int getIntegerData() override;
            double getDoubleData() override;
            bool getBoolData() override;
            JElementType::Type getType() override;

            friend class JElement;
        private:
            int jInteger = 0;
        };
        class JDouble : public IJElement{
        public:
            JDouble();
            JDouble(double d);
            JDouble(const JDouble& jDouble1);
            JDouble& operator =(double d);

            String getFormattedData() override;
            String getFormattedData(int &i) override;
            String getStringData() override;
            int getIntegerData() override;
            double getDoubleData() override;
            bool getBoolData() override;
            JElementType::Type getType() override;

            friend class JElement;
        private:
            double jDouble = 0;
        };
        class JBool : public IJElement{
        public:
            JBool();
            JBool(bool b);
            JBool(const JBool& jBool1);
            JBool& operator =(bool b);

            String getFormattedData() override;
            String getFormattedData(int &i) override;
            String getStringData() override;
            int getIntegerData() override;
            double getDoubleData() override;
            bool getBoolData() override;
            JElementType::Type getType() override;

            friend class JElement;
        private:
            bool jBool = false;
        };
        class JRecord : public IJElement{
        public:
            JRecord();
            JRecord(Map<String, JElement> r);
            JRecord(const JRecord& jRecord1);
            JRecord& operator =(const JRecord& jRecord1);
            JRecord& operator =(Map<String, JElement> r);

            String getFormattedData() override;
            String getFormattedData(int &i) override;
            String getStringData() override;
            int getIntegerData() override;
            double getDoubleData() override;
            bool getBoolData() override;
            JElementType::Type getType() override;
            Pair<String, Pointer<IJElement>>* begin();
            Pair<String, Pointer<IJElement>>* end();

            friend class JElement;
        private:
            Map<String, Pointer<IJElement>> jRecord;
        };
        class JArray : public IJElement{
        public:
            JArray();
            JArray(Vector<JElement> a);
            JArray(const JArray& jArray1);
            JArray& operator =(Vector<JElement> a);

            String getFormattedData() override;
            String getFormattedData(int &i) override;
            String getStringData() override;
            int getIntegerData() override;
            double getDoubleData() override;
            bool getBoolData() override;
            JElementType::Type getType() override;

            friend class JElement;
        private:
            Vector<Pointer<IJElement>> jArray;
        };
#endif
    }
}

#endif //GAME_IJELEMENT_H
