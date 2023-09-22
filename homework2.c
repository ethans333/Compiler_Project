#include <regex.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_IDENTIFIER_LENGTH 10

regex_t regex;
char file[500];

// numbersym:
// plussym: +
// minussym: -
// multsym: *
// slashsym: /
// oddsym: odd
// eqsym: =
// neqsym: <>
// lessym: <
// leqsym: <=
// gtrsym: >
// geqsym: >=
// lparentsym: (
// rparentsym: )
// commasym: ,
// semicolonsym: ;
// periodsym: .
// becomessym: :=
// beginsym: begin
// endsym: end
// ifsym: if
// thensym: then
// whilesym: while
// dosym: do
// callsym: call
// constsym: const
// varsym: var
// procsym: procedure
// writesym: write
// writelnsym: writeln
// oddsym: odd
// proceduresym: procedure

typedef enum {
  skipsym = 1,
  identsym = 2,
  numbersym = 3,
  plussym = 4,  //....
  minussym = 5, //....
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
  periodsym = 19,    //
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

void readRegularExpression() {
  int status = regcomp(&regex, "[:number:]", 0);

  if (status != 0) {
    printf("Invalid Regex!");
  }

  int match = regexec(&regex, "12345", 0, NULL, 0);

  // Check for a match
  if (match == 0) {
    printf("Match\n");
  } else {
    printf("No Match\n");
  }

  regfree(&regex);
}

// int tokenPrinter(char c) {
//   if (c == '<>') {
//   }
//   switch (c) {
//   case ';':
//     return semicolonsym;
//   case '+':
//     return plussym;
//   case '-':
//     return minussym;
//   case '*':
//     return multsym;
//   case '/':
//     return slashsym;
//   case '.':
//     return periodsym;
//   case '<>':
//     return;
//   case '':
//     return;
//   case '':
//     return;
//   case '':
//     return;
//   default:
//     return -1;
//   }
// }

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

  readRegularExpression();

  fclose(fp);
  return 0;
}
