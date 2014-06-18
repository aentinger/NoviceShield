/**
 * @author Alexander Entinger, MSc / LXRobotics
 * @brief this sketch demonstrates how to control the relais of the LXRobotics Novice Shield
 * @file relais_demo.ino
 */

static int const s1_pin = 2; // D2
static int const relais_pin = 4; // D4
static int const led_green_pin = 11; // D11
static int const led_red_pin = 13; // D13

void setup() {
  // configure the button s1 pin as input with pullup
  pinMode(s1_pin, INPUT_PULLUP);
  // configure the led pins as outputs
  pinMode(led_green_pin, OUTPUT);
  pinMode(led_red_pin, OUTPUT);
  // turn of the leds
  turn_off_red();
  turn_off_green();
  // configure relais pin as output
  pinMode(relais_pin, OUTPUT);
}

void turn_on_red() {
  digitalWrite(led_red_pin, LOW);
}
void turn_off_red() {
  digitalWrite(led_red_pin, HIGH);
}
void turn_on_green() {
  digitalWrite(led_green_pin, LOW);
}
void turn_off_green() {
  digitalWrite(led_green_pin, HIGH);
}
void turn_on_relais() {
  digitalWrite(relais_pin, LOW);
}
void turn_off_relais() {
  digitalWrite(relais_pin, HIGH);
}

void loop() {
  // check if the button is pressed
  boolean const s1_pressed = digitalRead(s1_pin) == LOW;

  // set leds and relais accordingly
  if(s1_pressed) {
    turn_on_relais();
    turn_on_green();
    turn_off_red();
  } 
  else {
    turn_off_relais();
    turn_off_green();
    turn_on_red();
  }
}


