/***************************************************************************
  Per sensore BME280 humidity, temperature & pressure sensor e scermo
  Oled 128x32 0.91''

  Libreria di partenza: Adafruit

  Installare le librerie richieste (vedi import statement).

  ---
  Per far funzionare correttamente questo sketch, ho dovuto modificare
  l'indirizzo i2c nella libreria di adafruit, come descritto qui:
  https://forum.arduino.cc/index.php?topic=400394.0

      Changing #define BME280_ADDRESS (0x77) for 
      #define BME280_ADDRESS (0x76) in the library's
      Adafruit_BME280.h solved the problem.

  Questo perchè il mio sensore ha l'indirizzo diverso e non è modificabile.
  ---

  Se colleghiamo un bme280 e lo screen Oled 128x32 all'arduino Nano usando
  l'interfaccia i2c, vedremo comparire i valori di temperatura, umidità
  e pressione :)

 ***************************************************************************/

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#include "U8glib.h"


//#define BME_SCK 13
//#define BME_MISO 12
//#define BME_MOSI 11
//#define BME_CS 10

#define SEALEVELPRESSURE_HPA (1013.25)

// per il display Oled
U8GLIB_SSD1306_128X32 u8g(U8G_I2C_OPT_NONE);  // I2C / TWI 


Adafruit_BME280 bme; // I2C
//Adafruit_BME280 bme(BME_CS); // hardware SPI
//Adafruit_BME280 bme(BME_CS, BME_MOSI, BME_MISO, BME_SCK); // software SPI

unsigned long delayTime;
int temp=0;
int pressione=0;
int umidita=0;
String baseTemp = "t: ";
String basePress = "p: ";
String baseUmi = "u: ";
String stringaTemp = "";
String stringaPress = "";
String stringaUmi = "";

void setup() {
    Serial.begin(9600);
    while(!Serial);    // time to get serial running
    Serial.println(F("BME280 test"));

    unsigned status;
    
    // default settings
    status = bme.begin();  
    // You can also pass in a Wire library object like &Wire2
    // status = bme.begin(0x76, &Wire2)
    if (!status) {
        Serial.println("Could not find a valid BME280 sensor, check wiring, address, sensor ID!");
        Serial.print("SensorID was: 0x"); Serial.println(bme.sensorID(),16);
        Serial.print("        ID of 0xFF probably means a bad address, a BMP 180 or BMP 085\n");
        Serial.print("   ID of 0x56-0x58 represents a BMP 280,\n");
        Serial.print("        ID of 0x60 represents a BME 280.\n");
        Serial.print("        ID of 0x61 represents a BME 680.\n");
        while (1) delay(10);
    }

    // setup screen Oled
    // assign default color value
    if ( u8g.getMode() == U8G_MODE_R3G3B2 ) {
      u8g.setColorIndex(255);     // white
    }
    else if ( u8g.getMode() == U8G_MODE_GRAY2BIT ) {
      u8g.setColorIndex(3);         // max intensity
    }
    else if ( u8g.getMode() == U8G_MODE_BW ) {
      u8g.setColorIndex(1);         // pixel on
    }
    else if ( u8g.getMode() == U8G_MODE_HICOLOR ) {
      u8g.setHiColorByRGB(255,255,255);
    }
    
    pinMode(8, OUTPUT);
    
    delayTime = 6000;

    Serial.println();
}

int getTemp() {
  return bme.readTemperature();
}

int getPress() {
  return bme.readPressure() / 100.0F;
}

int getUmi() {
  return bme.readHumidity();
}


void draw(String temp, String pressione) {
  // graphic commands to redraw the complete screen should be placed here  
  u8g.setFont(u8g_font_unifont);
  u8g.setPrintPos(0,10);
  //u8g.setFont(u8g_font_osb21);
  u8g.print(temp);

  u8g.setPrintPos(0,25);
  u8g.print(pressione);

}

void loop() { 
    printValues();

    temp = getTemp();
    pressione = getPress();
    umidita = getUmi();
    stringaUmi = String(baseUmi + umidita);
    stringaTemp = String(baseTemp + temp + "C | " + stringaUmi + "%");
    stringaPress = String(basePress + pressione + " hPa");

    // picture loop
    u8g.firstPage();  
    do {
      draw(stringaTemp, stringaPress);
    } while( u8g.nextPage() );
    
    delay(delayTime);
}


void printValues() {
    Serial.print("Temperature = ");
    Serial.print(bme.readTemperature());
    Serial.println(" *C");

    Serial.print("Pressure = ");

    Serial.print(bme.readPressure() / 100.0F);
    Serial.println(" hPa");

    Serial.print("Approx. Altitude = ");
    Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
    Serial.println(" m");

    Serial.print("Humidity = ");
    Serial.print(bme.readHumidity());
    Serial.println(" %");
    Serial.println();
}
