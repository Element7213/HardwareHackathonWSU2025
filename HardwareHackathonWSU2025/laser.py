import RPi.GPIO as GPIO
import time

# Set up GPIO
GPIO.setmode(GPIO.BCM)
PIR_PIN = 17
LASER_PIN = 18

GPIO.setup(PIR_PIN, GPIO.IN)
GPIO.setup(LASER_PIN, GPIO.OUT)

try:
    print("Motion Detector Initialized")
    time.sleep(2)  # Allow PIR sensor to stabilize
    print("Ready")

    while True:
        if GPIO.input(PIR_PIN):
            print("Motion Detected!")
            GPIO.output(LASER_PIN, GPIO.HIGH)  # Turn on laser
            time.sleep(0.25)  # Laser on for 0.25 second
            GPIO.output(LASER_PIN, GPIO.LOW)   # Turn off laser
        time.sleep(0.1)  # Check for motion every 0.1 seconds

except KeyboardInterrupt:
    print("Program terminated")

finally:
    GPIO.cleanup()