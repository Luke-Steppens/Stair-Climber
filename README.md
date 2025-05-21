# Stair-Climber


This repo currently contains all the group work from my 2nd year group COMP208 module

I am in the process of rearranging pieces to show my personal contributions

# COMP208 Robot Scaling Vehicle Project

## Overview

![](https://github.falmouth.ac.uk/GA-Undergrad-Student-Work-24-25/COMP208-GROUP-SCALING/blob/main/CAD/Fusion%20360/Render/Final%20frame%20render.png?raw=true)

This repository contains all the resources, code, and documentation for the COMP208 group project at Falmouth University (Second Year). The project involves designing and building a robot vehicle that can climb two flights of stairs (including a turn) and carry a 1kg cargo. 

<div style="display: flex; justify-content: space-between;">
  <img src="https://github.falmouth.ac.uk/GA-Undergrad-Student-Work-24-25/COMP208-GROUP-SCALING/blob/main/Media/Screenshots/stairs.png?raw=true" alt="Navigation" width="300">
  <img src="https://github.falmouth.ac.uk/GA-Undergrad-Student-Work-24-25/COMP208-GROUP-SCALING/blob/main/Media/Screenshots/1KG.png?raw=true" alt="Load Bearing" width="300">
  <img src="https://github.falmouth.ac.uk/GA-Undergrad-Student-Work-24-25/COMP208-GROUP-SCALING/blob/main/Media/Screenshots/locomotion.png?raw=true" alt="Locomotion" width="300">
</div>



- **Design and Manufacture:** Create a robot vehicle capable of climbing stairs and carrying cargo.
- **Documentation:** Use software tools to document the process, including:
  - CAD for design and prototyping
  - Arduino IDE for programming the robot's control system
- **Testing:** Implement testing to ensure the robot can perform tasks on flat surfaces and stairs.

### Team Members

- **Member 1:** [Anastasia Zaikina] - https://www.notion.so/Sebastian-Scaling-group-1342eb496f5380d0b8ddc6c4d95a6e97?pvs=4
- **Member 2:** [Revan Murton] - https://www.notion.so/Development-Log-208-111fe3942e8a80fbb9e5f9e884b2fb9e
- **Member 3:** [Luke Steppens] - https://www.notion.so/COMP208-Robotics-Cybernetics-12e3a60eabfc80f29989f14d743be708?pvs=4


### Repository Contents

- **CAD**
  - `Assemblies`: The complete robot assemblies.
  - `Parts`: Parts and components used in the design.
  - `Drawings`: Technical drawings of components and assemblies.

- **Code**
  - `Basic Component Code`: Code for individual components like motors and sensors.
  - `Control System`: The main code for controlling the robot's behavior.
  - `Test Code`: Scripts for testing individual components.

- **Documentation**
  - `Photos`: Project Development and testing
  - `videos`: Project development and testing.
  - `Screenshots`: Used in delivery of posters, devlogs and github
  - `Datasheets`: Technical specifications for used components.
  - `Design Documentation`: Detailed explanations of design decisions and iterations.
  - `Diagrams`: State Diagrams.
  - `Research`: Academic Papers and Grey Literature.
  - `Mathematics`: Notes Regarding gearing ratios.

- **Electronics**
  - `Schematics`: Circuit diagrams for wiring and connections.
  - `DataSheets`: Datasheets for electronic components.


  ### Code
The code in `scalingTurningStates` works on a simple 2 state system. One of the states is responsible for going forward and watching for walls when the robot is flat, and the other state watches for the robot being tilted, to continue climbing upwards.
![stateDiagram2](https://github.falmouth.ac.uk/GA-Undergrad-Student-Work-24-25/COMP208-GROUP-SCALING/assets/1907/11496b3b-43d4-46d5-a61d-550dc4b2cffc)

To alter `scalingTurningStates` to work in any new envinronment the following needs to be done:
- Check calibration of the Ultrasonic Sensor
- If readings dont match real life measurements, edit the code 
- The robot needs to have enough space to be able to turn 90 degrees in place, this is reflected in the variable `setDist` set at 43cm, change this if it needs more/less space
- Depending on the motors used the robot will turn at different speeds. If the robot doesn't reach the 90 degrees needed to turn, alter the delay in the function `turnRight90`.


The code in Comp208_Scaling_state_machine_code. It has two states, one for when it detects it is on a tilt (FORWARD) and the other for when it is flat (TURNING) for the second time, this is done so that the robot doesn't immediately start turning and miss the stairs. It also will reverse and turn right if it encounters a wall during the turning state

![StateDiagram](https://github.falmouth.ac.uk/GA-Undergrad-Student-Work-24-25/COMP208-GROUP-SCALING/blob/main/Documentation/Diagrams/State%20Diagram.png)


If you want to modify this for another purpose the main things that will need changing are:
- Check Ultrasonic sensor calibration
- Change setDist to the threshold distance
- Modify speed of front motors depending on the use case


  
 
  


