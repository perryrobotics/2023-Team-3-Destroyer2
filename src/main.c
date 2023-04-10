#include "movement.h"
#include <kipr/botball.h>
#include "constants.h"
#include "sensors.h"
#include <time.h>

int main()
{
    int start_seconds;

    printf("The destroyer remade.\n \bbeta v3.2 KAILASH WITH X-ACTO kNiFe!!!");
    enable_servos();
    set_servo_position(CLAW, CLAW_CLOSED);
    set_servo_position(ARM, ARM_BACK);   

    wait_for_light(1);
    //msleep(5000);
    // ============================START==========================
    start_seconds = time(NULL);

    //Sweep over to get other poms
    forward(800,700);
    left(800,150);
    set_servo_position(CLAW,CLAW_CLOSED);
    set_servo_position(ARM,ARM_DOWN);
    left(800,500); // sweep poms into analysis lab
    set_servo_position(ARM,ARM_BACK);
    right(1000,500);
    //Realign and WAIT FOR OTHER ROBOT
    msleep(6800);
    // GO GET THE REST OF THE POMS NOW
    set_servo_position(CLAW, CLAW_OPEN+40);
    msleep(1500);
    // PUT DOWN ON FIRST POMS
    set_servo_position(ARM,ARM_DOWN);  
    msleep(750);

    //Gathering poms
    right(800,380);
    forward(800,1900);

    //WE ARE NOW FACING THE WIRESHARK!!!
    //msleep(750);
    //forward(1000,630);
    right_to_black(200,LEFT_LINE);

    right(100,300);
    forward(1300,2500); // GO FORWARD TO GET ALL THE POMS
    right(1000, 800); // SWEEP THE POMS IN!!

    //raise arm after sweeping poms
    set_servo_position(ARM, ARM_BACK); 
    msleep(750);
    left_to_black(1000, LEFT_LINE);
    set_servo_position(ARM, ARM_DOWN); 
    //left(1000,150);
    follow_to_touch(800, LEFT_LINE, TOUCH_SENSOR);

    //Grab it!!
    set_servo_position(CLAW, CLAW_WIRESHARK);  
    msleep(750);
    backward(900,500);
    //Get better grip now
    set_servo_position(CLAW, CLAW_WIRESHARK+200);
    msleep(500);
    forward(500,300);
    set_servo_position(CLAW, CLAW_WIRESHARK);  
    msleep(500);
    backward(500,500);
    //alright now go to the dropper
    msleep(1050); 
    //LINE FOLLOW
    left(1200,1000);
    //printf("1");
    left_to_black(900, LEFT_LINE);
    //printf("2");
    forward(800,900);
    //printf("3");
    left_to_black(900, LEFT_LINE);
    //printf("4");
    right_to_black(400, LEFT_LINE);


    follow_to_black(950, LEFT_LINE, RIGHT_LINE);
    // AT CENTER OF TABLE!!! GET OFF THE CENTER HUMP
    forward(1400, 2000);
    //Now follow until you hit the pipe
    follow_to_touch(1000, LEFT_LINE, TOUCH_SENSOR);
    // GET OFF THE PIPE!!!
    msleep(500);
    backward(1100,550); 
    right(400,130);
    forward(1200,100);
    //Wait until it's been a min and a bit

    while( (time(NULL) - start_seconds) < 64)
    {
    }
    //Now SCORE THAT BIG POINTS
    backward(1100,900);
    left(1400,1300);
    msleep(750);
    set_servo_position(CLAW, 500);
    msleep(750);
    set_servo_position(ARM, ARM_BACK);
    backward(1500, 1000);
    right(1500,300);
    forward(1500,6000);
    /*
    set_servo_position(CLAW, CLAW_OPEN);
    msleep(750);
    //Get the noodle
    back_to_black(800,LEFT_LINE);
    backward(700,200);
    set_servo_position(ARM, ARM_BACK);
    //align or something idk
    msleep(750);
    left(600,1050);
    forward_to_black(800, LEFT_LINE);
    left(400,100);
    forward(800, 1500);
    //RIGHT turn to the noodles
    right(800,800);
    set_servo_position(CLAW, CLAW_OPEN);
    set_servo_position(ARM, 1215);
    forward(800, 1400);
    left(300,5);
    forward(800,1500);
    //Grab that noodle
    set_servo_position(CLAW, CLAW_CLOSED); 
    msleep(750);
    //Put up da noodle
    move_servo_slowly(ARM, ARM_BACK, 20); 
    backward(800,1000);
    right(800,750);
    //Drop it now
    set_servo_position(ARM, ARM_DOWN);
    msleep(750);
    set_servo_position(CLAW, CLAW_OPEN);
    //Do some things?
    msleep(750);
    backward(200,1000);
    set_servo_position(ARM, ARM_BACK);
    msleep(750);
    set_servo_position(CLAW, CLAW_CLOSED);
    backward(500,4000);
    //TBH i have no clue
    forward(800,3500);
    set_servo_position(CLAW, CLAW_CLOSED);
    msleep(750);
    set_servo_position(ARM,ARM_BACK);
    msleep(750);  
*/
    disable_servos();

    return 0;
}


