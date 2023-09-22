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

  // Reads and stores file contents within array `file`.

  if (argc < 2) {
    printf("Error : please include the file name");
    return 1;
  }

  FILE *fp = fopen(argv[1], "r");

  if (fp == NULL) {
    printf("Error : cannot open file");
    return -1;
  }

  char file[500];
  int currentIndex = 0;
  int prevCharWasSpace = 0;

  int c;

  while ((c = fgetc(fp)) != EOF) {
    if (currentIndex < 500) {
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

  file[currentIndex] = '\0';

  printf("Modified string:\n%s\n", file);

  fclose(fp);
  return 0;
}
