from machine import Pin
import time

# Define the GPIO pins
pir_sensor = Pin(14, Pin.IN)
laser = Pin(27, Pin.OUT)

def shoot_laser():
    laser.on()
    time.sleep(0.5)  # Laser on for 0.5 seconds
    laser.off()

def main():
    while True:
        if pir_sensor.value() == 1:  # Motion detected
            print("Motion detected! Shooting laser.")
            shoot_laser()
        time.sleep(0.1)  # Small delay to debounce the sensor

if __name__ == "__main__":
    main()

'''
Upload the Script: Use ampy or rshell to upload the script to your ESP32.
    ampy --port /dev/ttyUSB0 put your_script.py

Run the Script: Connect to the ESP32 using a serial terminal (like screen or minicom) and run the script.
    import your_script
    your_script.main()
'''