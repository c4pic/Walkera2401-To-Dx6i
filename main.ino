#define PinIn 3
#define PinOut 10

void setup() {
  pinMode(PinIn, INPUT);
  pinMode(PinOut, OUTPUT); 
  attachInterrupt(1, read_ppm, CHANGE); //Asigna una interrupcion al pin en CAMBIO
}

void loop() {}

void read_ppm(){
  
  static unsigned int pulse;
  static unsigned long counter;
  static byte channel;
  bool PinInStat;


  PinInStat=digitalRead(PinIn);
  pulse++;
  
  while (pulse<=14) {
    digitalWrite(PinOut,!PinInStat);
  }

  if (pulse>=18){
    pulse=0;
  }
  
}
