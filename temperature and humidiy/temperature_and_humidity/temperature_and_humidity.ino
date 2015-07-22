#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN,DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("Testing DHT Sensor");
  dht.begin();

}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  if(isnan(temperature) || isnan(humidity)){
    Serial.println("DHT could not be read!");
  }else{
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.print(" %\t");
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" *C");
  }
  delay(500);
}
