#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE_PIN   9
#define CSN_PIN 10

const uint64_t pipe = 0xE8E8F0F0E1LL; // Define the transmit pipe

RF24 radio(CE_PIN, CSN_PIN); // Create a Radio

int E1 = 5;
int M1 = 4;
int E2 = 6;
int M2 = 7;



/*-----( Declare Variables )-----*/
int joystick[2];  // 2 element array holding Joystick readings

void setup() {
  Serial.begin(9600); 
  
  delay(1000);
  Serial.println("Nrf24L01 Receiver Starting");
  radio.begin();
  radio.openReadingPipe(1,pipe);
  radio.startListening();;
    
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);

}

void loop() {

  if ( radio.available() )
  {
    // Read the data payload until we've received everything
    bool done = false;
    while (!done)
    {
      // Fetch the data payload
      done = radio.read( joystick, sizeof(joystick) );
      Serial.print("X = ");
      Serial.print(joystick[0]);
      Serial.print(" Y = ");      
      Serial.println(joystick[1]);
    }
  }
  else
  {    
      Serial.println("No radio available");
  }
  
    digitalWrite(M1,HIGH);
    digitalWrite(M2,HIGH);
  
    analogWrite(E1,joystick[1]);
    analogWrite(E2,joystick[1]);
    delay(25);
}
