#define PinIn 3
#define PinOut 10

void setup() {
  pinMode(PinIn, INPUT);
  pinMode(PinOut, OUTPUT); 
  attachInterrupt(1, read_ppm, CHANGE); //Asigna una interrupcion al pin en CAMBIO
  TCCR1A = 0;  //reset timer1
  TCCR1B = 0;
  TCCR1B |= (1 << CS11);  //Timer configurado 0,5us
}

void loop() {}

void read_ppm(){
  
  static unsigned int pulse;
  static unsigned long counter;
  static byte channel;
  bool PinInStat;

  counter = TCNT1; 
  TCNT1 = 0;      

  PinInStat=digitalRead(PinIn);
  pulse++;
  
  while (pulse<=14) {
    digitalWrite(PinOut,!PinInStat);
  }

  if (pulse>=18){
    pulse=0;
  }
  
}
