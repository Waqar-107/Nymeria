/***from dust i have come, dust i will be***/

#define F_CPU 1000000

#include <util/delay.h>
#include "ADXL345_I2C.h"

//---------------------------------------------------------
void sendData(unsigned char direction) {
	//using PORTD for this purpose
	PORTD=direction;
}

void forward() {
	unsigned char direction=0b00000001;
	sendData(direction);
}

void backward() {
	unsigned char direction=0b00000010;
	sendData(direction);
}

void left() {
	unsigned char direction=0b00000100;
	sendData(direction);
}

void right() {
	unsigned char direction=0b00001000;
	sendData(direction);
}

void stop() {
	unsigned char direction=0b00001111;
	sendData(direction);
}
//---------------------------------------------------------

int main(void)
{
	DDRD=0xFF;
	DDRC=0x00;
	DDRA=0xFF;
	
	ADXL_init();
	
	float acc_data[3]={0};
	
	while(1)
	{
		ADXL_Acc(acc_data);
		
		if(acc_data[1]>=4.0)
			forward();
		
		else if(acc_data[1]<=-4.0)
			backward();
		
		else if(acc_data[0]>=4.0)
			right();
		
		else if(acc_data[0]<=-4.0)
			left();
		
		else
			stop();
	}
}