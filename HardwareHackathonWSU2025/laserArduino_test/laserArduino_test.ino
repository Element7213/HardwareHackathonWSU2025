#define LASER_PIN 2  // Choose an appropriate GPIO pin

void setup() {
    pinMode(LASER_PIN, OUTPUT);  // Set the pin as output
}

void loop() {
    digitalWrite(LASER_PIN, HIGH);  // Turn laser ON
    delay(100);                     // Wait 500ms
    digitalWrite(LASER_PIN, LOW);   // Turn laser OFF
    delay(100);                     // Wait 500ms
}
