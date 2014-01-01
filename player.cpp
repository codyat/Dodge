#include "player.h"

Player::Player()
:x(25), y(1)
{
    body = Circle(Point(x,y), 1, DARK_GREEN, true);
}

void Player::move()
{
    Point p1 = body.get_center();
    Point p2 = p1;
    if ( win.is_key_down("up") && y < 62 )
    {
        y++;
        p2 = Point(x,y);
    }
    else if ( win.is_key_down("down") && y > 1 )
    {
        y--;
        p2 = Point(x,y);
    }
    else if ( win.is_key_down("left") && x > 1 )
    {
        x--;
        p2 = Point(x,y);
    }
    else if ( win.is_key_down("right") && x < 49 )
    {
        x++;
        p2 = Point(x,y);
    }
    body = Circle(p2, 1, DARK_GREEN, true);
    win << body;
}
bool Player::check_for_kill(Bird b)
{
    double x,y,z;
    x = b.c.get_center().get_x() - body.get_center().get_x();
    y = b.c.get_center().get_y() - body.get_center().get_y();
    z = sqrt( x*x + y*y );
    if( z <= 2*b.c.get_radius() ) return true;

    else return false;
}
