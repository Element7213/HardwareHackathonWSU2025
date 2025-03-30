int speakerPin = 2;  // Pin connected to the speaker

void setup() {
  pinMode(speakerPin, OUTPUT);  // Set the speaker pin as an output
}

void loop() {
  tone(speakerPin, 1000);  // Generate a 1000 Hz tone
  delay(1000);  // Wait for 1 second
  noTone(speakerPin);  // Stop the tone
  delay(1000);  // Wait for 1 second before repeating
}