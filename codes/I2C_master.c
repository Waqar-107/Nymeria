#include "I2C_master.h"

void TWI_Ini(void)
{
	TWBR = 32;
	TWSR = 0x00;
	
}


void TWI_start(void)
{
	TWCR=(1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while (!( TWCR & (1<<TWINT) ) );
	
	if ( !(( (TWSR & 0xF8) ==start) || ( (TWSR & 0xF8) == repeated_start)) )
	{
		TWI_start();
	}
}

void TWI_stop(void)
{
	TWCR=(1<<TWINT)|(1<<TWSTO)|(1<<TWEN) ;
}



void TWI_write(char data)
{
	TWDR = data;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while ( !( TWCR & (1<<TWINT) ) );
	
}


char TWI_read(char ACKM_NACKM)
{
	TWCR = (1<<TWINT) | (1<<TWEN) | (ACKM_NACKM<<TWEA);
	while ( !( TWCR & (1<<TWINT) ) );
	return TWDR;
}