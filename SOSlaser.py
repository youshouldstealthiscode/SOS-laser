import time
from machine import Pin

# Constants for laser pin, short and long flash durations, and delays
laser_pin = 16
short_flash_duration = 0.5  # 0.5 seconds
long_flash_duration = 1.5  # 1.5 seconds
gap_between_flashes = 0.5
delay_between_runs = 3

laser = Pin(laser_pin, Pin.OUT)  # Set laser pin as OUTPUT

def flash(duration):
    laser.value(1)  # Turn on the laser
    time.sleep(duration)  # Wait for the duration of the flash
    laser.value(0)  # Turn off the laser
    time.sleep(gap_between_flashes)  # Wait for the gap between flashes

while True:
    # Send "SOS" in Morse code
    # "S" in Morse code: 3 short flashes
    for _ in range(3):
        flash(short_flash_duration)

    # Gap between letters
    time.sleep(gap_between_flashes)

    # "O" in Morse code: 3 long flashes
    for _ in range(3):
        flash(long_flash_duration)

    # Gap between letters
    time.sleep(gap_between_flashes)

    # "S" in Morse code: 3 short flashes
    for _ in range(3):
        flash(short_flash_duration)

    # Wait for 3 seconds before repeating the loop
    time.sleep(delay_between_runs)
