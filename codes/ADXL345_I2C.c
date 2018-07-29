/*
 * CFile1.c
 *
 * Created: 9/25/2017 6:35:24 AM
 *  Author: hesham_omr
 */ 

#include "ADXL345_I2C.h"
void ADXL_init()
{
	TWI_Ini();
	ADXL_write(0x2D,0x08);
}

void ADXL_write(char address,char data)
{
	
	TWI_start();
	TWI_write(dev_write);
	TWI_write(address);
	TWI_write(data);
	TWI_stop();
}


void ADXL_Acc(float data_array[])
{
	int x0,x1,y0,y1,z0,z1;
	TWI_start();
	TWI_write(dev_write);
	TWI_write(x0_address);
	TWI_start();
	TWI_write(dev_read);
	x0=TWI_read(ACKM);
	x1=TWI_read(ACKM);
	y0=TWI_read(ACKM);
	y1=TWI_read(ACKM);
	z0=TWI_read(ACKM);
	z1=TWI_read(NACKM);
	TWI_stop();
	data_array[0]=((x1<<8)|x0)*g/sensitivity;
	data_array[1]=((y1<<8)|y0)*g/sensitivity;
	data_array[2]=((z1<<8)|z0)*g/sensitivity ;
	
}