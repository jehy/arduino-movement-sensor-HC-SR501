#define pirPin  8
#define WAIT_MOVE 60000
#define RELAY1  2

unsigned long previousMillis = 0;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(RELAY1, OUTPUT);
  Serial.begin(9600);
  
  digitalWrite(RELAY1, 1);          // Turns OFF Relays 1
  delay(500);
  digitalWrite(RELAY1, 0);          // Turns OFF Relays 1
}

void loop() {

  unsigned long currentMillis = millis();
  int val = digitalRead(pirPin); //read state of the PIR
  if (val == LOW) {
    if ((currentMillis - previousMillis < WAIT_MOVE))
      return;
    Serial.println("No motion"); //if the value read is low, there was no motion
    digitalWrite(RELAY1, 0);          // Turns OFF Relays 1
  }
  else {
    Serial.println("Motion! Light on for timeout"); //if the value read was high, there was motion
    digitalWrite(RELAY1, 1);          // Turns ON Relays 1
    previousMillis = currentMillis;
    delay(2500);
  }
  delay(50);
}

