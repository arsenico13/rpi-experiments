# IR remote control

Settembre 2017


## Obiettivo

Questo esperimento ha un obiettivo specifico ed un'applicazione reale:
riuscire a replicare il comando infrarosso inviato dal telecomando del
lampadario presente in camera mia per poter accendere la luce usando un
interruttore normale (e non per forza il telecomando, unico sistema previsto
dal produttore del lampatadio per poter accendere la luce).


### Piccola nota per il futuro...

**"Never trust the manufacturer blindly"** dice GreatScott ( https://www.youtube.com/channel/UC6mIxFTvXkWQVEHPsEdflzQ)
in uno dei suoi video.

Parole sante.


### Link utili / Risorse

- https://learn.adafruit.com/ir-sensor
- https://www.modmypi.com/blog/raspberry-pis-remotes-ir-receivers
- https://www.stavros.io/posts/how-turn-your-raspberry-pi-infrared-remote-control/


## Inizialmente...

### IR receiver con Raspberry Pi

Per poter replicare un segnale bisogna prima *sapere com'è fatto questo segnale*,
leggerlo e saperlo replicare.

Inizialmente pensavo di poter leggere il segnale originale del telecomando con
il mio Rpi 2 B+:

- Raspberry Pi 2 B+
- Ricevitore IR: quello presente nel *Sensor Kit v2.0 for Raspberry Pi B+*
  della SunFounder.

Dopo diverse prove, scopro che il raspberry fa molta
più fatica a generare correttamente segnali IR con la frequenza giusta (a causa
del suo essere un OS completo e non un semplice microcontrollore).

Per questo motivo sono passato ad Arduino.


## Arduino / IR

### IR remote signal

    https://learn.adafruit.com/ir-sensor/ir-remote-signals
    https://learn.adafruit.com/ir-sensor/using-an-ir-sensor


Prima dobbiamo leggere il segnale sorgente del telecomando.

Ho collegato il modulo IR ad Arduino:

    GND > GND
    Vcc > 5V
    SIG > Digital pin 2

Scaricato il codice di adafruit per decodificare un segnale IR, caricato su
arduino output salvato (diverse decine di righe di codice).
Un piccolo estratto:

```
Ready to decode IR!

Received:

OFF 	ON
17452 usec, 1340 usec
380 usec, 1360 usec
380 usec, 480 usec
1280 usec, 460 usec
1260 usec, 480 usec
1260 usec, 480 usec
1260 usec, 480 usec
1260 usec, 480 usec
1260 usec, 480 usec
1260 usec, 480 usec
1260 usec, 1300 usec
400 usec, 460 usec
...
...
```

Ho fatto più catture e più prove. Il segnale del telecomando risultava sempre
strano/disturbato, variava molto tra una cattura e l'altra (non ho per nulla
idea del perchè).

Il programma di adafruit restituisce anche il codice da poter copiare-incollare
con già i valori ON/OFF per l'emettitore IR, tipo:


```
int IRsignal[] = {
// ON, OFF
pulseIR(1340);
delayMicroseconds(400);
pulseIR(1340);
delayMicroseconds(400);
pulseIR(460);
delayMicroseconds(1280);
pulseIR(480);
delayMicroseconds(1260);
pulseIR(480);
delayMicroseconds(1260);
...
...
```


### Emissione IR

Il modulo usato per l'emissione è quello che ho nel kit di 37 sensori
della Elegoo (vedi immagine nelle risorse) acquistato su Amazon.

Tutto funzionante.

Il codice utilizzato è `irsend.ino`. Loop ogni 5 secondi ed emette la sequenza
IR per accendere/spegnere la luce.



## Emissione del segnale alla pressione di un bottone

Dopo tutto il lavoro fatto in precedenza, qui in realtà c'è poco da fare se non
chiamare la funzione che emette il segnale IR alla pressione di un bottone.

Per informazioni su come usare un bottone con Arduino: https://www.arduino.cc/en/Tutorial/Button.

Il codice che è stato utilizzato è `irsendbutton.ino` e l'intero progetto è
stato poi completato su una scheda Arduino Nano compatibile.











---





---
