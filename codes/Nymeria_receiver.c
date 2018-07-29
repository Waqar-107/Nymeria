/***from dust i have come, dust i will be***/

#define F_CPU 1000000

#include <avr/io.h>
#include <util/delay.h>

//--------------------------------------------------------
void forward(){
	PORTB=0b00000101;
}

void backward(){
	PORTB=0b00001010;
}

void left(){
	PORTB=0b00000001;
}

void right(){
	PORTB=0b00001000;
}

void stop(){
	PORTB=0b00000000;
}
//--------------------------------------------------------

int main(void)
{
	unsigned char c;
	
	DDRA = 0x00;
	DDRB = 0xFF;
	
	while(1)
	{
		c = PINA;
		c=c & 0b00001111;
		
		if(c==0b00000001)
			forward();
		
		else if(c==0b00000010)
			backward();
			
		else if(c==0b00000100)
			left();
			
		else if(c==0b00001000)
			right();
			
		else
			stop();
	}
}