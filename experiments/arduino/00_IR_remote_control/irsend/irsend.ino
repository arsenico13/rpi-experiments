// tutorial followed: at http://www.ladyada.net/learn/sensors/ir.html
// this code is public domain, please enjoy!

int IRledPin =  13;    // LED connected to digital pin 13

void setup()   {
  // initialize the IR digital pin as an output:
  pinMode(IRledPin, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  Serial.println("Ready to send IR signal");

  Serial.println("Sending...");
  SendLighCode();

  Serial.println("Wait 5 seconds.");
  delay(5*1000);  // wait 5 seconds (5 seconds * 1000 milliseconds)

  Serial.println("Sending...");
  SendLighCode();

  Serial.println("Wait 5 seconds.");
  delay(5*1000);  // wait 5 seconds (5 seconds * 1000 milliseconds)
}


// This procedure sends a 38KHz pulse to the IRledPin
// for a certain # of microseconds. We'll use this whenever we need to send codes
void pulseIR(long microsecs) {
  // we'll count down from the number of microseconds we are told to wait

  cli();  // this turns off any background interrupts

  while (microsecs > 0) {
    // 38 kHz is about 13 microseconds high and 13 microseconds low
   digitalWrite(IRledPin, HIGH);  // this takes about 3 microseconds to happen
   delayMicroseconds(10);         // hang out for 10 microseconds, you can also change this to 9 if its not working
   digitalWrite(IRledPin, LOW);   // this also takes about 3 microseconds
   delayMicroseconds(10);         // hang out for 10 microseconds, you can also change this to 9 if its not working

   // so 26 microseconds altogether
   microsecs -= 26;
  }

  sei();  // this turns them back on
}


void SendLighCode() {
    pulseIR(1340);
    delayMicroseconds(400);
    pulseIR(1320);
    delayMicroseconds(420);
    pulseIR(460);
    delayMicroseconds(1300);
    pulseIR(440);
    delayMicroseconds(1300);
    pulseIR(440);
    delayMicroseconds(1300);
    pulseIR(440);
    delayMicroseconds(1300);
    pulseIR(440);
    delayMicroseconds(1300);
    pulseIR(420);
    delayMicroseconds(1320);
    pulseIR(420);
    delayMicroseconds(1300);
    pulseIR(440);
    delayMicroseconds(1320);
    pulseIR(1260);
    delayMicroseconds(400);
    pulseIR(460);
    delayMicroseconds(8680);
    pulseIR(1340);
    delayMicroseconds(400);
    pulseIR(1340);
    delayMicroseconds(200);
    pulseIR(780);
    delayMicroseconds(1200);
    pulseIR(440);
    delayMicroseconds(1300);
    pulseIR(440);
    delayMicroseconds(1280);
    pulseIR(460);
    delayMicroseconds(1280);
    pulseIR(440);
    delayMicroseconds(1300);
    pulseIR(440);
    delayMicroseconds(1300);
    pulseIR(440);
    delayMicroseconds(1300);
    pulseIR(440);
    delayMicroseconds(1300);
    pulseIR(1280);
    delayMicroseconds(380);
    pulseIR(480);
    delayMicroseconds(8680);
    pulseIR(1340);
    delayMicroseconds(400);
    pulseIR(1340);
    delayMicroseconds(400);
    pulseIR(460);
    delayMicroseconds(1300);
    pulseIR(440);
    delayMicroseconds(1300);
    pulseIR(440);
    delayMicroseconds(1300);
    pulseIR(440);
    delayMicroseconds(1300);
    pulseIR(440);
    delayMicroseconds(1300);
    pulseIR(440);
    delayMicroseconds(1300);
    pulseIR(440);
    delayMicroseconds(1300);
    pulseIR(440);
    delayMicroseconds(200);
    pulseIR(440);
    delayMicroseconds(660);
    pulseIR(1280);
    delayMicroseconds(380);
    pulseIR(460);
    delayMicroseconds(8680);
    pulseIR(1340);
    delayMicroseconds(400);
    pulseIR(1340);
    delayMicroseconds(400);
    pulseIR(460);
    delayMicroseconds(1320);
    pulseIR(440);
    delayMicroseconds(1300);
    pulseIR(440);
    delayMicroseconds(1280);
    pulseIR(460);
    delayMicroseconds(1300);
    pulseIR(420);
    delayMicroseconds(1300);
    pulseIR(440);
    delayMicroseconds(1300);
    pulseIR(440);
    delayMicroseconds(1300);
    pulseIR(440);
    delayMicroseconds(1300);
    pulseIR(1280);
    delayMicroseconds(400);
    pulseIR(460);
    delayMicroseconds(8700);
    pulseIR(1320);
    delayMicroseconds(400);
    pulseIR(1340);
    delayMicroseconds(400);
    pulseIR(460);
    delayMicroseconds(1320);
    pulseIR(420);
    delayMicroseconds(1300);
    pulseIR(440);
    delayMicroseconds(1300);
    pulseIR(440);
    delayMicroseconds(1300);
    pulseIR(440);
    delayMicroseconds(1300);
    pulseIR(440);
    delayMicroseconds(1300);
    pulseIR(440);
    delayMicroseconds(1300);
    pulseIR(440);
    delayMicroseconds(1300);
    pulseIR(1280);
    delayMicroseconds(380);
    pulseIR(480);
    delayMicroseconds(8700);
    pulseIR(1320);
    delayMicroseconds(400);
    pulseIR(1320);
    delayMicroseconds(420);
    pulseIR(460);
    delayMicroseconds(1300);
    pulseIR(440);
    delayMicroseconds(1300);
    pulseIR(440);
    delayMicroseconds(1300);
    pulseIR(440);
    delayMicroseconds(1300);
    pulseIR(440);
    delayMicroseconds(1300);
    pulseIR(440);
    delayMicroseconds(460);
    pulseIR(220);
    delayMicroseconds(620);
    pulseIR(420);
    delayMicroseconds(1320);
    pulseIR(420);
    delayMicroseconds(1300);
    pulseIR(1300);
    delayMicroseconds(380);
    pulseIR(460);
    delayMicroseconds(8680);
    pulseIR(1340);
    delayMicroseconds(420);
    pulseIR(1320);
    delayMicroseconds(400);
    pulseIR(460);
    delayMicroseconds(1320);
    pulseIR(440);
    delayMicroseconds(1300);
    pulseIR(440);
    delayMicroseconds(1300);
    pulseIR(400);
    delayMicroseconds(1340);
    pulseIR(400);
    delayMicroseconds(1340);
    pulseIR(400);
    delayMicroseconds(1340);
    pulseIR(400);
    delayMicroseconds(1320);
    pulseIR(420);
    delayMicroseconds(1320);
    pulseIR(1280);
    delayMicroseconds(400);
    pulseIR(460);
    delayMicroseconds(8680);
    pulseIR(1300);
    delayMicroseconds(440);
    pulseIR(1340);
    delayMicroseconds(400);
    pulseIR(460);
    delayMicroseconds(1300);
    pulseIR(420);
    delayMicroseconds(1340);
    pulseIR(400);
    delayMicroseconds(1320);
    pulseIR(420);
    delayMicroseconds(1320);
    pulseIR(420);
    delayMicroseconds(1320);
    pulseIR(400);
    delayMicroseconds(1340);
    pulseIR(400);
    delayMicroseconds(1340);
    pulseIR(400);
    delayMicroseconds(1340);
    pulseIR(1280);
    delayMicroseconds(380);
    pulseIR(480);
}
