#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  FILE *fp;
  char buff[20];
  int opp_rock = 'A';
  int opp_paper = 'B';
  int opp_scissor = 'C';
  int i_lose = 'X';
  int i_tie = 'Y';
  int i_win = 'Z';

  fp = fopen("input.txt", "r");
  int score = 0;

  while (fgets(buff, 20, (FILE *)fp) != NULL) {
    if (buff[0] == opp_rock && buff[2] == i_lose) {
      score += 3;
    } else if (buff[0] == opp_paper && buff[2] == i_tie) {
      score += 5;
    } else if (buff[0] == opp_scissor && buff[2] == i_win) {
      score += 7;
    } else if (buff[0] == opp_rock && buff[2] == i_tie) {
      score += 4;
    } else if (buff[0] == opp_rock && buff[2] == i_win) {
      score += 8;
    } else if (buff[0] == opp_paper && buff[2] == i_lose) {
      score += 1;
    } else if (buff[0] == opp_paper && buff[2] == i_win) {
      score += 9;
    } else if (buff[0] == opp_scissor && buff[2] == i_lose) {
      score += 2;
    } else if (buff[0] == opp_scissor && buff[2] == i_tie) {
      score += 6;
    }
  }
  printf("The final score is: %d\n", score);
  return 0;
}