int redLed=2;
int greenLed=3;
int yellowLed=4;
int potPin=A0;
#include <Servo.h>
Servo myServo;
int servoPin=5;
int potValue;
int servoAngle;
int buzzerPin=6;

void setup()
{
pinMode(redLed,OUTPUT);
pinMode(greenLed,OUTPUT);
pinMode(yellowLed,OUTPUT);
pinMode(buzzerPin,OUTPUT);
  
myServo.attach(servoPin);
myServo.write(0);  
  
Serial.begin(9600);
  
Serial.println("---------");
Serial.println("Servo Motor Controller");
Serial.println("---------");
}

void loop()
{
potValue=analogRead(potPin);
servoAngle=map(potValue,0,1023,0,180);
if (servoAngle<=180 && servoAngle> 120)
 {
  digitalWrite(redLed,HIGH);
  digitalWrite(greenLed,LOW);
  digitalWrite(yellowLed,LOW);
  
  digitalWrite(buzzerPin,HIGH);
  delay(200);
  digitalWrite(buzzerPin,LOW);
  delay(200);  
 }
else if(servoAngle<=120 && servoAngle> 60)
 {
  digitalWrite(yellowLed,HIGH);
  digitalWrite(redLed,LOW);
  digitalWrite(greenLed,LOW);
  
  digitalWrite(buzzerPin,HIGH);
  delay(1000);
  digitalWrite(buzzerPin,LOW);
  delay(1000);  
 }  
else 
 {
  digitalWrite(greenLed,HIGH);
  digitalWrite(redLed,LOW);
  digitalWrite(yellowLed,LOW);  
  
  digitalWrite(buzzerPin,LOW);
 } 

  myServo.write(servoAngle);
  
Serial.print("Potentiometer: ");
Serial.print(potValue);
Serial.print("| Servo Angle: ");
Serial.println(servoAngle);  

}  