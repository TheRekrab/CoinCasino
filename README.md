# Coin Casino
This is a basic game that I created. You are given 100 coins and you try to push your luck as far as it will go without going out of money. I included some fun ASCII art titles for fun.

To play the game, clone the repo from GitHub and then simply run the downloaded executable, 'coinflip'.
If you are using Windows, then you will have to recompile the source code (coinflip.c) to a windows-friendly executable.

Once opening the game, you will be greeted with a cool ASCII art title.

```
#include <stdio.h>

void start_screen() {
  puts("[|=================================================================================|]");
  puts("   //==\\\\  //==\\\\  ====  |\\\\ ||    //==\\\\  //-\\\\  //===   ====  |\\\\ ||  //==\\\\");
  puts("   ||      ||  ||   ||   ||\\\\||    ||      ||=||  \\\\==\\\\   ||   ||\\\\||  ||  ||");
  puts("   \\\\==//  \\\\==//  ====  || \\\\|    \\\\==//  || ||   ===//  ====  || \\||  \\\\==//");
  puts("[|=================================================================================|]");
}

void game_over() {
  puts("[|===============================================================|]");
  puts("   //==\\\\  //-\\\\  |\\\\  //|  ||==    //==\\\\  \\\\  //  ||==  ||=\\\\");
  puts("   ||  __  ||=||  ||\\\\//||  ||=     ||  ||   \\\\//   ||=   ||=//");
  puts("   \\\\==//  || ||  || \\/ ||  ||==    \\\\==//    \\/    ||==  || \\\\");
  puts("[|===============================================================|]");
}

```
