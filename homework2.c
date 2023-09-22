#include <stdio.h>

#define MAX_IDENTIFIER_LENGTH 10

typedef enum {
  skipsym = 1,
  identsym = 2,
  numbersym = 3,
  plussym = 4,
  minussym = 5,
  multsym = 6,
  slashsym = 7,
  ifelsym = 8,
  eqlsym = 9,
  neqsym = 10,
  lessym = 11,
  leqsym = 12,
  gtrsym = 13,
  geqsym = 14,
  lparentsym = 15,
  rparentsym = 16,
  commasym = 17,
  semicolonsym = 18,
  periodsym = 19,
  becomessym = 20,
  beginsym = 21,
  endsym = 22,
  ifsym = 23,
  thensym = 24,
  whilesym = 25,
  dosym = 26,
  callsym = 27,
  constsym = 28,
  varsym = 29,
  procsym = 30,
  writesym = 31,
  readsym = 32,
  elsesym = 33
} token_type;

int main(int argc, char *argv[]) {

  if (argc < 2) {
    printf("Error : please include the file name");
    return 1;
  }

  FILE *fp = fopen(argv[1], "r");

  if (fp == NULL) {
    printf("Error : cannot open file");
    return -1;
  }

  char inputArray[500];
  int currentIndex =
      0; // Initialize an index to track the current position in the array
  int prevCharWasSpace = 0; // Flag to track consecutive white spaces

  int c; // Variable to store the read character

  while ((c = fgetc(fp)) != EOF) {
    if (currentIndex < 500) { // Check if there's still space in the array
      if (c == ' ' || c == '\t' || c == '\n') {
        if (!prevCharWasSpace) {
          inputArray[currentIndex++] =
              ' '; // Replace consecutive white spaces with a single space
          prevCharWasSpace = 1;
        }
      } else {
        inputArray[currentIndex++] = c;
        prevCharWasSpace = 0;
      }
    } else {
      printf("Error: Input exceeded 500 characters.\n");
      break;
    }
  }

  inputArray[currentIndex] = '\0'; // Null-terminate the array

  printf("Modified string:\n%s\n", inputArray);

  fclose(fp);
  return 0;
}
