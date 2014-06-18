/**
 * @author Alexander Entinger, MSc / LXRobotics
 * @brief this sketch demonstrates how to control the leds of the LXRobotics Novice Shield
 * @file rotating_leds.ino
 */

static int const led_green_pin = 11; // D11
static int const led_yellow_pin = 12; // D12
static int const led_red_pin = 13; // D13

void setup() {
  // configure the led pins as outputs
  pinMode(led_green_pin, OUTPUT);
  pinMode(led_yellow_pin, OUTPUT);
  pinMode(led_red_pin, OUTPUT);
  // turn of the leds
  turn_off_red();
  turn_off_yellow();
  turn_off_green();
}

void turn_on_red() {
  digitalWrite(led_red_pin, LOW);
}
void turn_off_red() {
  digitalWrite(led_red_pin, HIGH);
}
void turn_on_yellow() {
  digitalWrite(led_yellow_pin, LOW);
}
void turn_off_yellow() {
  digitalWrite(led_yellow_pin, HIGH);
}
void turn_on_green() {
  digitalWrite(led_green_pin, LOW);
}
void turn_off_green() {
  digitalWrite(led_green_pin, HIGH);
}

void loop() {
  turn_off_green();
  turn_on_red();
  delay(100);
  turn_on_yellow();
  turn_off_red();
  delay(100);
  turn_on_green();
  turn_off_yellow();
  delay(100);
}

