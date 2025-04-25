#define TRIG_PIN D5  // GPIO14
#define ECHO_PIN D6  // GPIO12

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.println("Ultrasonic Sensor Initialized");
}

void loop() {
  long duration;
  float distance;

  // Trigger the sensor
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read echo time
  duration = pulseIn(ECHO_PIN, HIGH);

  // Convert to distance in cm
  distance = duration * 0.0343 / 2;

  Serial.print("Distance: ");
  Serial.print(distance, 2);
  Serial.println(" cm");

  delay(1000);
}
