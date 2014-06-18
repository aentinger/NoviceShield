/**
 * @author Alexander Entinger, MSc / LXRobotics
 * @brief this sketch read the voltages from the ntc and ptc voltage divider and transmits it to the pc where it can be viewed in the serial monitor (Tools -> Serial Monitor)
 * @file temperature_read_serial.ino
 */

static int const ptc_pin = 3; // A3
static int const ntc_pin = 4; // A4

void setup() {
  Serial.begin(115200);
}

void loop() {
  // read the voltage as adc value
  int const adc_value_ptc_voltage = analogRead(ptc_pin);
  int const adc_value_ntc_voltage = analogRead(ntc_pin);
  // convert to volt
  float const volt_ptc = (float)(adc_value_ptc_voltage)*(5.0/1024);
  float const volt_ntc = (float)(adc_value_ntc_voltage)*(5.0/1024);
  // write to the pc
  Serial.print("PTC Voltage (A3) = ");
  Serial.print(volt_ptc);
  Serial.println(" V");
  Serial.print("NTC Voltage (A4) = ");
  Serial.print(volt_ntc);
  Serial.println(" V");
  // wait a little
  delay(1000);
}

