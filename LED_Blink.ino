/*
CSC 899: DIY Burglar Alarm
Pratik Jaiswal, Arno Puder

Arduino program to make its LED blink
*/

// LED is connected to digital pin 13
#define LED1 10

#define LED2 11

#define LED3 9

//Set the digital pin as output
void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}
/* This loop will make sure that LED turns on and then,
waits for a second to make it off again. And the process 
repeats, wating - on - waiting - off and so on*/

void loop() {
  
  digitalWrite(LED1, HIGH);
  delay(100);
  digitalWrite(LED1, LOW);
  delay(100);  
  
  {
    digitalWrite(LED2, HIGH);
    delay(100);
    digitalWrite(LED2, LOW);
    delay(100);
  }
  
  {
    digitalWrite(LED3, HIGH);
    delay(100);
    digitalWrite(LED3, LOW);
    delay(100);
  }
  
}

