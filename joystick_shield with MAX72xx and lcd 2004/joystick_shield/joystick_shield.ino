#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Store the Arduino pin associated with each input

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

// Select button is triggered when joystick is pressed
const byte PIN_BUTTON_SELECT = 8; 

const byte PIN_BUTTON_F = 7;
const byte PIN_BUTTON_E = 6;

const byte PIN_BUTTON_RIGHT = 3;
const byte PIN_BUTTON_UP = 2;
const byte PIN_BUTTON_DOWN = 4;
const byte PIN_BUTTON_LEFT = 5;

const byte PIN_ANALOG_X = 0;
const byte PIN_ANALOG_Y = 1;

uint8_t joystick[2];  // 2 element array of unsigned 8-bit type, holding Joystick readings

// Matrix

int pinCS = 10;

Max72xxPanel matrix = Max72xxPanel(pinCS,1,1);

void setup() {
  Serial.begin(9600);

  matrix.setIntensity(4);

  lcd.begin(16,2);
  lcd.backlight(); // finish with backlight on  

  pinMode(PIN_BUTTON_RIGHT, INPUT);
  digitalWrite(PIN_BUTTON_RIGHT, HIGH);

  pinMode(PIN_BUTTON_LEFT, INPUT);
  digitalWrite(PIN_BUTTON_LEFT, HIGH);

  pinMode(PIN_BUTTON_UP, INPUT);
  digitalWrite(PIN_BUTTON_UP, HIGH);

  pinMode(PIN_BUTTON_DOWN, INPUT);
  digitalWrite(PIN_BUTTON_DOWN, HIGH);

  pinMode(PIN_BUTTON_SELECT, INPUT);
  digitalWrite(PIN_BUTTON_SELECT, HIGH);
  
  pinMode(PIN_BUTTON_E, INPUT);
  digitalWrite(PIN_BUTTON_E, HIGH);
  
  pinMode(PIN_BUTTON_F, INPUT);
  digitalWrite(PIN_BUTTON_F, HIGH);
}

void loop() {

  joystick[0] = map(analogRead(PIN_ANALOG_X), 0, 207, 0, 2);
  joystick[1] = map(analogRead(PIN_ANALOG_Y), 0, 207, 0, 2);

  //joystick[0] = analogRead(PIN_ANALOG_X);
  //joystick[1] = analogRead(PIN_ANALOG_Y);

  printSerial();
  printLCD();
  printMatrix();
 }


 
 void printMatrix(){
  matrix.fillScreen(0);
  
  matrix.drawPixel(joystick[0],7 - joystick[1],1);

  if(digitalRead(PIN_BUTTON_SELECT) == 0){
    matrix.drawPixel(3,3,1);
    matrix.drawPixel(4,3,1);
    matrix.drawPixel(3,4,1);
    matrix.drawPixel(4,4,1);
  }

  if(digitalRead(PIN_BUTTON_UP) == 0){
    matrix.drawPixel(3,0,1);
    matrix.drawPixel(4,0,1);
    matrix.drawPixel(3,1,1);
    matrix.drawPixel(4,1,1);
  }
  
  if(digitalRead(PIN_BUTTON_RIGHT) == 0){
    matrix.drawPixel(6,3,1);
    matrix.drawPixel(6,4,1);
    matrix.drawPixel(7,3,1);
    matrix.drawPixel(7,4,1);
  }

  if(digitalRead(PIN_BUTTON_DOWN) == 0){
    matrix.drawPixel(3,6,1);
    matrix.drawPixel(4,6,1);
    matrix.drawPixel(3,7,1);
    matrix.drawPixel(4,7,1);
  }

  if(digitalRead(PIN_BUTTON_LEFT) == 0){
    matrix.drawPixel(0,3,1);
    matrix.drawPixel(0,4,1);
    matrix.drawPixel(1,3,1);
    matrix.drawPixel(1,4,1);
  }

  if(digitalRead(PIN_BUTTON_F) == 0){
    matrix.drawPixel(0,6,1);
    matrix.drawPixel(0,7,1);
    matrix.drawPixel(1,6,1);
    matrix.drawPixel(1,7,1);
  }

  if(digitalRead(PIN_BUTTON_E) == 0){
    matrix.drawPixel(6,6,1);
    matrix.drawPixel(6,7,1);
    matrix.drawPixel(7,6,1);
    matrix.drawPixel(7,7,1);
  }
  
  matrix.write();
 }
 
 void printLCD(){
  lcd.setCursor(0,0); //Start at character 4 on line 0
  lcd.print("X ");
  lcd.print(joystick[0]);
  lcd.print(" Y ");
  lcd.print(joystick[1]);
  lcd.print(" F ");
  lcd.print(digitalRead(PIN_BUTTON_F));
  lcd.print(" E ");
  lcd.print(digitalRead(PIN_BUTTON_E));

  lcd.setCursor(0,1); //Start at character 4 on line 0
  lcd.print("U ");
  lcd.print(digitalRead(PIN_BUTTON_UP));
  lcd.print(" R ");
  lcd.print(digitalRead(PIN_BUTTON_RIGHT));
  lcd.print(" D ");
  lcd.print(digitalRead(PIN_BUTTON_DOWN));
  lcd.print(" L ");
  lcd.print(digitalRead(PIN_BUTTON_LEFT));
 }

 void printSerial(){
  
  Serial.print("U:");
  Serial.print(digitalRead(PIN_BUTTON_UP));
  Serial.print(" ");

  Serial.print("R:");
  Serial.print(digitalRead(PIN_BUTTON_RIGHT));
  Serial.print(" ");
  
  Serial.print("D:");
  Serial.print(digitalRead(PIN_BUTTON_DOWN));
  Serial.print(" ");
  
  Serial.print("L:");
  Serial.print(digitalRead(PIN_BUTTON_LEFT));
  Serial.print(" ");

  Serial.print("x:");
  Serial.print(joystick[0]);
  
  Serial.print(" ");

  Serial.print("y:");
  Serial.print(joystick[1]);
  Serial.print(" ");

  Serial.print("S:");
  Serial.print(digitalRead(PIN_BUTTON_SELECT));
  Serial.print(" ");
  
  Serial.print("F:");
  Serial.print(digitalRead(PIN_BUTTON_F));
  Serial.print(" ");
  
  Serial.print("E:");
  Serial.print(digitalRead(PIN_BUTTON_E));
  Serial.print(" ");

  Serial.println();
 }

