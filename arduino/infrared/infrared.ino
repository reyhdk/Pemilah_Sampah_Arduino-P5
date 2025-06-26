int led = 13;
int sensorpin = 11;
int sensor = HIGH;

void setup(){
  pinMode( led , OUTPUT);
  pinMode(sensorpin , INPUT);
  Serial.begin(9600);

}

void loop(){
  sensor = digitalRead(sensorpin);
  if (sensor == LOW){
    Serial.println(" ada benda");
    digitalWrite(led, HIGH);
  } else {
    Serial.println(" kosong");
    digitalWrite( led, LOW);
  }
  delay(1000);
}