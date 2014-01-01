#ifndef BIRD_H
#define BIRD_H

#include "instinct.h"

class Bird
{
    private:
        int x;
        int y;
        bool x_add;
        bool y_add;
        bool check_bottom();
        bool check_left();
        bool check_right();
        bool check_top();
        Point get_random_number();
        long t;
    public:
        Circle c;
        Bird();
        void move();
};

#endif // BIRD_H
