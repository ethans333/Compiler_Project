#include <regex.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_IDENTIFIER_LENGTH 10

char file[500];

typedef enum {
  skipsym = 1,
  identsym = 2,
  numbersym = 3,
  plussym = 4,  //....
  minussym = 5, //.....
  multsym = 6,  //
  slashsym = 7, //
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
  semicolonsym = 18, //
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

int tokenPrinter(char c) {
  switch (c) {
  case ';':
    return semicolonsym;
  case '+':
    return plussym;
  case '-':
    return minussym;
  case '*':
    return multsym;
  case '/':
    return slashsym;
  case '.':
    return periodsym;
  case '':
    return;
  case '':
    return;
  case '':
    return;
  case '':
    return;
  default:
    return -1;
  }
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Error: Please include the file name.\n");
    return 1;
  }

  FILE *fp = fopen(argv[1], "r");

  if (fp == NULL) {
    printf("Error: Cannot open file.\n");
    return -1;
  }

  int currentIndex = 0;
  int prevCharWasSpace = 0;

  int c;
  char original[500];

  while ((c = fgetc(fp)) != EOF) {
    if (currentIndex < 499) {
      original[currentIndex] = c;
      if (c == ' ' || c == '\t' || c == '\n') {
        if (!prevCharWasSpace) {
          file[currentIndex++] = ' ';
          prevCharWasSpace = 1;
        }
      } else {
        file[currentIndex++] = c;
        prevCharWasSpace = 0;
      }
    } else {
      printf("Error: Input exceeded 500 characters.\n");
      break;
    }
  }

  original[currentIndex] = '\0';
  file[currentIndex] = '\0';

  printf("Original string:\n%s\n", original);
  printf("\n\n");
  printf("Modified string:\n%s\n", file);

  fclose(fp);
  return 0;
}
