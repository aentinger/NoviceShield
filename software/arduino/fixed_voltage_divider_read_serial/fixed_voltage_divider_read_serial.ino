/**
 * @author Alexander Entinger, MSc / LXRobotics
 * @brief this sketch read the voltage from the fixed voltage divider and transmits it to the pc where it can be viewed in the serial monitor (Tools -> Serial Monitor)
 * @file fixed_voltage_divider_read_serial.ino.ino
 */

static int const fixed_voltage_divider_pin = 0; // A0

// V_FIXED = 5V * R7/(R6+R7) = 5V * 2k/(1k+2k) = 5V * 2/3 = 3.33 V
// this value should always be received via this sketch
// if you get something severely different you most likely built in a different resistor than the building instructions state

void setup() {
  // initialize the serial interface
  Serial.begin(115200);
    // read the voltage from adc
  int const adc_value_fixed_voltage = analogRead(fixed_voltage_divider_pin);
  // convert to volt
  float const volt = (float)(adc_value_fixed_voltage)*(5.0/1024);
  // write to the pc
  Serial.print("Voltage on pin A0 = ");
  Serial.print(volt);
  Serial.println(" V");
}

void loop() {

}

