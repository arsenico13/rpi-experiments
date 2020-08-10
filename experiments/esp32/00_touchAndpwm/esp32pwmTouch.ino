/*
 * ESP32 + IRF520 Mosfet driver module
 * Sfrutta la possibilità di usare i pin come sensori touch.
 * Sfrutta gli interrupt.
 * 
 * 2 Touch in uso:
 * - GPIO12
 * - GPIO13
 * 
 * segnale pwm nel GPIO16 <--> SIG nel modulo IRF520
 * 
 * Toccando GPIO13: full duty cicle pwm (accendi le luci full power)
 * Toccando GPIO12: spegni tutto, duty cicle 0
*/

// PWM
const int ledPin = 16; // ovvero GPIO16
const int freq = 5000;
const int ledChannel = 0;
const int resolution = 8;

// Touch
const int threshold = 40;
bool touch1detected = false;
bool touch2detected = false;


void IRAM_ATTR gotTouch1(){
 touch1detected = true;
 ledcWrite(ledChannel, 255);
}

void IRAM_ATTR gotTouch2(){
 touch2detected = true;
 ledcWrite(ledChannel, 0);
}

void setup() {
  Serial.begin(115200);
  delay(1000); // give me time to bring up serial monitor
  Serial.println("ESP32 Touch Interrupt and PWM Test");
  touchAttachInterrupt(T4, gotTouch1, threshold);
  touchAttachInterrupt(T5, gotTouch2, threshold);

  // PWM
  ledcSetup(ledChannel, freq, resolution);
  ledcAttachPin(ledPin, ledChannel); // associa il canale alla GPIO specificata
}

void loop(){
  if(touch1detected){
    touch1detected = false;
    Serial.println("Touch 1 detected");
  }
  if(touch2detected){
    touch2detected = false;
    Serial.println("Touch 2 detected");
  }
}
