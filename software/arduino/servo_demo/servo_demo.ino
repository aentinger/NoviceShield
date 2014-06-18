/**
 * @author Alexander Entinger, MSc / LXRobotics
 * @brief this sketch demonstrates how to control a servo attached to the LXRobotics Novice Shield
 * @file servo_demo.ino
 */

#include <Servo.h>

static int const servo_pin_1 = 9; // D9
static int const servo_pin_2 = 10; // D10
static int const current_servo_pin = servo_pin_1;

Servo my_servo;

void setup() {
  my_servo.attach(current_servo_pin);
}

void loop() {
  int const angle_min = 0;
  int const angle_max = 180;
  for(int angle=angle_min; angle<=angle_max; angle++) {
    my_servo.write(angle); 
    delay(10);
  }
}


