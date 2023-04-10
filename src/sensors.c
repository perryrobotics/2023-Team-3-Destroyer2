#include <kipr/botball.h>
#include "constants.h"


void forward_to_touch(int speed, int port)
{
    mav(LM, speed);
    mav(RM, speed);

    while (digital(port) == NOT_TOUCHED)
    {
    }
    mav(LM, 0);
    mav(RM, 0);
}
void forward_to_black(int speed, int port)
{
    mav(LM, speed);
    mav(RM, speed);

    while (analog(port) < BLACK)
    {
    }
    mav(LM, 0);
    mav(RM, 0);
}

void back_to_black(int speed, int port)
{
    mav(LM, -speed);
    mav(RM, -speed);

    while (analog(port) < BLACK)
    {
    }
    mav(LM, 0);
    mav(RM, 0);
}


void left_to_black(int speed, int port)
{
    mav(LM, -speed);
    mav(RM, speed);

    while (analog(port) < BLACK)
    {
    }
    mav(LM, 0);
    mav(RM, 0);
}


void right_to_black(int speed, int port)
{
    mav(LM, speed);
    mav(RM, -speed);

    while (analog(port) < BLACK)
    {
    }
    mav(LM, 0);
    mav(RM, 0);
}

void right_to_white(int speed, int port)
{
    mav(LM, speed);
    mav(RM, -speed);

    while (analog(port) > BLACK)
    {
    }
    mav(LM, 0);
    mav(RM, 0);
}

void forward_for_black(int speed, int port, int amount)
{
    int i;
    for(i = 0; i < amount; i++)
    {
        forward_to_black(speed, port);
        while (analog(port) >= BLACK)
        {
        }
    }
    mav(LM, 0);
    mav(RM, 0);
}

void follow_to_black(int speed, int port1, int port2)
{

    while(analog(port2) < BLACK)
    {

        if(analog(port1) > BLACK)// over black
        {
            mav(LM, speed+200);
            mav(RM, speed - 200);
        }
        else
        {
            mav(RM, speed+400);
            mav(LM, speed - 400);
        }

    }
    mav(LM, 0);
    mav(RM, 0);
}
void follow_to_ticks(int speed, int port1, int ticks)
{
    cmpc(LM);
    cmpc(RM);
    while(gmpc(RM) < ticks)
    {

        if(analog(port1) > BLACK)
        {
            mav(LM, speed+200);
            mav(RM, speed - 200);
        }
        else
        {
            mav(RM, speed+200);
            mav(LM, speed - 200);
        }
    }
    mav(LM, 0);
    mav(RM, 0);
}

void follow_to_touch(int speed, int port1, int touch_port)
{

    while(digital(touch_port) == NOT_TOUCHED )
    {

        if(analog(port1) > BLACK)
        {
            mav(LM, speed+200);
            mav(RM, speed - 200);
        }
        else
        {
            mav(RM, speed+200);
            mav(LM, speed - 200);
        }
    }
    mav(LM, 0);
    mav(RM, 0);
}