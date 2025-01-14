# Robotic Arm Control System

## Project Overview
This project explores the exciting realm of robotics by building a beginner-friendly robotic arm. The system uses an MPU6050 sensor, servo motors, and an Arduino Uno to create a functional robotic arm capable of basic movements and gripper control.

---

## Components Used
1. **MPU6050** - Accelerometer and gyroscope sensor (1)  
2. **MG255** - Positional servo motor (3)  
3. **SG90** - Positional servo motor (1)  
4. **3D-Printed Robotic Arm** - Custom frame  
5. **Arduino Uno** - Microcontroller (1)  
6. **Button** - Input control  
7. **Jumper Wires** - Connections  
8. **Breadboard** - Prototyping platform  

---

## Working Mechanism
This project implements a basic control system for the robotic arm:

1. **Libraries and Communication**:  
   - Uses libraries for I2C communication, MPU6050 sensor interaction, and servo motor control.  
   - Sets up I2C communication between the MPU6050 and Arduino through SDA and SCL pins.

2. **Control Logic**:  
   - Continuously reads acceleration data from the MPU6050 sensor.  
   - Maps acceleration values to control the arm’s primary servos:  
     - **Left/Right**  
     - **Forward/Back**  
     - **Up/Down** (linearly dependent on Forward/Back due to the 2D constraint of the accelerometer).

3. **Gripper Control**:  
   - Monitors button state to toggle the gripper servo position.

**Note**: The x and y readings from the accelerometer are mapped to angles between 0° and 90° to control movement.  

---

## Circuit Diagrams
### Circuit Diagram
![Circuit Diagram](https://github.com/user-attachments/assets/c64399c6-99a2-45a8-9c2a-cbe2700ab465)

### Realized Circuit Diagram
![Realized Circuit Diagram](https://github.com/user-attachments/assets/511231eb-fe5c-4ce1-bdcf-ec502c2e2d7c)

---

## Contributors
1. **Pragati Ramesh**  
2. **Pusshya Jagadish**  

---

## References
1. [DIY Hand Gesture Controlled Robotic Arm Using Arduino Nano - Circuit Digest](https://circuitdigest.com/microcontroller-projects/diy-hand-gesture-controlled-robotic-arm-using-arduino-nano)  
2. [Arduino Button Servo Motor Control](https://arduinogetstarted.com/tutorials/arduino-button-servo-motor)  
3. [How to Control a Servo with Arduino and MPU6050 - Maker Pro](https://maker.pro/arduino/tutorial/how-to-control-a-servo-with-an-arduino-and-mpu605)

---

## Limitations and Future Work
### Limitations
- **Drift Errors**: The arm experienced significant drift errors during implementation. Fine-tuning the accelerometer readings and eliminating linear dependencies can improve precision.

### Future Work
- **Advanced Gesture Control**: Integrate vision-based gesture control for more sophisticated operation.  
- **Enhanced Independence**: Develop independent movement axes for better flexibility and accuracy.  
