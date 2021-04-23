




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

unsigned char tmpA;
unsigned char tmpB;
unsigned char side;

enum On_States {On_Start, On_None, On_Held_None, On_PB0, On_Held_PB0, On_PB1, On_Held_PB1, On_PB2, On_Held_PB2, On_PB3, On_Held_PB3, On_PB4, On_Held_PB4, On_PB5, On_Held_PB5, On_Off} On_State;

void Festive(){

    switch(On_State){
        case On_Start:
            On_State = On_None;
            break;
        case On_None:
            if(tmpA)
                On_State = On_Held_None;
            else if(!tmpA)
                On_State = On_None;
            break;
        case On_Held_None:
            if(tmpA)
                On_State = On_Held_None;
            else if(!tmpA)
                On_State = On_PB0;
            break;
        case On_PB0:
            if(tmpA){
                On_State = On_Held_PB0;
	  	tmpB = 0x01;
	    }
            else if (!tmpA)
                On_State = On_PB0;
            break;
        case On_Held_PB0:
            if(tmpA)
                On_State = On_Held_PB0;
            else if(!tmpA)
                On_State = On_PB1;
            break;
        case On_PB1:
            if(tmpA){
                On_State = On_Held_PB1;
	    	tmpB = 0x03;
	    }
            else if(!tmpA)
                On_State = On_PB1;
            break;
        case On_Held_PB1:
            if(tmpA)
                On_State = On_Held_PB1;
            else if(!tmpA)
                On_State = On_PB2;
            break;
        case On_PB2:
            if(tmpA){
                On_State = On_Held_PB2;
		tmpB = 0x07;
            } else if(!tmpA)
                On_State = On_PB2;
            break;
        case On_Held_PB2:
            if(tmpA)
                On_State = On_Held_PB2;
            else if(!tmpA)
                On_State = On_PB3;
            break;
        case On_PB3:
            if(tmpA){
                On_State = On_Held_PB3;
		tmpB = 0x0F;
            } else if(!tmpA)
                On_State = On_PB3;
            break;
        case On_Held_PB3:
            if(tmpA)
                On_State = On_Held_PB3;
            else if(!tmpA)
                On_State = On_PB4;
            break;
        case On_PB4:
            if(tmpA){
                On_State = On_Held_PB4;
		tmpB = 0x1F;
            } else if(!tmpA)
                On_State = On_PB4;
            break;
        case On_Held_PB4:
            if(tmpA)
                On_State = On_Held_PB4;
            else if(!tmpA)
                On_State = On_PB5;
            break;
        case On_PB5:
            if(tmpA){
                On_State = On_Held_PB5;
	    	tmpB = 0x3F;
            } else if(!tmpA)
                On_State = On_PB5;
            break;
        case On_Held_PB5:
            if(tmpA)
                On_State = On_Held_PB5;
            else if(!tmpA)
                On_State = On_None;
            break;
        default:
            On_State = On_None;
            break; 

    }
    
    switch(On_State){
        case On_None:
            tmpB = 0x00;
            break;
        case On_PB0:
            if(side)
                tmpB = 0x01;
            else if(!side)
                tmpB = 0x20;
            break;
        case On_PB1:
            if(side)
                tmpB = 0x03;
            else if(!side)
                tmpB = 0x30;
            break;
        case On_PB2:
            if(side)
                tmpB = 0x07;
            else if(!side)
                tmpB = 0x38;
            break;
        case On_PB3:
            if(side)
                tmpB = 0x0F;
            else if(!side)
                tmpB = 0x3C;
            break;
        case On_PB4:
            if(side)
                tmpB = 0x1F;
            else if(!side)
                tmpB = 0x3D;
            break;
        case On_PB5:
            tmpB = 0x3F;
            side = ~side;
            break;
    }
    PORTB = tmpB;
}
    

int main(void)
{
    // PORTA: input   PORTC: output
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
    
    tmpB = 0x00;   
    side = 1; 
    On_State = On_None;
    while (1)
    {
        tmpA = ~PINA & 0x03;
        Festive();
    }
}


