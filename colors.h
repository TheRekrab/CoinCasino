#include <stdio.h>

#ifndef COLORS
#define COLORS
// Define colors here:

#define RESET "\033[01;00m"
#define GREY "\033[01;30m"
#define RED "\033[01;31m"
#define GREEN "\033[01;32m"
#define YELLOW "\033[01;33m"
#define BLUE "\033[01;34m"
#define MAGENTA "\033[01;34m"
#define TEAL "\033[01;35m"

#endif

#ifndef STYLES
#define STYLES
// Define styles here:
#define RESET_STYLE "\033[00;01m"
#define DULL "\033[01;01m"
#define ITALICS "\033[03;01m"
#define UNDERLINE "\033[04;01m"
#define BLINKING "\033[05;01m"

#endif

#ifndef RESET_ALL
// Reset-all variable
#define RESET_ALL "\033[00;00m"
#endif

void reset(void) {
	printf(RESET_ALL);
}
