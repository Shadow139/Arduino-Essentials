
int ledPin = 13;
int inputPin = 2;
int pirState = LOW;
int val = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(inputPin, INPUT);

  Serial.begin(9600);
}

void loop() {
  val = digitalRead(inputPin);
  if (val == HIGH) {
    digitalWrite(ledPin, HIGH);
    if (pirState == LOW) {
      // We just turned it on
      Serial.println("Motion");
      pirState = HIGH;
    }
  }else{
    digitalWrite(ledPin,LOW);
    if(pirState == HIGH){
      Serial.println("Motion ended");
      pirState = LOW;
    }
  }

}
