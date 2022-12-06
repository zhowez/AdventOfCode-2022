#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  FILE *fp;
  char buff[255];

  fp = fopen("input-day1.txt", "r");
  int count = 0;

  while (fgets(buff, 255, (FILE *)fp) != NULL) {
    if (buff[0] == '\n') {
      count++;
    }
  }

  rewind(fp);

  int elfCalCount = 0;

  int elfCals[count];

  int elfNum = 0;

  int maxCal = 0;

  while (fgets(buff, 255, (FILE *)fp) != NULL) {
    if (buff[0] != '\n') {
      elfCalCount += atoi(buff);
    } else {
      elfCals[elfNum] = elfCalCount;

      if (elfCalCount > maxCal) {
        maxCal = elfCalCount;
      }
      elfCalCount = 0;
      elfNum++;
    }
  }
  printf("The max cal count is: %d\n", maxCal);
  return 0;
}