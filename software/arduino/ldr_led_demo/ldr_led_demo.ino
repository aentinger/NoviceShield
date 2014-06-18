/**
 * @author Alexander Entinger, MSc / LXRobotics
 * @brief this sketch read the voltage from the ldr voltage divider and turns on the green led if it is to dark
 * @file ldr_led_demo.ino
 */

static int const ldr_pin = 2; // A2
static int const led_green_pin = 11; // D11

void setup() {
  // configure the led pins as outputs
  pinMode(led_green_pin, OUTPUT);
  turn_off_green();
}

void turn_on_green() {
  digitalWrite(led_green_pin, LOW);
}
void turn_off_green() {
  digitalWrite(led_green_pin, HIGH);
}

void loop() {
  // read the voltage as adc value
  int const adc_value_ldr_voltage = analogRead(ldr_pin);
  // convert to volt
  float const ldr_volt = (float)(adc_value_ldr_voltage)*(5.0/1024);
  // check if it is too dark
  boolean const it_is_too_dark = ldr_volt >= 2.0;
  // turn on/off green led accordingly
  if(it_is_too_dark) {
    turn_on_green();
  } 
  else {
    turn_off_green();
  }
}


