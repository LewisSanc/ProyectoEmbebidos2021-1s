#include <inttypes.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

//CONFIGURACIONES 
void configVentilador();
void configPines();

//INTERRUPCIONES
void interrupt_INT0_Init();
