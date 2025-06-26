
#include <Servo.h>
Servo autoServo; // untuk penggerak servo ultrasonic
Servo humServo; // untuk pengerak servo kelembapan
int humPin = A0; // signal pada soil sensor disambungkan ke pin A0
int echoPin = 4; // pin echo pada ultrasonic disambungkan pada pin 4
int trigPin = 5; //pin trig pada ultrasonic disambungkan pada pin 5
int autoservoPin = 7; 
int humservoPin = 9;
int led = 10;
int humVal = 0;
int disVal = 0;
void initPin()
{
 autoServo.attach(autoservoPin);
 humServo.attach(humservoPin);
 pinMode(trigPin, OUTPUT); //trig pada ultra sebagai keluaran
 pinMode(echoPin, INPUT); //echo pada ultra sebagai masukan
 autoServo.write(0);
 humServo.write(0);
 delay(100);
}
void setup()
{
 Serial.begin(9600);
 initPin();
 Serial.println("Smart-Bin"); //nama awal pada serial monitor
}
void loop()
{
 humVal = readHum();
 if (humVal > 50) //besar batas nilai pada sensor kelembapan
 {
 humServoOn(); //agar servo yang terhubung ke soil bergerak
 }
 else
 {
 humServoOff();
 }
 disVal = readDisAvg();
 if (disVal < 50)
 {
 autoServoOn();
 }
 else
 {
 autoServoOff();
 }
 delay(3000);
}
int readHum()
{
 int humVals = analogRead(humPin);
 humVals = 1023 - humVals;
 Serial.println("Nilai Kelembaban: " + String(humVals));
 return humVals;
}
int readDis()
{
 int duration;
 int distance;
 digitalWrite(10, HIGH);
 digitalWrite(trigPin, LOW);
 delayMicroseconds(5);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(15);
 digitalWrite(trigPin, LOW);
 pinMode(echoPin, INPUT);
 duration = pulseIn(echoPin, HIGH);
 distance = (duration / 2) / 29.1;
 return (distance);
}
int readDisAvg()
{
 int disVals = 0;
 int totaldisVal = 0;
 for (int i = 0; i < 3; i++)
 {
disVals = readDis();
 totaldisVal += disVals;
 }
 disVals = totaldisVal / 3;
 Serial.println("Nilai Ultrasonic: " + String(disVals));
 return (disVals);
}
void humServoOn()
{
 Serial.println("Servo Hum ON");
 humServo.write(180);
 delay(1000);
 humServo.write(90);
}
void humServoOff()
{
 Serial.println("Servo Hum OFF");
 humServo.write(0);
 delay(1000);
 humServo.write(90);
}
void autoServoOn()
{
 Serial.println("Servo Auto ON");
 autoServo.write(0);
 delay(200);
 humServo.write(180);
}
void autoServoOff()
{
 Serial.println("Servo Auto OFF");
 autoServo.write(180);
 delay(1000);
}

