#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Help for the code to use with this sensor from this link:
# https://www.modmypi.com/blog/ds18b20-one-wire-digital-temperature-sensor-and-the-raspberry-pi

import os
import time

os.system('modprobe w1-gpio')
os.system('modprobe w1-therm')

# IMPORTANT: CHANGE THIS ACCORDING TO YOUR SENSOR SERIAL NUMBER
temp_sensor = '/sys/bus/w1/devices/28-80000028f844/w1_slave'


def get_raw_temp():
    """ This functions read the file wich contains the output of the sensor
    and returns it as it is."""

    f = open(temp_sensor, 'r')
    lines = f.readlines()
    f.close()
    return lines


def get_temp():
    """ Reads the output of the sensor,
    check is the readings are OK"""

    lines = get_raw_temp()

    while lines[0].strip()[-3:]!='YES':
        time.sleep(0.5)
        lines = get_raw_temp()

    temp_output = lines[1].find('t=')

    if temp_output != -1:
        temp_string = lines[1].strip()[temp_output+2:] # we strip the digits
        temp_c = float(temp_string)/1000.0
        temp_f = temp_c * 9.0 / 5.0 + 32.0 # calculate the Fahrenheit temp
        return temp_c, temp_f

def loop():
    while True:
        print "Reading temperature..."
        readings = get_temp()
        print "Celsius: %f - Fahrenheit: %f" % (readings[0], readings[1])
        time.sleep(3)


if __name__ == '__main__':
    try:
        loop()
    except KeyboardInterrupt:  # When 'Ctrl+C' is pressed
        exit()
