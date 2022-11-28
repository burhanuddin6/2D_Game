#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "drawing.hpp"
using namespace std;
class Object
{
    protected:
    SDL_Rect moverRect;
    SDL_Rect obj_source;
    public:
    Object(int x = 50, int y = 50, int h = 50, int w = 50)
    {
        // a square object by default
        moverRect = {x,y,h,w};
    }
    virtual void draw()
    {
        SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &obj_source, &moverRect);
    }
};

class Foo : public Object
{};

class Player : public Object
{
    string state;
    int x_move, y_move;
    bool JUMP = false;
    int JUMP_COUNT = 0;
    public:
    Player(int x=50, int y=50, int h=50, int w=50) : Object{x,y,h,w}
    {
        state = "DEFAULT";
        x_move = 0;
        y_move = 0;
        obj_source = Drawing::JumpKing->at(state);
    }
    void move(int x = 0, int y = 0)
    {
        if (JUMP == true and JUMP_COUNT < 5)
        {
            y_move = 5;
            JUMP_COUNT++;
        }
        else if (JUMP == true && JUMP_COUNT < 10)
        {
            y_move = -5;
            JUMP_COUNT++;
        }
        else if (JUMP == true)
        {
            JUMP = false;
            JUMP_COUNT = 0;
            y = 0;
        }
        if (JUMP == false & y > 0)
        {
            JUMP = true;
            JUMP_COUNT = 0;
        }
        y_move = y;
        x_move = x; 
        if (moverRect.x + x_move >= SCREEN_WIDTH|| moverRect.x <= 1)
        {
            x_move = 0;
        }
        if (moverRect.y + y_move >= SCREEN_HEIGHT || moverRect.y <= 1)
        {
            y_move = 0;
            JUMP = false;
            JUMP_COUNT = 0;
        }
    }
    void draw()
    {
        if (x_move < 0 && y_move == 0)
        {
            if (state.compare("DEFAULT") == 0)
            {
                state = "LEFT";
            }
            else if (state.compare("LEFT") == 0)
            {
                state = "LEFT_RUN";
                cout << "HELLO";
            }
            else
            {
                state = "LEFT";
            }
        }
        else if (x_move > 0 && y_move == 0)
        {
            if (state.compare("DEFAULT") == 0)
            {
                state = "RIGHT";
            }
            else if (state.compare("RIGHT") == 0)
            {
                state = "RIGHT_RUN";
            }
            else
            {
                state = "RIGHT";
            }
        }
        else if (x_move == 0 && y_move > 0)
        {
            state = "DOWN";
        }
        else if (x_move > 0 && y_move > 0)
        {
            state = "UP_RIGHT";
        }
        else if (x_move < 0 && y_move > 0)
        {
            state = "UP_LEFT";
        }
        else if (x_move == 0 && y_move < 0)
        {
            state = "UP";
        }
        else if (x_move > 0 && y_move < 0)
        {
            state = "DOWN_RIGHT";
        }
        else if (x_move < 0 && y_move < 0)
        {
            state = "DOWN_LEFT";
        }
        else
        {
            state = "DEFAULT";
        }
        moverRect.x += x_move;
        moverRect.y += y_move;
        std::cout << state << std::endl;
        std::cout << "x: " << moverRect.x << endl;
        std:: cout << "y: " << moverRect.y << endl;
        obj_source = Drawing::JumpKing->at(state);
        Object::draw();
    }
};