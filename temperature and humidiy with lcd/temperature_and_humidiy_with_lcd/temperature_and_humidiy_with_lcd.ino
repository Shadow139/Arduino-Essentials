#include "DHT.h"
#include <Wire.h>  // Comes with Arduino IDE
#include <LiquidCrystal_I2C.h>

#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN,DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address

void setup() {
  Serial.begin(9600);
  Serial.println("Testing DHT Sensor");
  lcd.begin(16,2);   // initialize the lcd for 16 chars 2 lines, turn on backlight
  lcd.backlight(); // finish with backlight on  
  
  dht.begin();

}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  if(isnan(temperature) || isnan(humidity)){
    lcd.setCursor(0,0); //Start at character 4 on line 0
    lcd.print("DHT could not ");
    lcd.setCursor(0,1);
    lcd.print("be read!");
    Serial.println("DHT could not be read!");
  }else{

    lcd.setCursor(0,0); //Start at character 4 on line 0
    lcd.print("Humidity: ");
    lcd.print(humidity);
    lcd.setCursor(0,1);
    lcd.print("Temp: ");
    lcd.print(temperature);
    lcd.print(" *C");
      
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.print(" %\t");
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" *C");
  }
  delay(500);
}

