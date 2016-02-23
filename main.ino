#define PPM_Pin 3 
int ppm[16];  

void setup()
{
  pinMode(3, INPUT); 
  
  attachInterrupt(PPM_Pin - 2, read_ppm, CHANGE); //Asigna una interrupcion al pin en CAMBIO

  TCCR1A = 0;  //reset timer1
  TCCR1B = 0;
  TCCR1B |= (1 << CS11);  //set timer1 to increment every 0,5 us   //Timer configurado 0,5us
}

void loop()
{
  //You can delete everithing inside loop() and put your own code here
  int count;

  while(ppm[count] != 0){  //print out the servo values
    Serial.print(ppm[count]);
    Serial.print("  ");
    count++;
  }
  Serial.println("");
  delay(100);  //you can even use delays!!!
}

// Utiliza interrupcion de un pin al cambio. Se ejecuta la rutinta de la interrupcion dos veces
// por pulso...Así lee señales con estado por defecto a '0' o a '1'

void read_ppm(){  //leave this alone

 //lo interesante
 
  static unsigned int pulse;
  static unsigned long counter;
  static byte channel;

  counter = TCNT1; //Timer 1 - guarda
  TCNT1 = 0;       //Timer 1 - reinicia

  if(counter < 1020){  //must be a pulse if less than 510us *** Como configurado a  0.5us -> 1020 (1020*0.5=510) 
    pulse = counter; //pulso el valor del timer // Comienzo del pulso (flanco ascendente)
  }
  else if(counter > 3820){  //sync pulses over 1910us //se ha acabado la trama de pulsos
    channel = 0; //reinicia el numero de canal
  }
  else{  //servo values between 510us and 2420us will end up here //fin del pulso (flanco descendente)
    ppm[channel] = (counter + pulse)/2; //el pulso es la suma total del tiempo entre interrupciones dividido por 2 (0.5us timer)
    channel++;                 
  }
}
