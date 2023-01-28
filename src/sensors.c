#include <kipr/botball.h>
#include "constants.h"

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