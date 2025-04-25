#include <Wire.h>
#include <Adafruit_ADS1015.h>

Adafruit_ADS1115 ads;  // Create an ADS1115 object

void setup() {
  Serial.begin(9600);
  Wire.begin();
  ads.begin();
  Serial.println("Starting pH sensor readings...");
}

void loop() {
  int16_t adc0 = ads.readADC_SingleEnded(0);  // Read from A0 of ADS1115
  float voltage = adc0 * 0.1875 / 1000.0;      // Convert to voltage (0.1875 mV/bit for default gain)

  float ph = voltageToPh(voltage);

  Serial.print("ADC: "); Serial.print(adc0);
  Serial.print(" | Voltage: "); Serial.print(voltage, 3);
  Serial.print(" V | pH: "); Serial.println(ph, 2);

  delay(1000);
}

// Basic conversion function — you may need calibration for your specific sensor
float voltageToPh(float voltage) {
  // Example: 3.0V = pH 7.0, 0.0V = pH 0.0, linear map
  // Adjust based on calibration
  return 7.0 + ((2.5 - voltage) * 3.5);  // Example formula
}
