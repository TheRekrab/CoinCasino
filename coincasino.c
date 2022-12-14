#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include "ascii_art.h"
#include "bank_utils.h"
#include "clear_buffer.h"
// ascii_art.h already has the colors defined.

#define BUFFSIZE 2048

long flip();
void rules();
void loop(long *coins, const char* username);
long result_bet(long coins_to_bet, const char*, const char*);
long place_bet(long coins);

int main() {
  srand(time(NULL));
  start_screen();
  puts("\n\nWelcome to the Coin Casino.");
  printf("Would you like to play? (y/n):  " YELLOW);
  char play = getchar();
  reset();
	clear_buffer();
  if ( play == 'y' || play == 'Y' ) {
    rules();
    char username[BUFFSIZE];
    printf("Enter your name:  " YELLOW);
    fgets(username, BUFFSIZE, stdin);
		reset();
    username[strcspn(username, "\n")] = 0;
    long money = get_balance(username);
    printf("You have %ld coins to start the round with.\n", money);
    while (1) {
        loop(&money, username);
    }

  } else {
      puts("Ok. Come back to the Coin Casino later...");
			return EXIT_SUCCESS;
  }
}

// Basic stuff:
long flip() {
  return rand() % 2;
}

void rules() {
  puts( YELLOW "\n  COIN FLIP RULES:" RESET);
  puts(" 1. A coin is tossed.");
  puts(" 2. You try to guess which side the coin will land on and place a bet.");
  puts("    If you win the bet, you will gain however much money you bet.");
  puts("    However, if you loose, you lose however much money you bet.");
  puts(" 3. This continues until you decide to quit, or are out of money.");
  printf("You start the game with exactly " YELLOW "100" RESET " coins (if this is your first time). Let's get this round started!\n\n");
}


// More complex functions:
long solve_bet(long coins_to_bet, const char* bet, const char* correct) {
  printf("The coin was %s!\n", correct);
  // Did the user's bet win?
  if ( strcmp(bet, correct) == 0 ) {
    printf("You won the bet! You win " YELLOW "%ld" RESET " coins.\n", coins_to_bet);
    return coins_to_bet;
  } else {
    printf("Sorry, you did not win the bet. Better luck next time. You lose " YELLOW "%ld" RESET " coins.", coins_to_bet);
    return 0 - coins_to_bet;
  }
}

long place_bet(long coins) {
  // Get amount of money to bet:
  printf("Betting time!\nHow many coins do you want to bet?  " YELLOW);
  char coins_to_bet_str[BUFFSIZE];
  fgets(coins_to_bet_str, BUFFSIZE, stdin);
	reset();
  // Is is a number?
  if ( !(atoi(coins_to_bet_str)) ) {
    puts("Not a number!");
    return 0;
  } else if (atoi(coins_to_bet_str) < 0) { // Prevent user from entering random numbers.
    printf("You cannot bet " YELLOW "%d" RESET" coins. Try again.\n", atoi(coins_to_bet_str));
    return 0;
  }
  long coins_to_bet = atoi(coins_to_bet_str);
  // Check if it is OK to be removed from the account:
  if (coins_to_bet > coins) {
    printf("You cannot spend that many coins. You only have " YELLOW "%ld" RESET " coins.\n", coins);
    return 0;
  }
  // Get bet (heads or tails):
  printf("You have wagered " YELLOW "%ld" RESET " coins.\nWhat do you think the outcome will be? (heads/tails):  " YELLOW, coins_to_bet);
  char bet[BUFFSIZE];
  fgets(bet, BUFFSIZE, stdin);
	reset();
  bet[strcspn(bet, "\n")] = 0; // Replace \n with a null byte.
  // Flip coin
  puts("Flipping coin...");
  long result = flip();
  if (result) {
    char correct[] = "heads";
    return solve_bet(coins_to_bet, bet, correct);
  } else {
    char correct[] = "tails";
    return solve_bet(coins_to_bet, bet, correct);
  }

}

void loop(long *coins, const char* username) {
  long gain = place_bet(*coins);
  if (gain == 0) {
    return; // Restart the loop
  }
  *coins += gain;
  add_coins(strdup(username),gain);
  if (*coins == 0) {
    printf( RED "OH, NO! You no longer have any coins. You are now broke, and must leave the casino.\nCome again soon with more money!\n\n\n" RESET);
    game_over();
    exit(EXIT_SUCCESS);

  } else {
    printf("You currently have " YELLOW "%ld " RESET " coins.\nWould you like to keep playing? (y/n)  " YELLOW, *coins);
    char cont = getchar();
		reset();
    clear_buffer();
    if (tolower(cont) != 'y') {
      printf("You leave the table with " YELLOW "%ld" RESET " coins.\nCome back to the Coin Casino to try and earn more than that next time.\n", *coins);
      game_over();
      exit(0);
    }
  }
}
