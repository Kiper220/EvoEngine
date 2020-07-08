//
// Created by kiper220 on 23.05.2020.
//

#ifndef GAME_PAIR_H
#define GAME_PAIR_H

namespace RTL::Types{
    template<typename _x, typename _y>
    class Pair{
        typedef struct{_x uX; _y uY;} t_Pair;
    public:
        Pair() {}
        Pair(const Pair<_x, _y>& pair) {
            this->x = pair.x;
            this->y = pair.y;
        }
        Pair(_x uX, _y uY) {
            this->x = uX;
            this->y = uY;
        }

        Pair& operator =(const Pair<_x, _y> pair) {
            this->x = pair.x;
            this->y = pair.y;
        }
        Pair& operator =(t_Pair pair) {
            this->x = pair.x;
            this->y = pair.y;
        }

        _x x;
        _y y;
    };
}

#endif //GAME_PAIR_H
