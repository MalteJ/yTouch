#include "error.h"
#include <avr/io.h>

void ERROR() {
  DDRD = 0xff;
  PORTD = 0xff;
}
