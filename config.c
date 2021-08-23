#include "config.h"

void configVentilador(){
   ADMUX = 0B01000001;	//AVCC- AREF y ADC1
   ADCSRA = 0B00000111; //PRE-SCALER  128 - DISABLED ANALOG CONVERTER & CONVERSION NOT STARTED
   ADCSRB = 0B00000000;  //FREE RUNNING MODE
   DIDR0 = 0B00000110;  //ENABLE ANALOG MODE ADC1
   DDRD |= 0b01100000; //SALIDA PINES PD5(OC0B) Y PD6(OC0A)
   TCCR0A = 0b11100011; //TIMER0 PWMA// INVERTIDO A & NO INVERTIDO B &MODO RAPIDO
   TCCR0B = 0b00000001; //SIN PREESCALADOR
   OCR0B = 0; //valor inicial de pwm para el pin OC0B
   OCR0A = 0; //valor inicial de pwm para el pin OC0A
   }

void configPines(){
    PORTD |= (1<<PB3); //Activar resistencia de PULLUP en PIN0 del puerto 
 }
 
 void interrupt_INT0_Init(){
 cli();
 EICRA = 0b11;
 EIMSK = 1;
 sei();
}
