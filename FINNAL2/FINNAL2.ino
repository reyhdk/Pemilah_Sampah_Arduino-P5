#include <Servo.h>
long jarak, waktu; 
Servo servo1;
Servo servo2;
Servo servo3;
#define trigpin 13
#define echopin 12
int induksi_pin = 8; //induksi NPN ( 0 itu yes, 1 itu no) kebalik 
int val;
int soil_pin = A0;
int output_value = 0;

void setup(){
  pinMode(induksi_pin,INPUT);
   servo1.attach(5);
   servo2.attach(6);
   servo3.attach(7);
  pinMode (trigpin, OUTPUT);
  pinMode (echopin, INPUT);
  pinMode(soil_pin,INPUT);
  servo1.write(0);
  servo2.write(90);
  servo3.write(90);
  Serial.begin(9600);
}

void loop(){

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

  val = digitalRead(induksi_pin);

  if (val==0)
  {
  Serial.println("sampah metal terdeteksi");
  delay(100);
  servo2.write(0);
   
  }
  if (val==1)
  {
   Serial.println("sampah metal tidak terdeteksi");
  delay(700);
  servo2.write(180);
  
  }
   output_value = analogRead(soil_pin);
  Serial.print(" sensor : ");
  Serial.println(output_value);
  delay(1000);


   if (output_value > 550){
  servo3.write(0);
  Serial.println(" sampahnya kering");
 
  }
  else {
  servo3.write(180);
  Serial.println("sampahnya basah");
  
    }
}
void servo1On(){

}

void servo1Off(){

}

void servo2On(){

}

void servo2Off(){

}