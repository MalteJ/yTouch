#include "i2c.h"
#include <util/twi.h>
#include "error.h"


void i2c_init() {}
void i2c_start() {
  TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
  while (!(TWCR & (1<<TWINT)))
    ;
  if ((TWSR & 0xF8) != TW_START)
    ERROR();
}

void i2c_stop() {
  TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}

void i2c_slaw(char SLA_W) {
  TWDR = SLA_W;
  TWCR = (1<<TWINT) | (1<<TWEN);
  while (!(TWCR & (1<<TWINT)))
    ;
  if ((TWSR & 0xF8) != TW_MT_SLA_ACK)
    ERROR();
}

void i2c_slar() {
}
void i2c_waitforack() {}
void i2c_ack() {}
void i2c_nack() {}

void i2c_send(char byte) {
  TWDR = byte;
  TWCR = (1<<TWINT) | (1<<TWEN);
  while (!(TWCR & (1<<TWINT)))
    ;
  if ((TWSR & 0xF8) != TW_MT_DATA_ACK)
    ERROR();
}

void i2c_getdata(char* data) {}
