#include <Arduino.h>
long duration;
int distance;

void setup() {
  // Define inputs and outputs:
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
  //Begin Serial communication at a baudrate of 9600:
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(50);
}
