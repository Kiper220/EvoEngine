//
// Created by kiper220 on 17.08.2020.
//

#ifndef GAME_IJELEMENT_H
#define GAME_IJELEMENT_H

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

        class IJElement {
        public:
            virtual String getFormattedData() = 0;
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
            void operator =(String s);

            String getFormattedData() override;
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
            void operator =(int i);

            String getFormattedData() override;
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
            void operator =(double d);

            String getFormattedData() override;
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
            void operator =(bool b);

            String getFormattedData() override;
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
            JRecord(Map<String, IJElement*> r);
            JRecord(const JRecord& jRecord1);
            void operator =(Map<String, IJElement*> r);

            String getFormattedData() override;
            String getStringData() override;
            int getIntegerData() override;
            double getDoubleData() override;
            bool getBoolData() override;
            JElementType::Type getType() override;
            Pair<String, IJElement*>* begin();
            Pair<String, IJElement*>* end();

            friend class JElement;
        private:
            Map<String, IJElement*> jRecord;
        };
        class JArray : public IJElement{
        public:
            JArray();
            JArray(Vector<IJElement*> a);
            JArray(const JArray& jArray1);
            void operator =(Vector<IJElement*> a);

            String getFormattedData() override;
            String getStringData() override;
            int getIntegerData() override;
            double getDoubleData() override;
            bool getBoolData() override;
            JElementType::Type getType() override;

            friend class JElement;
        private:
            Vector<IJElement*> jArray;
        };
#endif
    }
}

#endif //GAME_IJELEMENT_H
