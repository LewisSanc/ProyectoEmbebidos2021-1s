#include "ventilador.h"

void ventiladorManual(){
   ADCSRA = 0B11000111; // ENABLED ANALOG CONVERTER & START CONVERSION
   while(ADCSRA & (1<< ADSC)); // ADSC DISABLED?
   OCR0B  = ADC/4;
   }

void ventiladorAuto(){
   if (PINB & (1<<PB0)){
      OCR0B = 63.75; 
      while(PINB & (1<<PB0));
       }
   if (PINB & (1<<PB1)){
      OCR0B = 127.5; 
      while(PINB & (1<<PB1));
       }
   if (PINB & (1<<PB2)){
       OCR0B = 255; 
      while(PINB & (1<<PB2));
       }
}
