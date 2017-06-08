void setup() {
  // put your setup code here, to run once:
  pinMode(12,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int t = digitalRead(12);
  if(t==0){
    pinMode(12,OUTPUT);
    digitalWrite(12,HIGH);
    delay(1000);
    digitalWrite(12,LOW);
    delay(1000);
    pinMode(12,INPUT);
  }
  Serial.println(t);

}
