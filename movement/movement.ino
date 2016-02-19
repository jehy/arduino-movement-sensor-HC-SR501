int pirPin = 8;
int val;
int redPin = 11;
int greenPin = 10;
int bluePin = 9;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  setColor(255, 0, 0);  // red
  delay(1000);
  setColor(0, 255, 0);  // green
  delay(1000);
  setColor(0, 0, 255);  // blue
  delay(1000);
  setColor(255, 255, 0);// yellow
  delay(1000);  
  setColor(80, 0, 80);  // purple
  delay(1000);
  setColor(0, 255, 255);// aqua
  delay(1000);
  
  Serial.begin(9600);
}

void loop() {
  val = digitalRead(pirPin); //read state of the PIR
  if (val == LOW) {
    setColor(0, 255, 0);  // green
    Serial.println("No motion"); //if the value read is low, there was no motion
  }
  else {
    setColor(255, 0, 0);  // red
    Serial.println("Motion!"); //if the value read was high, there was motion
    delay(2500);
  }
  delay(50);
}

void setColor(int red, int green, int blue)
{
#ifdef COMMON_ANODE
  red = 255 - red;
  green = 255 - green;
  blue = 255 - blue;
#endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
