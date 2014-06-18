/**
 * @author Alexander Entinger, MSc / LXRobotics
 * @brief this sketch read the voltage from the potentiometer and transmits it to the pc where it can be viewed in the serial monitor (Tools -> Serial Monitor)
 * @file potentiometer_read_serial.ino
 */

static int const potentiometer_pin = 1; // A1

void setup() {
  Serial.begin(115200);
}

void loop() {
  // read the voltage as adc value
  int const adc_value_potentiometer = analogRead(potentiometer_pin);
  // convert to volt
  float const volt = (float)(adc_value_potentiometer)*(5.0/1024);
  // write to the pc
  Serial.print("Voltage on pin A1 = ");
  Serial.print(volt);
  Serial.println(" V");
  // wait a little
  delay(1000);
}

