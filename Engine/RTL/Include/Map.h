//
// Created by kiper220 on 23.05.2020.
//

#ifndef GAME_MAP_H
#define GAME_MAP_H

#include <Vector.h>
#include <Pair.h>

namespace RTL{
     /**
     *
     * \brief Red Template Library Map
     * \authors WetGrape | Kiper220
     * \copyright GNU LGPL
     *
     **/
    template<typename key, typename value>
    class Map{
    public:
        /**
         * \brief Standart zero constructor
         */
        Map() = default;
        /**
         * \brief Standart copy constructor
         */
        Map(const Map& map): Data(map._Data){}
        /**
         * \brief Standart move constructor
         */
        Map(const Map&& map): Data(std::move(map._Data)){}
        /**
         * \brief Standart copy constructor
         */
        Map(const Vector<Pair<key, value>>& _data): Data(_data){}
        /**
         * \brief Standart move constructor
         */
        Map(const Vector<Pair<key, value>>&& _data): Data(std::move(_data)){}

        /**
         * \brief Map overload copy operator
         */
        Map& operator = (const Map& map){
            Data = map._Data;
        };
        /**
         * \brief Map overload copy operator
         */
        Map& operator = (const Vector<Pair<key, value>>& _data){
            Data = _data;
        };

        /**
         * \brief Map overload operator[](key)
         * \arg _Key - key to get value reference
         */
        value& operator[](key _Key) {
            if (Data.size() == 0) {
                Data.push_back(Pair<key, value>());
                Data[0].x = _Key;
                return Data[0].y;
            } else if (Data.size() == 1) {
                if (Data[0].x == _Key)
                    return Data[0].y;
                else {
                    if (Data[0].x < _Key) {
                        Data.insert(Pair<key, value>(), 1);
                        Data[1].x = _Key;
                        return Data[1].y;
                    } else {
                        Data.insert(Pair<key, value>(), 0);
                        Data[0].x = _Key;
                        return Data[0].y;
                    }
                }
            } else if (Data.size() == 2) {
                if (Data[0].x == _Key)
                    return Data[0].y;
                if (Data[1].x == _Key)
                    return Data[0].y;

                if(Data[0].x > _Key) {
                    Data.insert(Pair<key, value>(), 0);
                    Data[0].x = _Key;
                    return Data[0].y;
                }
                else if (Data[0].x < _Key) {
                    if (Data[1].x > _Key) {
                        Data.insert(Pair<key, value>(), 1);
                        Data[1].x = _Key;
                        return Data[1].y;
                    } else {
                        Data.insert(Pair<key, value>(), 2);
                        Data[2].x = _Key;
                        return Data[2].y;
                    }
                }
            } else {
                size_t l = 0, r = Data.size(), p = (l + r) / 2;

                if (Data[l].x == _Key)
                    return Data[l].y;
                if (Data[r].x == _Key)
                    return Data[r].y;
                if (Data[p].x == _Key)
                    return Data[p].y;

                while (true) {
                    if (Data[p].x == _Key)
                        return Data[p].y;

                    else if (Data[p].x > _Key)
                        r = p;
                    else l = p;

                    p = (l + r) / 2;
                    if (p == l || p == r)
                        break;
                }
                if (Data[p].x < _Key) {
                    Data.insert(Pair<key, value>(), p + 1);
                    Data[p + 1].x = _Key;
                    return Data[p + 1].y;
                }else{
                    Data.insert(Pair<key, value>(), p);
                    Data[p].x = _Key;
                    return Data[p].y;
                }
            }
        }

        /**
         * \brief Map is empty function
         */
        bool IsEmpty(){
            return this->Data.IsEmpty();
        }
        /**
         * \brief Map clear function
         */
        void Clear(){
            this->Data.Clear();
        }
    private:
        Vector<Pair<key, value>> Data;
    };
}

#endif //GAME_MAP_H
