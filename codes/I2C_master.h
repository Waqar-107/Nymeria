


#ifndef I2C_MASTER_H_
#define I2C_MASTER_H_
#include <avr/io.h>
#define start            0x08
#define repeated_start   0x10
#define ACKM              1
#define NACKM             0

void TWI_Ini(void);
void TWI_start(void);
void TWI_stop(void);
void TWI_write(char data);
char TWI_read(char ACKM_NACKM);

#endif