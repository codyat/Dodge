#ifndef PLAYER_H
#define PLAYER_H
#include "bird.h"
#include <cmath>
#include <vector.h>

class Player
{
    private:
        int x;
        int y;
        Circle body;
    public:
        Player();
        void move();
        bool check_for_kill(Bird b);
};

#endif // PLAYER_H
