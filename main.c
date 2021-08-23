#include "ventilador.h"
#include "uart.h"
#include <avr/io.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#include <util/delay.h>
#define MAX_STR 50
#define BAUD 9600
#define MIN_DATOS 10
#define MAX_DATOS 20 
#define SEMILLA 0

//LUIS ALFREDO SÁNCHEZ ALARCÓN - LUIS ANTONIO GONZALEZ HIDALGO
volatile bool manual = false;

//INTERRUPCIONES

ISR(INT0_vect){  //INTERRUPCION BOTÓN AUTO/MANUAL
 manual = !manual;
 if (manual){
      PORTB = ((1 << PB3));
    }else{
       PORTB = ((0 << PB3));
       }
}

//MAIN

int main()
 { 
   configPines();
    configVentilador();
    interrupt_INT0_Init(); //INTERRUPCION MANUAL/AUTOMÁTICO
   while (1){
     if (manual){
	 ventiladorManual();
       }else{
	  ventiladorAuto();
	  }
   }
   return 0;
 }
