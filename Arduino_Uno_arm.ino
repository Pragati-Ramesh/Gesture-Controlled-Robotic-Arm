#include <Servo.h>

// Define Servo Pins (modify based on your connections)
#define SERVO_UP_DOWN 8
#define SERVO_LEFT_RIGHT 9
#define SERVO_FORWARD_BACK 10
#define SERVO_GRIPPER 12

// Create servo objects
Servo upDownServo;
Servo leftRightServo;
Servo forwardBackServo;
Servo gripperServo;

// Define Bluetooth communication variables
#define BT_RX_PIN 2  // Adjust based on Bluetooth module connections
int incomingByte = 0;

void setup() {
  // Initialize servos
  upDownServo.attach(SERVO_UP_DOWN);
  leftRightServo.attach(SERVO_LEFT_RIGHT);
  forwardBackServo.attach(SERVO_FORWARD_BACK);
  gripperServo.attach(SERVO_GRIPPER);

  // Initialize serial communication for Bluetooth
  Serial.begin(9600);
}

void loop() {
  // Check if there's data from Bluetooth
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    
    // Example: Parse data assuming integers for servo positions (0-180) and gripper state (0/1)
    int servo1Pos = incomingByte; // Modify parsing based on actual data format
    int servo2Pos = Serial.read(); // Modify parsing based on actual data format
    int servo3Pos = Serial.read(); // Modify parsing based on actual data format
    int gripperState = Serial.read(); // Modify parsing based on actual data format

    // Move servos and gripper based on received data
    upDownServo.write(servo1Pos);
    leftRightServo.write(servo2Pos);
    forwardBackServo.write(servo3Pos);
    gripperServo.write(gripperState * 180); // Convert gripper state (0/1) to servo position (0/180)
  }

  // Add delay to avoid overwhelming serial communication
  delay(10);
}
