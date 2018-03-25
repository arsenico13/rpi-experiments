# Connections / Wiring up

- Connect the ground-pin the the ground on the pi.
- Connect the VCC to the 5V output from the pi.
- Connect the signal-pin the the gpio4 of the pi (board-pin number 7).

### Useful links

https://francoz.me/dht11-sensor-on-raspberry-pi2-gdocs-logging/
http://www.circuitbasics.com/how-to-set-up-the-dht11-humidity-sensor-on-the-raspberry-pi/


## Instructions

    sudo apt-get install build-essential python-dev

Install Adafruit_Python_DHT library from github:

    git clone https://github.com/adafruit/Adafruit_Python_DHT.git
    cd Adafruit_Python_DHT
    sudo python setup.py install


# OneWire support

Change the file `/boot/config.txt`.


Add the following line:

    dtoverlay=w1-gpio,gpiopin=4

Reboot the system, then:

    sudo modprobe w1-gpio
    sudo modprobe w1-therm

    cd /sys/bus/w1/devices
    ls

You find a folder with a long string of numbers. Change into that directory.

    cd XX-XX....

    cat w1_slave

This file is the output from the sensor.

---
