int IRSensor=0;
int LED=13;
void setup() {
Serial.begin(9600);
pinMode(IRSensor, INPUT);
pinMode(LED, OUTPUT);
}

void loop() {
 int sensorstatus=digitalRead(IRSensor);
 if(sensorstatus==1)
 {
 
 digitalWrite(LED, LOW);
 Serial.println("Motion ended!");
 delay(1000);
 }
  digitalWrite(LED, HIGH);
  Serial.println("motion detected");
  delay(1000);
}
 
