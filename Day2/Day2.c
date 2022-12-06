#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  FILE *fp;
  char buff[20];
  int opp_rock = 'A';
  int opp_paper = 'B';
  int opp_scissor = 'C';
  int my_rock = 'X';
  int my_paper = 'Y';
  int my_scissor = 'Z';

  fp = fopen("input.txt", "r");
  int score = 0;

  while (fgets(buff, 20, (FILE *)fp) != NULL) {
    if (buff[0] == opp_rock && buff[2] == my_rock) {
      score += 4;
    } else if (buff[0] == opp_paper && buff[2] == my_paper) {
      score += 5;
    } else if (buff[0] == opp_scissor && buff[2] == my_scissor) {
      score += 6;
    } else if (buff[0] == opp_rock && buff[2] == my_paper) {
      score += 8;
    } else if (buff[0] == opp_rock && buff[2] == my_scissor) {
      score += 3;
    } else if (buff[0] == opp_paper && buff[2] == my_rock) {
      score += 1;
    } else if (buff[0] == opp_paper && buff[2] == my_scissor) {
      score += 9;
    } else if (buff[0] == opp_scissor && buff[2] == my_rock) {
      score += 7;
    } else if (buff[0] == opp_scissor && buff[2] == my_paper) {
      score += 2;
    }
  }
  printf("The final score is: %d\n", score);
  return 0;
}