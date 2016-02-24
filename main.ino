void setup() {
  pinMode(3, INPUT);
  pinMode(10, OUTPUT); 
}
void loop() {
  digitalWrite(10,!digitalRead(3));
}
