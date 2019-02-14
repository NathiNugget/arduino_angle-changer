#include <Servo.h>
Servo myservo;
int sensorPin = A0;
// Her defineres alle Servo som myservo og A0 defineres som sensorPin

void setup() {
  // Ben 5 sættes til digitalt PWM-output, A0 og A1 er input
  pinMode(5, OUTPUT);
  pinMode(A1, INPUT);
  pinMode(A0, INPUT);
  
  
  // Servo forbindes til ben 5 og der bliver printet til Serial monitor med en Baud-rate på 115.200. 
  myservo.attach(5);
  Serial.begin(115200);
}

// Her begyndes det primære loop, hvor vi har tre forskellige muligheder for servoen. 
// Der foretages analog læsning af ben A0 og A1. 
void loop() {
 float sensorValue1 = analogRead(A1);
 float sensorValue0 = analogRead(A0);
 
  // Her startes første loop hvor sensor 1 og sensor 2 sammenlignes. Er de lig hinanden indstilles servoen 
  // til vinkel 90, som er neutral - servoen står stille. 
  if (sensorValue1 == sensorValue0) {
    myservo.write(90);
    Serial.println("Perfect");
    }
  // Her begynder andet tilfælde, hvor den ene sensor er større end den anden. Servoen drejer frem. 
  // Dette printes 
  else if (sensorValue0 < sensorValue1){
    myservo.write(120);
    Serial.println(sensorValue0);
    Serial.println(sensorValue1);
    Serial.println("Less");
  }
  // Sidste mulighed begynder her, servoen drejer tilbage. Resultatet og værdi printes til serial monitor
  else if (sensorValue0 > sensorValue1){
    myservo.write(60);
    Serial.println("Over");
  }
  delay(200);
    }
