#include <ESP32Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int x = 0; // variable to store movement detection at servo position

void setup() {
  myservo.attach(18);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  for (pos = 20; pos <= 160; pos += 1, x += 1) { // goes from 0 degrees to 180 degrees
    // if(x == 90) delay(1000); // delay for 1000ms at motion detection
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15m s for the servo to reach the position
  }
  // delay(1000);
  for (pos = 160; pos >= 20; pos -= 1, x -= 1) { // goes from 180 degrees to 0 degrees
    // if(x == 90) delay(1000); // delay for 1000ms at motion detection
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }
}
