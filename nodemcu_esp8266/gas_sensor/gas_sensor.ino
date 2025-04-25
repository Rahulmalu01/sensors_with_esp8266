// --- BOARD: ESP8266 (NodeMCU) ---
// Gas sensor on A0 (ESP8266 has only one analog pin)

// --- DEFINES ---
#define GAS_PIN A0   // ESP8266 only has A0

// --- SETUP ---
void setup() {
  Serial.begin(9600);
  delay(1000);
  Serial.println("Starting gas sensor readings...");
}

// --- GAS SENSOR READING (Analog) ---
int readGasRaw() {
  return analogRead(GAS_PIN);
}

float readGasPpm() {
  int raw = readGasRaw();
  return raw;  // Replace with calibration formula if needed
}

// --- LOOP ---
void loop() {
  int gasRaw = readGasRaw();
  float gasPpm = readGasPpm();

  Serial.print("Gas raw: "); Serial.print(gasRaw);
  Serial.print(" | Gas ppm: "); Serial.println(gasPpm);

  delay(1000);
}
