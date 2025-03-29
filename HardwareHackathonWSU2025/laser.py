import RPi.GPIO as GPIO
import time

# GPIO setup
PIR_PIN = 17
LASER_PIN = 27

GPIO.setmode(GPIO.BCM)
GPIO.setup(PIR_PIN, GPIO.IN)
GPIO.setup(LASER_PIN, GPIO.OUT)

def motion_detected(channel):
    print("Motion detected! Shooting laser.")
    GPIO.output(LASER_PIN, GPIO.HIGH)
    time.sleep(0.25)  # Laser on for 0.25 second
    GPIO.output(LASER_PIN, GPIO.LOW)

# Event detection
GPIO.add_event_detect(PIR_PIN, GPIO.RISING, callback=motion_detected)

try:
    print("Monitoring for motion...")
    while True:
        time.sleep(0.5)  # Keep the script running, check for motion every 0.5 second
except KeyboardInterrupt:
    print("Exiting program.")
finally:
    GPIO.cleanup()

''' checks for motion every 0.1 second, uses polling which uses cpu more. code above uses event detection
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
            time.sleep(1)  # Laser on for 1 second
            GPIO.output(LASER_PIN, GPIO.LOW)   # Turn off laser
        time.sleep(0.1)  # Check for motion every 0.1 seconds

except KeyboardInterrupt:
    print("Program terminated")

finally:
    GPIO.cleanup()
'''