/**
 * @author Alexander Entinger, MSc / LXRobotics
 * @brief this sketch read the voltage from the ldr voltage divider and transmits it to the pc where it can be viewed in the serial monitor (Tools -> Serial Monitor)
 * @file ldr_read_serial.ino
 */

static int const ldr_pin = 2; // A2

void setup() {
  Serial.begin(115200);
}

void loop() {
  // read the voltage as adc value
  int const adc_value_ldr_voltage = analogRead(ldr_pin);
  // convert to volt
  float const volt = (float)(adc_value_ldr_voltage)*(5.0/1024);
  // write to the pc
  Serial.print("LDR Voltage (A2) = ");
  Serial.print(volt);
  Serial.println(" V");
  // wait a little
  delay(1000);
}

