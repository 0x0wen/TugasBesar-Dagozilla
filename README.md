# Jacobi Robot Programming Implementation - Dagozilla ITB Internship 2023

## Introduction

This documentation provides an overview of the programming details and specifications for the Jacobi Robot project. The project involves reviving the Jacobi robot. Jacobi has omnidirectional 4WD wheels as locomotion, which can be controlled using a keyboard. The robot will be powered by a PC running ROS (Robot Operating System) and will communicate with a microcontroller (STM32 Nucleo) to execute motor commands.

## Specifications

### Robot Configuration

- 4WD omni-directional robot with wheels for movement in all directions.
- The robot is controlled via a PC running ROS.
- The PC serves as the main functional unit for ROS operations.
- The microcontroller used is STM32 Nucleo, which communicates with the PC.
- The robot is powered by two LiPo batteries:
    1. One 14.8V battery powers the PC.
    2. One 22.4V battery powers the STM32 Nucleo.



## Program Dependencies
1. Ubuntu 20.04 LTS
2. ROS Noetic

## Instalation
1. Clone this repository (for more information, please visit this [link](https://www.youtube.com/watch?v=C-jOtle5BmE) and watch the tutorial)
```sh
git clone https://[PAT]:x-oauth-basic@github.com/owenthe10x/TUBES-Dagoz.git
```
2. Create the workspace
```sh
$ cd jacobi-robot_ws
$ catkin_make
```

## How To Run
### Remote access to the robot PC
1. The PC on the robot is run remotely using a laptop with SSH (Secure Shell).
2. The PC on the robot is connected to WiFi Dagozilla then use a separate laptop that is also connected to WiFi Dagozilla.
3. The laptop connected to WiFi Dagozilla is used to find the IP address of the robot PC using 192.168.1.1 (default gateway) in the browser. **Password: admin**
4. Use SSH on the laptop to access the PC robot terminal with the command:
```sh
ssh -XC <username>@<ip_addr>
```
-   Example: 

    The username of the robot PC is "shani" and the ip address is 192.168.1.104, then the command is
    ```sh
    ssh -XC shani@192.168.1.104
    ```
5. Enter the robot PC password and the laptop is successfully connected to the robot PC terminal.
6. Change directory to jacobi-robot_ws and run this command:
```sh
$ source devel/setup.bash # bash terminal
# or
$ source devel/setup.zsh # zsh terminal
```
7. Launch the program using the command:
```sh
$ roslaunch robot_launch jacobi_routine.launch
```

## Rostopic

### /control/command/hardware
- Function: The ROS node on the PC publishes motor commands to the STM32 Nucleo (subscriber) using PWM values for each motor.
- PWM range: -1.0 ≤ PWM ≤ 1.0, where 1.0 represents maximum motor power, and -1.0 represents maximum power in the opposite direction.
- Positive PWM indicates clockwise rotation relative to the observer.
- To prevent the robot from moving too fast, the minimum and maximum PWM values used are -0.1 and 0.1, respectively.

### /PWM
- Function: Same as the previous one but used for testing and debugging. 
### /robot_keyboard_input
- Function: Getting the keyboard input by the user

## Author

1. Firly Hafiz Syahreza (Dagozilla ITB Programming Intern)
2. Muhammad Kamal (Dagozilla ITB Programming Intern)
3. Owen Tobias Sinurat (Dagozilla ITB Programming Intern)
4. Raden Rafly Hanggaraksa Budiarto (Dagozilla ITB Programming Intern)
5. Ulivia Embun Tresna Wardani (Dagozilla ITB Programming Intern)

## References

- ["ROS Wiki"](http://wiki.ros.org/). *ROS Community*. 23 May 2023.
- ["ROS Overview Day 4 Programming Internship"](https://docs.google.com/presentation/d/1-BXbW0xk8AuFd5CYSxQdVrsaX1Lo4jzK4FVs6je9gwc/edit#slide=id.p). *Dagozilla*. 23 May 2023.
- ["ROS Tutorials Python - Beginner"](https://www.youtube.com/playlist?list=PLAjUtIp46jDcQb-MgFLpGqskm9iB5xfoP). *Emil Vidmark*. 23 May 2023.
- ["ROS Tutorials - Beginner"](https://www.youtube.com/playlist?list=PLAjUtIp46jDdv1U7I0tJlJTmjnYcczJSN). *Emil Vidmark*. 23 May 2023.
- to be added....