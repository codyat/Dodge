///////////////////////////////////////////////////////////////////////////////
//
// Name:  Cody Troyer
// Email: codyatroyer@yahoo.com
//
// This is entirely my own genuine code.
//
///////////////////////////////////////////////////////////////////////////////
#include "bird.h"
#include "player.h"

using namespace std;

string itos( int );
int apow( const int &, int );
string digit2str( short );
int get_level();
bool is_in(Point, Rect);
bool play_again();

int instinct_main()
{
    win.set_window_size(650, 650);
    do
    {
        win.coord(0,0,50,63);
        win.set_background_color(BLACK);
        win.clear_buffer();
        int level = get_level();
        win.clear_buffer();
        Player p1;
        vector<Bird> birds;
        Bird* b = new Bird;
        birds.push_back(*b);
        unsigned int i;
        bool play = true;
        Timer t;
        Timer score;
        t.start();
        score.start();
        while (true)
        {
            wait_for(5*level);
            win.clear_buffer();
            if( t.get_time() >= 3500)
            {
                b = new Bird;
                birds.push_back(*b);
                t.reset();
            }
            for( i = 0; i < birds.size(); i++ )
            {
                if ( p1.check_for_kill(birds[i]) )
                {
                    play = false;
                    break;
                }
                birds[i].move();
            }
            if (!play) break;
            p1.move();
            win.output_buffer();
        }
        string s = itos(score.get_time()/1000) + " seconds";
        Message m = Message(Point(20, 50), s, YELLOW);
        win << m;
        win.output_buffer();


        delete b;
    }while(play_again());
    return 0;
}

int get_level()
{
    Message *m = new Message(Point (17, 50), "Choose a difficulty", WHITE);
    win << *m;
    m = new Message(Point (8, 32.5), "Easy", WHITE);
    win << *m;
    m = new Message(Point (22.5, 32.5), "Medium", WHITE);
    win << *m;
    m = new Message(Point (38, 32.5), "Hard", WHITE);
    win << *m;

    Rect e_r = Rect(Point(5, 30), 10, 6, GREEN);
    win << e_r;
    Rect m_r = Rect(Point(20, 30), 10, 6, YELLOW);
    win << m_r;
    Rect h_r = Rect(Point(35, 30), 10, 6, RED);
    win << h_r;

    win.output_buffer();

    Point p;
    while(true)
    {
        if(win.left_mouse_down())
        {
            p = win.get_mouse_loc();
            if( is_in( p, e_r) ) return 20;
            else if( is_in( p, m_r) ) return 14;
            else if( is_in( p, h_r) ) return 8;
        }
    }
    delete m;
}

bool play_again()
{
    Rect r = Rect(Point(20, 20), 10, 6, WHITE);
    win << r;
    Message m = Message(Point(20.5 ,22.5), "play again", WHITE);
    win << m;
    win.output_buffer();

    while(true)
        if(win.left_mouse_down()) return true;
}

bool is_in(Point p, Rect r)
{
    if( p.get_x() > r.get_lower_left().get_x() &&
        p.get_x() < r.get_lower_left().get_x() + r.get_width() &&
        p.get_y() > r.get_lower_left().get_y() &&
        p.get_y() < r.get_lower_left().get_y() + r.get_height() ) return true;
    else
        return false;
}

string itos(int a)
{
    /* Convert an integer to a string */
    int b = 0, c = 1, n = 0;
    string result;
    while(apow(10,n) < a) n++;

    if(n != 0) n--;
    b = apow(10,n);
    while((b*c) < a) c++;
    if(n != 0) c--;
    a -= (b*c);
    result += digit2str(c);
    if(n != 0) result += itos(a);
    return result;
}

int apow(const int &x, int y)
{
    /* Raise x to the power of y */
    int result = 1;
    if(y < 0)
	return apow(1/x, -y);
    for(int i = y; i > 0; i--)
	result *= x;
    return result;
}

string digit2str(short digit)
{
    /* Convert a digit to a string */
    string tmp;
    if(digit >= 0 && digit <= 9)
    {
        tmp = digit + '0';
        return tmp;
    }
    return "";
}
