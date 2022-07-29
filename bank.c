#include <stdio.h>
#include <string.h>
#include "bank_utils.h"
#include "clear_buffer.h"
#include "ascii_art.h"

#define BUFFSIZE 2048

int main() {
  bank_login();
  printf("\n\nHello! Welcome to the Coin Bank.\nPlease login:\nName: ");
  char username[BUFFSIZE];
  fgets(username, BUFFSIZE, stdin);
  username[strcspn(username, "\n")] = 0;
  printf("Hello, %s! Here are your options:\n", username);
  puts("1 - View account balance");
  puts("2 - Reset account to 100 coins");
  printf("Please enter your selection here: ");
  char selection = getchar();
  clear_buffer();
  if (selection == '1') {
    printf("ACCOUNT BALANCE:  %ld coins.\n", get_balance(username));
    return 0;
  } else if (selection == '2') {
    printf("This is very dangerous. Please type \"I agree\" to continue:   ");
    char agree[BUFFSIZE];
    fgets(agree, BUFFSIZE, stdin);
    agree[strcspn(agree, "\n")] = 0;
    if (strcmp(agree, "I agree") == 0) {
      long to_remove = 0 - get_balance(username);
      to_remove += 100;
      add_coins(username, to_remove);
      puts("Account reset.");
    } else {
      puts("Abort.");
      return 0;
    }
  } else {
    puts("Not a valid option. Goodbye!");
  }
}
