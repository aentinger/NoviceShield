/**
 * @author Alexander Entinger, MSc / LXRobotics
 * @brief this sketch demonstrates how to read the button state and display it on the leds using a method known as "interrupt"
 * @file buttons_interrupt.ino
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
  digitalWrite(led_green_pin, HIGH);
  digitalWrite(led_yellow_pin, HIGH);
  digitalWrite(led_red_pin, HIGH);
  // attach the interrupt handler functions
  attachInterrupt(0, &isr_s1, CHANGE); // call function isr_s1 whenever a change edge is detected at s1 (connected to D2 = INT0)
  attachInterrupt(1, &isr_s2, CHANGE); // call function isr_s2 whenever a change is detected at s1 (connected to D3 = INT1)
}

// this function is called whenever a change at the pin INT0 = D2 = S1 occurs
void isr_s1() {
  boolean const s1_pressed = digitalRead(s1_pin) == LOW;
  if(s1_pressed) {
    digitalWrite(led_green_pin, LOW); 
  } 
  else {
    digitalWrite(led_green_pin, HIGH); 
  }
}

// this function is called whenever a change at the pin INT1 = D3 = S2 occurs
void isr_s2() {
  boolean const s2_pressed = digitalRead(s2_pin) == LOW;
  if(s2_pressed) {
    digitalWrite(led_red_pin, LOW); 
  } 
  else {
    digitalWrite(led_red_pin, HIGH); 
  }
}

void loop() {
  // dont do anything here - everything is handled within the interrupt service routine
}

