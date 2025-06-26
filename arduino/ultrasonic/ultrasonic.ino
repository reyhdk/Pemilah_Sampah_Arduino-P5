#include <Servo.h>

long jarak, waktu; 
Servo servo1;
#define trigpin 13
#define echopin 12

void setup() {
  // put your setup code here, to run once:
  servo1.attach(5);
pinMode (trigpin, OUTPUT);
pinMode (echopin, INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trigpin, LOW);
delayMicroseconds(2);
digitalWrite (trigpin, HIGH);
delayMicroseconds(10); 
digitalWrite(trigpin, LOW);

waktu = pulseIn(echopin, HIGH);
jarak = (waktu * 0.0343) / 2;
Serial.println(jarak);

if (jarak < 20 ){
  servo1.write(180);
}if (jarak>20) {
  servo1.write(0);

}
}
