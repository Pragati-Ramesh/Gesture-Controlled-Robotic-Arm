#include <Wire.h>
#include <MPU6050.h>
#include <Servo.h>

const int MPU_addr = 0x68; // I2C Address (optional, defined for clarity)

Servo upDownServo;
Servo leftRightServo;
Servo forwardBackServo;
Servo gripperServo;

#define SERVO_UP_DOWN 10
#define SERVO_LEFT_RIGHT 8
#define SERVO_FORWARD_BACK 9
#define SERVO_GRIPPER 11

const int BUTTON_PIN = 7; // Arduino pin connected to button's pin

int angle = 0; // The current angle of the gripper servo motor
int lastButtonState; // The previous state of the button
int currentButtonState; // The current state of the button

MPU6050 sensor;
int16_t ax, ay, az;
int16_t gx, gy, gz;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  // Initialize MPU6050
  sensor.initialize();
  Serial.println(sensor.testConnection() ? "Successfully Connected" : "Connection failed");

  // Attach servos
  upDownServo.attach(SERVO_UP_DOWN);
  leftRightServo.attach(SERVO_LEFT_RIGHT);
  forwardBackServo.attach(SERVO_FORWARD_BACK);
  gripperServo.attach(SERVO_GRIPPER);

  // Button pin mode
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  gripperServo.write(angle); // Initialize gripper servo position
  currentButtonState = digitalRead(BUTTON_PIN);
}

void loop() {
  // Read MPU data
  sensor.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  // Map accelerometer reading (ax) to servo angle
  int forward_back_angle = map(ax, -2000, 8000, 0, 90);
  int left_right_angle = map(ay, -2000, 8000, 0, 90);
  int up_down_angle = 1.5*forward_back_angle;      // Fine-tune the mapping range based on the kind of readings of your specific MPU
  //int up_down_angle = map(az, -4000, 4000, 0, 180);
  //int forward_back_angle = 0.75*up_down_angle;
  // Serial monitor print for MPU data
  Serial.print("X: ");
  Serial.println(forward_back_angle);
  Serial.print("Y: ");
  Serial.println(left_right_angle);
  Serial.print("Z: ");
  Serial.println(up_down_angle);

  // Control arm movement based on MPU data
  upDownServo.write(up_down_angle);
  forwardBackServo.write(forward_back_angle);
  leftRightServo.write(left_right_angle);

  // Button press handling for gripper
  lastButtonState = currentButtonState;
  currentButtonState = digitalRead(BUTTON_PIN);

  if (lastButtonState == HIGH && currentButtonState == LOW) {
    Serial.println("Gripper Button Pressed!");
    if (angle == 0) {
      angle = 180;
    } else {
      angle = 0;
    }
    gripperServo.write(angle);
  }

  delay(400);
}
