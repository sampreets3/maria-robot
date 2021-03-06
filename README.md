[![GitHub issues](https://img.shields.io/github/issues/Naereen/StrapDown.js.svg)](https://github.com/sampreets3/maria-robot/issues/)
[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)
[![Maintenance](https://img.shields.io/badge/Maintained%3F-yes-green.svg)](https://GitHub.com/Naereen/StrapDown.js/graphs/commit-activity)
[![Open Source Love svg3](https://badges.frapsoft.com/os/v3/open-source.svg?v=103)](https://github.com/ellerbrock/open-source-badges/)


# maria-robot

MARIA is a simple robot which will help me understand how to design the systems of a complex robot. Features will be mentioned as they are added.
The organization of the project is divided into three main components: The ROS workspace, the necessary resources *(books, papers, etc.)* and any supporting material. This may include a lot of things such as the electrical schematics and board layouts for several boards, the CAD models, the PCB fabrication files, and so on.

---

## Roadmap

As this is mainly a summer project, my current aim is to get all the electronics and hardware done. That way, I can get a basic idea about how the system would look and likely behave. Writing software and firmware would then be easier. A good approach in my opinion is to keep the ROS based processing separate from the low-level actions, and write a bridge between the two when necessary. The microcontroller I have decided to go with for designing the base board is the STM32F103C8T6 from ST Microelectronics. This is a small ARM Cortex M3 based microcontroller, packed with a lot of features. The design of the base board is highly inspired by the famous "Blue Pill" line of cheap development boards featuring this MCU. For the moment, the number of sensors are being kept simple - IR sensors as limit switches, to always keep the robot at a certain distance from the walls. There will be two IR sensors on each face, so 8 in total.

After having finished with the hardware and designs, I will focus on writing the low-level microcontroller code to interact with the sensors. I will be using bare-metal programming, although if things get too complex, I might try to compile everything within a C/C++ library. When writing the code, the first test would be to see if I can get data out of the IR sensors. Once that is done, I will focus on the SPI communication channel, to write the driver code for the motor controllers. The logic is pretty simple, so I think I might be able to provide API based framework for it.

With the electronics design done and the low level drivers tested, I will then focus on creating the simple ROS workspace for the high-level interaction with the robot. While I send the board designs for fabrication, I will start by using the ros_bridge package to see if I can establish communication between the PC and the MCU or not. I am thinking of using a Raspberry Pi at the moment, but it might change if I come across a better SBC.

Then onwards, most of the development will focus on the ROS side of things, like using a vision system, introducing some simple AI into it, etc. I will revisit the electronics designs only if I feel the need of extra sensors, or something goes wrong.

---



## Updates

[![ros-ws-update](https://img.shields.io/badge/ros-workspace-red.svg)](https://shields.io/)
**Added three ROS packages to the main catkin workspace.** There are three main packages as of now: [maria_robot_control](https://github.com/sampreets3/maria-robot/tree/master/maria_ros_ws/src/maria_robot_control), which will focus on the control of the differential drive robot, [maria_robot_gazebo](https://github.com/sampreets3/maria-robot/tree/master/maria_ros_ws/src/maria_robot_gazebo)
where all the files required for the Gazebo simulation will reside, and [maria_robot_description](https://github.com/sampreets3/maria-robot/tree/master/maria_ros_ws/src/maria_robot_description) which will host all the CAD files for the chassis design and the corresponding URDF imports.

[![support-schematic](https://img.shields.io/badge/schematic-support-blue.svg)](https://shields.io/)
**Updated the Motor Controller Schematic.** Refined the design a little bit. The AMS1117 LDOs use the copper plane as a heatsink, as was pointed out by [Mr. Petr Dvořák](https://www.linkedin.com/in/petr-dvorak-hw/). Thus, I created two copper planes, one for 3.3V and another for 5V, for the heat to dissipate. Also, I had overlooked the use of decoupling capacitors in the design. Added them close to the ICs.

[![support-schematic](https://img.shields.io/badge/schematic-support-blue.svg)](https://shields.io/)
**Added schematics for STM32 base board.** This board is going to be responsible for processing sensor data, sending commands to the motor controller, and in later stages, communicating with the SBC running ROS. Need to finish the layout of the board.

[![resource-legacy-code](https://img.shields.io/badge/resource-legacy-red.svg)](https://shields.io/)
**Added the legacy files and libraries for the original MARIA design.** MARIA was originally developed during my time at The Neotia University, India. Added the old files and libraries for reference or if someone from the old team would need support. The old architecture was based off an Arduino Uno, so you will mainly find Arduino codes, a MARIA library containing essential functionalities.

[![ros-ws-update](https://img.shields.io/badge/ros-workspace-red.svg)](https://shields.io/)
**Added the main ROS workspace for the robot.** Configured it with a simple chatter application under a package named "comm". Currently hosts two executables, "talker" and "listener". Maybe I will add the build directories to .gitignore

<!-- BADGES FOR UPDATE STATUS-->
<!-- Used to indicate what kind of work was updated-->
<!-- The general rule of thumb is to make it understandable. So, we can use any sort of indicator of what it was. -->
<!-- For instance, I had updated the schematics in the support section, so I added the badge as "schematic - support" -->
<!-- You can make your badge from this generic badge tag : [![Generic badge](https://img.shields.io/badge/<SUBJECT>-<STATUS>-<COLOR>.svg)](https://shields.io/) -->
<!-- Just change the <SUBJECT>, <STATUS>, and <COLOR> fields to appropriate values -->
<!-- Ideally, use blue for electrical schematics/layout, red for code updates, and other colors as per need -->

---

## Usage

If you are interested in contributing to this project, be my guest!
  1. You can start by forking the repo using `git clone https://github.com/sampreets3/maria-robot.git`, and begin working on things.
  1. You can open an issue pertaining to any fix/features that you might want to implement.
  1. If everything looks good, then open a PR and we shall merge the commit.

---

## Contact

You can reach out to me via email at : `sampreets3@gmail.com`

![visitors](https://visitor-badge.laobi.icu/badge?page_id=sampreets3.maria-robot)
