#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFSIZE 2048

long get_balance(char* username) {
  char file_path[BUFFSIZE] = "Accounts/";
  strncat(file_path, username, BUFFSIZE-1);
  FILE *fp = fopen(file_path, "r");
  if (fp == NULL) {
    // Add the starting 100 coins.
    FILE *new = fopen(file_path, "w");
    fprintf(new, "100");
    fclose(new);
    return 100;
  }
  char coins_str[BUFFSIZE];
  fgets(coins_str, BUFFSIZE, fp);
  fclose(fp);
  return atol(coins_str);
}

void add_coins(char* username, long gain) {
  long current_balance = get_balance(username) + gain;
  char file_path[BUFFSIZE] = "Accounts/";
  strncat(file_path, username, BUFFSIZE-1);
  FILE *fp = fopen(file_path, "w");
  fprintf(fp, "%ld", current_balance);
  fclose(fp);
}
