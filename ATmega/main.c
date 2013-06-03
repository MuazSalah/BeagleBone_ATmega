// This is a modified code of 
// https://github.com/Torrentula/I2C-slave-lib



//----------------------------------------------------------------------
// Includes
//----------------------------------------------------------------------
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "I2C_slave.h"



//----------------------------------------------------------------------
// Defines
//----------------------------------------------------------------------
//I2C Slave Address
#define MyI2CAddress			0x0A


// Set and clear bits in I/O registers can also be declared as macros 
#define SETBIT(ADDRESS,BIT) (ADDRESS |= (1<<BIT))
#define CLEARBIT(ADDRESS,BIT) (ADDRESS &= ~(1<<BIT))
// Macro for testing of a single bit in an I/O location
#define CHECKBIT(ADDRESS,BIT) (ADDRESS & (1<<BIT))






//----------------------------------------------------------------------
// Function Declarations
//----------------------------------------------------------------------
// System Initilization Function
void System_init(void);
void ioinit(void);






//----------------------------------------------------------------------
// Main
//----------------------------------------------------------------------
int main(void)
{

	System_init();
	
	for (;;)
	{
		if (rxbuffer[1] == 0)
			PORTB |= (1<<PB0);
		else
			PORTB &= ~(1<<PB0);
		
		
		if (rxbuffer[2] == 0)
			PORTB |= (1<<PB1);
		else
			PORTB &= ~(1<<PB1);
		
	}
	
	return 0;
}








//----------------------------------------------------------------------
// Other Functions
//----------------------------------------------------------------------
void System_init(void)
{
	ioinit();
	
	I2C_start(MyI2CAddress);
	
	txbuffer[5] = 1;

	sei();

}



void ioinit(void)
{
	DDRB |= (1<<PB0) | (1<<PB1);
}



