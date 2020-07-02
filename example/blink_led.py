#!/usr/bin/env python
# -*- coding: utf-8 -*-

import OPi.GPIO as GPIO
from time import sleep          # this lets us have a time delay

pin = 12

GPIO.setboard(GPIO.THREE)    # Orange Pi PC board
GPIO.setmode(GPIO.BOARD)        # set up BOARD BCM numbering
GPIO.setup(pin, GPIO.OUT)         # set BCM7 (pin 26) as an output (LED)

try:
    print ("Press CTRL+C to exit")
    while True:
        GPIO.output(pin, 1)       # set port/pin value to 1/HIGH/True
        sleep(0.1)
        GPIO.output(pin, 0)       # set port/pin value to 0/LOW/False
        sleep(0.1)

        GPIO.output(pin, 1)       # set port/pin value to 1/HIGH/True
        sleep(0.1)
        GPIO.output(pin, 0)       # set port/pin value to 0/LOW/False
        sleep(0.1)

        sleep(0.5)

except KeyboardInterrupt:
    GPIO.output(pin, 0)           # set port/pin value to 0/LOW/False
    GPIO.cleanup()              # Clean GPIO
    print ("Bye.")
