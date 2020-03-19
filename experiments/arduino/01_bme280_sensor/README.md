# Sensore bme280 + schermo Oled 128x32

> Marzo 2020


## Obiettivo

È da tempo che ho in mente di mettere insieme una piccola stazione metereologica
personale e finalmente mi sono deciso ad acquistare il sensore giusto per
cominciare: un bme280, pressione, umidità, temperatura.
Con questo sketch volevo provare la lettura dei dati e la visualizzazione degli
stessi su un piccolo schermo.


## Link utili / risorse

- https://learn.adafruit.com/adafruit-bme280-humidity-barometric-pressure-temperature-sensor-breakout


## Collegamenti

Sia il sensore `bme280` che lo schermo oled sono dotati di 4 pin e vanno
collegati come segue:

bme280/Oled | Arduino Nano
--- | ---
GND | GND
Vcc | 5v
SCL | A5
SDA | A4


## Dipendenze

Scaricare/installare le seguenti librerie (sono tutte disponibili direttamente
dal manager di Arduino IDE):

- `adafruit bme280`
- `Adafruit Unified Sensor`
- `U8glib`


---

Per vedere l'esempio del risultato, controllare le risorse nella cartella `pics`.


---
