#include "constants.h"
#include <kipr/botball.h>

void forward(int speed, int ticks)
{
    msleep(100);
    cmpc(LM);
    cmpc(RM);
    msleep(100);
    mav(LM,speed);
    mav(RM,speed);
    while(gmpc(LM) < ticks)
    {
    }
    mav(LM,0);
    mav(RM,0);
    msleep(100);
}


void backward(int speed, int ticks)
{
    msleep(100);
    cmpc(LM);
    cmpc(RM);
    msleep(100);
    mav(LM,-speed);
    mav(RM,-speed);
    while(gmpc(LM) > -ticks)
    {
    }
    mav(LM,0);
    mav(RM,0);
    msleep(100);
}

void left(int speed, int ticks)
{
    msleep(100);
    cmpc(LM);
    cmpc(RM);
    msleep(100);
    mav(LM,-speed);
    mav(RM,speed);
    while(gmpc(LM) > -ticks)
    {
    }
    mav(LM,0);
    mav(RM,0);
    msleep(100);
}

void right(int speed, int ticks)
{
    msleep(100);
    cmpc(LM);
    cmpc(RM);
    msleep(100);
    mav(LM,speed);
    mav(RM,-speed);
    while(gmpc(LM) < ticks)
    {
    }
    mav(LM,0);
    mav(RM,0);
    msleep(100);
}


void move_servo_slowly(int port, int end_pos, int speed)
{
    
    int current_pos;
    current_pos=get_servo_position(port);
    printf("%d     %d", current_pos, end_pos);
    
    if (current_pos < end_pos)
    {
        while (current_pos < end_pos)
            {
                current_pos += 20;
            	if (current_pos > 2045)
                {
                    current_pos = 2045;
                }
                set_servo_position(port, current_pos);
                msleep(speed); //in milliseconds
            }
     }
     else if (current_pos > end_pos)
     {
		printf("Im counting backwards!!!");
        while(current_pos > end_pos)
        {
            current_pos -= 20;
            if (current_pos < 0)
            {
                current_pos=0;
                break;
            }
            set_servo_position(port, current_pos);
            msleep(speed); //in milliseconds
        }
     }
    
	//set_servo_position(port, end_pos); 
}
