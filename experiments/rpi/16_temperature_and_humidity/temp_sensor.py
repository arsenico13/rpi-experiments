#!/usr/bin/env python
# -*- coding: utf-8 -*-

import time
import Adafruit_DHT


def loop():
    while True:
        humidity, temperature = Adafruit_DHT.read_retry(11, 4)
        print 'Temp: {0:0.1f} C  Humidity: {1:0.1f} %'.format(temperature, humidity)
        time.sleep(3)


if __name__ == '__main__':
    try:
        loop()
    except KeyboardInterrupt:  # When 'Ctrl+C' is pressed
        exit()
