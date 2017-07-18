#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Lo schema elettrico base per questo circuito è quello del kit sunfounder.
# Materiale: raspberry, power module, L293D, jumper wires, 2 motori DC
# L'ho modificato per riuscire a controllare due motori invece che uno soltanto.
# L'energia per i motori è data da una batteria da 9V collegata al power module.

import RPi.GPIO as GPIO
import time

# First motor
Motor1Pin1   = 11   # pin11 / gpio 17
Motor1Pin2   = 12   # pin12 / gpio 18
Motor1Enable = 13   # pin13 / gpio 27

# Second motor
Motor2Pin1   = 15   # pin15 / gpio 22
Motor2Pin2   = 16   # pin16 / gpio 23
Motor2Enable = 18   # pin18 / gpio 24

def setup():
    GPIO.setmode(GPIO.BOARD)           # Numbers GPIOs by physical location

    # Conf for first motor
    GPIO.setup(Motor1Pin1, GPIO.OUT)   # mode --- output
    GPIO.setup(Motor1Pin2, GPIO.OUT)
    GPIO.setup(Motor1Enable, GPIO.OUT)
    GPIO.output(Motor1Enable, GPIO.LOW) # motor 1 stop

    # Conf for second motor
    GPIO.setup(Motor2Pin1, GPIO.OUT)
    GPIO.setup(Motor2Pin2, GPIO.OUT)
    GPIO.setup(Motor2Enable, GPIO.OUT)
    GPIO.output(Motor2Enable, GPIO.LOW) # motor 2 stop


def loop():
    while True:
        print 'Press Ctrl+C to end the program...'
        # Let's run only the first motor
        print 'Start motor 1'
        GPIO.output(Motor1Enable, GPIO.HIGH) # motor 1 driver enable
        GPIO.output(Motor1Pin1, GPIO.HIGH)   # clockwise
        GPIO.output(Motor1Pin2, GPIO.LOW)
        time.sleep(4)

        print 'Stop motor 1'
        GPIO.output(Motor1Enable, GPIO.LOW) # motor 1 stop
        time.sleep(4)

        # Let's run only the second motor
        print 'Start motor 2'
        GPIO.output(Motor2Enable, GPIO.HIGH) # motor 1 driver enable
        GPIO.output(Motor2Pin1, GPIO.HIGH)
        GPIO.output(Motor2Pin2, GPIO.LOW)
        time.sleep(4)

        print 'Stop motor 2'
        GPIO.output(Motor2Enable, GPIO.LOW) # motor 2 stop
        time.sleep(4)

        # Let's run both the motors in opposite direction as before
        print 'Run both motors!'
        GPIO.output(Motor1Enable, GPIO.HIGH) # motor 1 driver enable
        GPIO.output(Motor2Enable, GPIO.HIGH) # motor 2 driver enable
        GPIO.output(Motor1Pin1, GPIO.LOW)   # 1 - anticlockwise
        GPIO.output(Motor1Pin2, GPIO.HIGH)
        GPIO.output(Motor2Pin1, GPIO.LOW)   # 2 - anticlockwise
        GPIO.output(Motor2Pin2, GPIO.HIGH)
        time.sleep(5)

        print 'Stop both motors!'
        GPIO.output(Motor1Enable, GPIO.LOW) # motor 1 stop
        GPIO.output(Motor2Enable, GPIO.LOW) # motor 2 stop
        time.sleep(3)

def destroy():
    GPIO.output(Motor1Enable, GPIO.LOW) # motor 1 stop
    GPIO.output(Motor2Enable, GPIO.LOW) # motor 2 stop
    GPIO.cleanup()                      # Release resource

if __name__ == '__main__':
    setup()
    try:
        loop()
    except KeyboardInterrupt:  # When 'Ctrl+C' is pressed
        destroy()
