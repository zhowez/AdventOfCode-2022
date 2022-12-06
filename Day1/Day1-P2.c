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

  int maxCal1 = 0;
  int maxCal2 = 0;
  int maxCal3 = 0;

  while (fgets(buff, 255, (FILE *)fp) != NULL) {
    if (buff[0] != '\n') {
      elfCalCount += atoi(buff);
    } else {
      elfCals[elfNum] = elfCalCount;

      if (elfCalCount > maxCal1) {
        maxCal3 = maxCal2;
        maxCal2 = maxCal1;
        maxCal1 = elfCalCount;
      } else if (elfCalCount > maxCal2) {
        maxCal3 = maxCal2;
        maxCal2 = elfCalCount;
      } else if (elfCalCount > maxCal3) {
        maxCal3 = elfCalCount;
      }

      elfCalCount = 0;
      elfNum++;
    }
  }
  int total = maxCal1 + maxCal2 + maxCal3;
  printf("The max cal count 1 is: %d\n", maxCal1);
  printf("The max cal count 2 is: %d\n", maxCal2);
  printf("The max cal count 3 is: %d\n", maxCal3);
  printf("The max cal count of all is: %d\n", total);

  return 0;
}