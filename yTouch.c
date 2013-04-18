#include <avr/io.h>

#define TOUCH_I2C_ADDRESS 0x1B

#include "i2c.h"

int main(void) {
  DDRD = 0xff;

  char data = 0;

  for(;;) {
    i2c_start();
    i2c_slaw(TOUCH_I2C_ADDRESS);
	i2c_waitforack();
	i2c_send(3);
	i2c_waitforack();
	i2c_stop();
	i2c_start();
	i2c_slar();
    i2c_waitforack();
	i2c_getdata(&data);
    i2c_nack();
	i2c_stop();

	PORTD = data;
  }

  return 0;
}
