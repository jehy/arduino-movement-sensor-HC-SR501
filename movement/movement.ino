#define pirPin  8
#define WAIT_MOVE 10000
#define RELAY1  2

unsigned long previousMillis = 0;

void setup() {
  pinMode(pirPin, INPUT);
  Serial.begin(9600);
  pinMode(RELAY1, OUTPUT);
}

void loop() {

  unsigned long currentMillis = millis();


  int val = digitalRead(pirPin); //read state of the PIR
  if (val == LOW && (currentMillis - previousMillis > WAIT_MOVE)) {
    digitalWrite(RELAY1, 1);          // Turns OFF Relays 1
    Serial.println("No motion"); //if the value read is low, there was no motion
  }
  else {
    digitalWrite(RELAY1, 0);          // Turns ON Relays 1
    Serial.println("Motion!"); //if the value read was high, there was motion
    previousMillis = currentMillis;
    delay(2500);
  }
  delay(50);
}

