#include "movement.h"
#include <kipr/botball.h>
#include "constants.h"
#include "sensors.h"

int main()
{
    
    /*forward_to_black(1000, FRONT_LINE);
    msleep(1000);
    forward(800,1000);
       
	back_to_black(1000, FRONT_LINE);
    forward(800,1000);
	right(800,1000);
	msleep(1000);
    left_to_black(1000, FRONT_LINE);
	msleep(1000);
    forward(800,300);
	right_to_black(1000, FRONT_LINE);
    */
    
    forward_for_black(1000, FRONT_LINE, 2);
    return 0;
}
