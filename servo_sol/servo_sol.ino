#include <Servo.h>
Servo myservo;
int pos = 0;
int pos1 = 1;
int pos2 = 0;
int sensorPin = A0;

void setup() {
  // put your setup code here, to run once:
  pinMode(5, OUTPUT);
  pinMode(A1, INPUT);
  pinMode(A0, INPUT);
  
  
  myservo.attach(5);
  Serial.begin(115200);
}

void loop() {
 float sensorPin = A0; 
 float sensorValue1 = analogRead(A1);
 float sensorValue0 = analogRead(A0);
 
  
  if (sensorValue1 == sensorValue0) {
    myservo.write(90);
    Serial.println("Perfect");
    }
  else if (sensorValue0 < sensorValue1){
    myservo.write(120);
    int valueString = (pos1-1, pos2);
    Serial.println(sensorPin);
    Serial.println(sensorValue1);
    Serial.println("Less");
  }
  else if (sensorValue0 > sensorValue1 + ){
    myservo.write(60);
    Serial.println("Over");
  }
  delay(200);
    }
