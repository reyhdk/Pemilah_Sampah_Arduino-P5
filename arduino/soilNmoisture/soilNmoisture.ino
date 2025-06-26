#include <Servo.h>
Servo tap_servo;
int sensor_pin = A0;
int output_value = 0;
int tap_servo_pin = 7;

void setup(){
  pinMode(sensor_pin,INPUT);
  tap_servo.attach(tap_servo_pin);
  Serial.begin(9600);
}

void loop(){
   output_value = analogRead(sensor_pin);
 Serial.print(" sensor : ");
 Serial.println(output_value);
delay(500);

 if ( output_value > 820){
  tap_servo.write(90); 
  
 }else if( output_value < 700 && output_value < 814){
  tap_servo.write(180);
 } else {
  tap_servo.write(0);
 }
 }
    
