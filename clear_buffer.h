#include <stdio.h>
void clear_buffer() {
  long c;
  while ( (c = getchar()) != '\n' && c != EOF) {
    ; // Do nothing...
  }
}
