

















/*	Author: lab
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */


#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;
    unsigned char tmpC = 0;
    unsigned char fuel = 0;

    /* Insert your solution below */
    while (1) {
	fuel = ~PINA & 0x0F;
	if(fuel == 0){
	    tmpC = 0x40;
	}
	else if (fuel == 0x01 || fuel == 0x02){
	    tmpC = 0x60;
	} else if (fuel == 0x03 || fuel == 0x04){
	    tmpC = 0x70;
	} else if (fuel == 0x05 || fuel == 0x06){
	    tmpC = 0x38;
	} else if (fuel > 0x06 && fuel < 0x0A) {
	    tmpC = 0x3C;
	} else if (fuel > 0x09 && fuel < 0x0D) {
	    tmpC = 0x3E;
	} else 
	    tmpC = 0x3F;
	PORTC = tmpC;
    }
    
}
