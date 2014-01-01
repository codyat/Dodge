#include "bird.h"

Bird::Bird()
:x_add(true), y_add(false)
{
    time(&t);
    srand(t);
    Point p = get_random_number();
    c = Circle(p,1,WHITE, true);
}

bool Bird::check_bottom()
{
    return ( c.get_center().get_y() - c.get_radius() > 0);
}
bool Bird::check_left()
{
    return ( c.get_center().get_x() - c.get_radius() > 0 );
}
bool Bird::check_right()
{
    return ( c.get_center().get_x() + c.get_radius() < 50 );
}
bool Bird::check_top()
{
    return ( c.get_center().get_y() + c.get_radius() < 63 );
}
void Bird::move()
{
    if (!check_bottom() &&  x_add ) y_add = true;
    if (!check_bottom() && !x_add ) y_add = true;
    if (!check_top()    &&  x_add ) y_add = false;
    if (!check_top()    && !x_add ) y_add = false;
    if (!check_left()   &&  y_add ) x_add = true;
    if (!check_left()   && !y_add ) x_add = true;
    if (!check_right()  &&  y_add ) x_add = false;
    if (!check_right()  && !y_add ) x_add = false;

    if (  y_add ) y++;
    if ( !y_add ) y--;
    if (  x_add ) x++;
    if ( !x_add ) x--;

    c = Circle(Point(x,y),1, WHITE, true);
    win<<c;
}
Point Bird::get_random_number()
{
    Point temp;

    x = rand()%48+1;
    y = ((rand()/3)%61+1);
    if( (rand()/5)%2 ) x_add = false;
    if( (rand()/7)%2 ) y_add = true;
    temp = Point(x,y);
    return temp;
}
