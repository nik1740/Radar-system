#include <Servo.h>
const int trigPin =10;
const int echoPin =11;
const int ledPin = 9;
const int buzzerPin =8;
long duration;
int distance;

Servo motor1;
void setup() {
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(ledPin,OUTPUT);
  pinMode(buzzerPin,OUTPUT);
  motor1.attach(12);
  Serial.begin(9600);
}
int findDistance() {
  digitalWrite(trigPin,LOW);
delayMicroseconds(2);
digitalWrite(trigPin,HIGH);
delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
duration = pulseIn(echoPin,HIGH);
distance = 0.034*duration/2;
return distance;
}
void loop() {
  int distance = findDistance();
  if(distance<100){
    digitalWrite(ledPin,HIGH);
    tone(buzzerPin,1000);
    Serial.println("Enemy in proximity! ");
  } else {
    digitalWrite(ledPin,LOW);
    noTone(buzzerPin);
  }
  for (int i=30;i<=270;i++){
    motor1.write(i);
    delay(30);
    distance = findDistance();
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print("m.");
}
  for (int i=270;i<=30;i--){
   motor1.write(i);
    delay(30);
    distance = findDistance();
    distance = findDistance();
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print("m.");    

}
  
  }

