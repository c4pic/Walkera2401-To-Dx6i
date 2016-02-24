static unsigned int pulse=0;
static unsigned int tempo=0;
void setup() {  pinMode(3, INPUT);
  pinMode(10, OUTPUT); 
  attachInterrupt(1, read_ppm, CHANGE); }
void loop() {}
void read_ppm(){  pulse++;
    if (pulse<=14) {    digitalWrite(10,!digitalRead(3));  }
  if ((pulse>=18) || (millis()-t1>10) ){pulse=0;  }
  t1=millis();}
  
