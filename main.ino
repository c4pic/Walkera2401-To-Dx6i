void setup() {
  pinMode(3, INPUT);
  pinMode(10, OUTPUT); 
  attachInterrupt(1, read_ppm, CHANGE); //Asigna una interrupcion al pin en CAMBIO
}
void loop() {}
void read_ppm(){
  static unsigned int pulse;
  pulse++;
  while (pulse<=14) {    digitalWrite(10,!digitalRead(3));  }
  if (pulse>=18){    pulse=0;  }
}
