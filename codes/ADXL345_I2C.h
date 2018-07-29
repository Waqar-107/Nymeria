/*
 * IncFile1.h
 *
 * Created: 9/25/2017 6:35:07 AM
 *  Author: hesham_omr
 */ 


#ifndef ADXL345_I2C_H_
#define ADXL345_I2C_H_
#ifndef AVR_IO_H_
#include <avr/io.h>
#endif
#ifndef I2C_MASTER_H_
#include "I2C_master.h"
#endif
#define dev_write   0xA6
#define dev_read    0xA7
#define x0_address  0x32
#define x1_address  0x33
#define y0_address  0x34
#define y1_address  0x35
#define z0_address  0x36
#define z1_address  0x37
#define sensitivity 282
#define     g        9.8f
void ADXL_init(void);
void ADXL_write(char address,char data);
void ADXL_Acc(float data_array[]);






#endif /* INCFILE1_H_ */