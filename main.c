#include <avr/io.h>

#include "i2c.h"

int main(void) {
  DDRD = 0xff;
  PORTD = 0x01;

  return i2c_channel();
}
