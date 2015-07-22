/*
 * Find the Adafruit-BMP085-Library at
 * https://github.com/adafruit/Adafruit-BMP085-Library
 */

#include <Wire.h>
#include <Adafruit_BMP085.h>


Adafruit_BMP085 bmp;

void setup() {
  Serial.begin(9600);
  if(!bmp.begin()){
    Serial.println("Sensor not found");
    while(1){}
  }
}

void loop() {
  Serial.print("Temperature: ");
  Serial.print(bmp.readTemperature());
  Serial.println(" *C");

  Serial.print("Pressure: ");
  Serial.print(bmp.readPressure());
  Serial.println(" Pa");

  Serial.print("Altitude: ");
  Serial.print(bmp.readAltitude());
  Serial.println(" meters");

  // you can get a moe precise measurement of altitude if you know the current sea level.
  // if it is 1015 milibars which is 101500 Pascals the use it like this
  Serial.print("More Accurate Altitude: ");
  Serial.print(bmp.readAltitude(101500));
  Serial.println(" meters");

  delay(500);
}
