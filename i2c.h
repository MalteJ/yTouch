#ifndef _I2C_H
#define _I2C_H

#include <util/twi.h>
#include "error.h"

void i2c_init();
void i2c_start();
void i2c_stop();
void i2c_slaw(char SLA_W);
void i2c_slar();
void i2c_waitforack();
void i2c_ack();
void i2c_nack();
void i2c_send(char byte);
void i2c_getdata(char* data);

#endif
