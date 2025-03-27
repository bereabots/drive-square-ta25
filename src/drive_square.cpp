#include <iostream>
#include <cmath>

#include <mbot_bridge/robot.h>
#include <wall_follower/common/utils.h>


int main(int argc, const char *argv[])
{
    // Initialize the robot.
    mbot_bridge::MBot robot;

    float vx =0.3; //x velocity
    float vy = 0.3; //y velocity

    int time = 3; //time to wait

    for (int i=0; i<3;i++){
        //drive forward along x-axis
        robot.drive(vx,0,0);
        sleepFor(time);
        robot.drive(0,0,0);
        sleepFor(2);

        //drive forward along y-axis
        robot.drive(0,vy,0);
        sleepFor(time);
        robot.drive(0,0,0);
        sleepFor(2);

        //drive backward along x-axis
        robot.drive(-vx,0,0);
        sleepFor(time);
        robot.drive(0,0,0);
        sleepFor(2);

        //drive backward along y-axis
        robot.drive(0,-vy,0);
        sleepFor(time);
        robot.drive(0,0,0);
        sleepFor(2);
    }

    // Stop the robot.
    std::cout << "Stopping the robot!!" << std::endl;
    robot.stop();
    return 0;
}
