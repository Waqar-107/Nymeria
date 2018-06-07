/***from dust i have come, dust i will be***/

#define F_CPU 1000000

#include <avr/io.h>
#include <util/delay.h>

//---------------------------------------------------------
//in1,in2 for right pairs- when in1=1,in2=0 then clockwise and when in1=0,in2=1 then anti-clockwise
//in3,in4 for left pairs- when in3=1,in4=0 then clockwise and when in3=0,in4=1 then anti-clockwise
void forward() 
{
	//in4 in3 in2 in1 - 0101 - both pairs in clockwise
	PORTC=0b00000101;
}

void backward()
{
	//in4 in3 in2 in1 - 1010 - both pairs in counter-clockwise
	PORTC=0b00001010;
}

void left()
{
	//in4 in3 in2 in1 - 0001- right-pairs in clockwise, left pairs stopped
	PORTC=0b00000001;
}

void right()
{
	//in4 in3 in2 in1 - 0100- left pairs in clockwise, right pairs stopped
	PORTC=0b00000100;
}
//---------------------------------------------------------

int main(void)
{
	DDRC=0xFF;
	int dir=1;
	
    while(1)
    {
        //in4 in3 in2 in1
		
		PORTC=0b00000101;
    }
}