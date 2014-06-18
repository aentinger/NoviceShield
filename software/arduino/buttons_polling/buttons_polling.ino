/**
 * @author Alexander Entinger, MSc / LXRobotics
 * @brief this sketch demonstrates how to read the button state and display it on the leds using a method known as "polling"
 * @file buttons_polling.ino
 */
 
static int const s1_pin = 2; // D2
static int const s2_pin = 3; // D3
static int const led_green_pin = 11; // D11
static int const led_yellow_pin = 12; // D12
static int const led_red_pin = 13; // D13

void setup() {
  // configure the two button pins as input with pullup
  pinMode(s1_pin, INPUT_PULLUP);
  pinMode(s2_pin, INPUT_PULLUP);
  // configure the led pins as outputs
  pinMode(led_green_pin, OUTPUT);
  pinMode(led_yellow_pin, OUTPUT);
  pinMode(led_red_pin, OUTPUT);
}

void loop() {
  // read the buttons over and over again in this loop
  // this is called "polling"
  boolean const s1_pressed = digitalRead(s1_pin) == LOW;
  boolean const s2_pressed = digitalRead(s2_pin) == LOW;
  
  // and set the leds accordingly
  if(s1_pressed && s2_pressed) {
   // when both buttons are pressed, then turn on ALL LEDs
   digitalWrite(led_green_pin, LOW);
   digitalWrite(led_yellow_pin, LOW);
   digitalWrite(led_red_pin, LOW);
  } else {
    // otherwise turn only that led on, where the corresponding button is pressed
    digitalWrite(led_yellow_pin, HIGH);
    if(s1_pressed) {
     digitalWrite(led_green_pin, LOW); 
    } else {
      digitalWrite(led_green_pin, HIGH); 
    }
    if(s2_pressed) {
     digitalWrite(led_red_pin, LOW); 
    } else {
     digitalWrite(led_red_pin, HIGH); 
    }
  }
}
