# ESP8266 - WiFi Module

Installato l' ESP8266 Arduino Core seguendo le istruzioni di questo repo: https://github.com/esp8266/Arduino.
Così facendo è possibile gestire questa board utilizzando l'IDE di Arduino.


#### Link utili

- https://medium.com/@cgrant/using-the-esp8266-wifi-module-with-arduino-uno-publishing-to-thingspeak-99fc77122e82
- Lista comandi AT: https://www.electronicshub.org/esp8266-at-commands/
- https://www.instructables.com/id/Arduino-IOT-Temperature-and-Humidity-With-ESP8266-/


## Comandi AT

#### AT+GMR

firmware version

```
AT+GMR

AT version:1.2.0.0(Jul  1 2016 20:04:45)
SDK version:1.5.4.1(39cb9a32)
v1.0.0
Mar 11 2018 18:27:31

OK
```

#### AT+CWMODE=?

mostra quali sono le opzioni possibili

```
T+CWMODE=?

+CWMODE:(1-3)

OK
```

#### AT+CWMODE?

mostra in quale modalità siamo

```
+CWMODE:2

OK
```

#### AT+CWMODE=1

cambia la modalità

1. Client
2. Access Point
3. Client and Access Point


#### AT+CWJAP?

query: a quale rete siamo collegati?

```
AT+CWJAP?

No AP

OK
```

#### AT+CWLAP

lista le reti disponibili.
Perchè questo comandi funzioni, la modalità non deve essere "2".

```
AT+CWLAP

+CWLAP:(3,"nome di una rete 1",-49,"aa:3b:bb:71:cc:c7",6,-37,0)
+CWLAP:(3,"nome di una rete 2",-85,"00:aa:0c:bb:15:cc",6,-52,0)

OK
```


#### AT+CWJAP="<SSID>","<pwd>"

accede ad una rete.


#### AT+CIFSR

mostra indirizzo IP assegnato alla scheda.

```
+CIFSR:STAIP,"192.168.1.230"
+CIFSR:STAMAC,"aa:dd:bb:ee:cc:ff"

OK
```


---
