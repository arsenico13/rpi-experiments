# Connections / Wiring up

- Connect the ground-pin the the ground on the pi.
- Connect the VCC to the 5V output from the pi.
- Connect the signal-pinn the the gpio4 of the pi (pin number 7).


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
