/*
CSC 899: DIY Burglar Alarm
Arno Puder, Pratik Jaiswal

Arduino program to make a piezo element make sound on sensing by an Ultransonic senor and make LED blink
*/

//Setting up the pins
#define redLED 10
#define whiteLED 11
#define trigPIN 12
#define echoPIN 13
   
int sensorDIST = 200;
boolean triggered = false;
 
void setup() {
  Serial.begin (9600);
  pinMode(redLED, OUTPUT);
  pinMode(whiteLED, OUTPUT);
  pinMode(trigPIN, OUTPUT);
  pinMode(echoPIN, INPUT);
  pinMode(9, OUTPUT);
 
  long duration, distance;
 
  /*
  Begin calibration: Arduino takes around 5 seconds to set itself and so, hold on.
  */
 
  digitalWrite(redLED, HIGH); 
  digitalWrite(whiteLED, HIGH);
  digitalWrite(9, 20);
 
  while (millis() < 5000) {
      digitalWrite(trigPIN, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPIN, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPIN, LOW);
      duration = pulseIn(echoPIN, HIGH);
      distance = (duration / 2) / 29.1;
      if (distance < sensorDIST) {
        sensorDIST = distance;
      }
   }
   
   // finish calibration
   digitalWrite(redLED, LOW); 
   digitalWrite(whiteLED, LOW);
   digitalWrite(9, 0);
}
 
void loop() {
  if (triggered) {
    digitalWrite(redLED, HIGH);
    digitalWrite(whiteLED, LOW);
    digitalWrite(9, 20);
    delay(500);
    digitalWrite(redLED, LOW);
    digitalWrite(whiteLED, HIGH);
    digitalWrite(9, 0);
    delay(500);
  } else {
    long duration, distance;
    digitalWrite(trigPIN, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPIN, LOW);
    duration = pulseIn(echoPIN, HIGH);
    distance = (duration/2) / 29.1;
    if (distance < sensorDIST - 10) {
      triggered = true;
    }
    delay(20);
  }
}
