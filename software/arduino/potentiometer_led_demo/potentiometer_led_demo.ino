/**
 * @author Alexander Entinger, MSc / LXRobotics
 * @brief this sketch read the voltage from the potentiometer and turns the leds on/off depending on this voltage
 * @file potentiometer_led_demo.ino
 */

static int const potentiometer_pin = 1; // A1
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
  // read the voltage as adc value
  int const adc_value_potentiometer = analogRead(potentiometer_pin);
  // convert to volt
  float const volt = (float)(adc_value_potentiometer)*(5.0/1024);
  // set the leds accordingly
  turn_off_red();
  turn_off_yellow();
  turn_off_green();
  if(volt <= 0.8) turn_on_green();
  else if(volt > 0.8 && volt <= 1.6) turn_on_yellow();
  else if(volt > 1.6) turn_on_red();
}

