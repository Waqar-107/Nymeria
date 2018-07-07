/***from dust i have come, dust i will be***/

#define F_CPU 1000000

#include <avr/io.h>
#include <util/delay.h>

//---------------------------------------------------------
//in1,in2,in3 and in4 connected with D0,D1,D2 and D3 OF the RF receiver 
//in1 in2 in3 and in4 sent through AD0,AD1,AD2 and AD3 which connected to PD0,PD1,PD2,PD3
//in1,in2 for right pairs- when in1=1,in2=0 then clockwise and when in1=0,in2=1 then anti-clockwise
//in3,in4 for left pairs- when in3=1,in4=0 then clockwise and when in3=0,in4=1 then anti-clockwise
//---------------------------------------------------------
void sendData(unsigned char direction) {
	//using PORTD for this purpose
	PORTD=direction;
}

void forward() {
	//in4 in3 in2 in1 - 0101 - both pairs in clockwise
	unsigned char direction=0b00000101;
	sendData(direction);
}

void backward() {
	//in4 in3 in2 in1 - 1010 - both pairs in counter-clockwise
	unsigned char direction=0b00001010;
	sendData(direction);
}

void left() {
	//in4 in3 in2 in1 - 0001- right-pairs in clockwise, left pairs stopped
	unsigned char direction=0b00000001;
	sendData(direction);
}

void right() {
	//in4 in3 in2 in1 - 0100- left pairs in clockwise, right pairs stopped
	unsigned char direction=0b00000100;
	sendData(direction);
}

void stop() {
	//in4 in3 in2 in1 - 0000 - stop the wheels
	unsigned char direction=0b00000000;
	sendData(direction);
}
//---------------------------------------------------------

int main(void)
{
	DDRD=0xFF;
	
    while(1)
    {
        //write necessary codes, use ADC and decide which way to goto
		_delay_ms(500);
    }
}