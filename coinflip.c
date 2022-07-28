#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int flip() {
    return rand() % 2;
}

void loop() {
    // Do nothing, so far.
}

int main() {
    puts("");
    puts("[|=================================================================================|]");
    puts("   //==\\\\  //==\\\\  ====  |\\\\ ||    //==\\\\  //-\\\\  //===   ====  |\\\\ ||  //==\\\\");
    puts("   ||      ||  ||   ||   ||\\\\||    ||      ||=||  \\\\==\\\\   ||   ||\\\\||  ||  ||");
    puts("   \\\\==//  \\\\==//  ====  || \\\\|    \\\\==//  || ||   ===//  ====  || \\||  \\\\==//");
    puts("[|=================================================================================|]");
    puts("");
    puts("Welcome to the Coin Casino.");
    printf("Would you like to play? (y/n):  ");
    char play = getc(stdin);
    if ( play == 'y' || play == 'Y' ) {
        while (1) {
            loop();
        }
    } else {
        puts("Ok. Come back to the Coin Casino later...");
    }
}
