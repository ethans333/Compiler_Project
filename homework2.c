#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARRAY_LENGTH 500
#define MAX_CHARACTER_LENGTH 11
#define MAX_DIGITS_LENGTH 5

char file[MAX_ARRAY_LENGTH];
int tokenList[MAX_ARRAY_LENGTH];
char word[MAX_CHARACTER_LENGTH];
char digits[MAX_DIGITS_LENGTH];

// numbersym:
// plussym: +
// minussym: -
// multsym: *
// slashsym: /
// oddsym: odd
// x eqsym: =
// x neqsym: <>
// x lessym: <
// x leqsym: <=
// x gtrsym: >
// x geqsym: >=
// lparentsym: (
// rparentsym: )
// commasym: ,
// semicolonsym: ;
// periodsym: .
// x becomessym: :=
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

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Error: Please include the file name.\n");
    return 1;
  }

  FILE *fp = fopen(argv[1], "r");

  if (fp == NULL) {
    printf("Error: Cannot open file.\n");
    return 1;
  }

  int i = 0, j = 0, k = 0, fileLen = 0;
  char ch;
  bool lastWasSpace = false;

  while ((ch = fgetc(fp)) != EOF) {
    putchar(ch);

    if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r') {
      if (!lastWasSpace) {
        file[i++] = ' ';
        lastWasSpace = true;
      }
    } else {
      file[i++] = ch;
      lastWasSpace = false;
    }

    if (i >= MAX_ARRAY_LENGTH - 1) {
      printf("Error: Input file is too large.\n");
      fclose(fp);
      return 1;
    }
  }

  file[i] = '\0';
  fileLen = i + 1;
  fclose(fp);

  printf("\n\n%s\n\n", file);

  for (i = 0; i < fileLen; i++) {
    ch = file[i];

    if (ch >= 'A' && ch <= 'z') { // If Letter
      word[j++] = ch;
    } else if (ch >= '0' && ch <= '9') { // If digit
      if (j != 0) {                      // Is digit from identifier
        word[j++] = ch;
      } else { // Is digit from value
        digits[k++] = ch;
      }
    } else { // If special symbol

      // End of idenitfier name or reserved word
      if (j > 0) {
        word[j + 1] = '\0';
        printf("%s|", word);
      } else if (k > 0) {
        digits[k + 1] = '\0';
        printf("%s|", digits);
      }

      // Wipe word array
      memset(word, 0, MAX_CHARACTER_LENGTH);
      j = 0;
      memset(digits, 0, MAX_DIGITS_LENGTH);
      k = 0;

      // There exist a next char in the array
      bool isNext = i + 1 < fileLen;

      switch (ch) {
      case '+':
        printf("%c|", ch);
        break;
      case '-':
        printf("%c|", ch);
        break;
      case '*':
        printf("%c|", ch);
        break;
      case '/':
        if (isNext && file[i + 1] == '*') { // /*
          // **Handle Comment Case**
        } else { // /
          printf("%c|", ch);
        }
        break;
      case '(':
        printf("%c|", ch);
        break;
      case ')':
        printf("%c|", ch);
        break;
      case '=':
        printf("%c|", ch);
        break;
      case ',':
        printf("%c|", ch);
        break;
      case '<':
        if (isNext) {
          if (file[i + 1] == '>') { // <>
            printf("%c%c|", ch, file[i + 1]);
            i++;
          } else if (file[i + 1] == '=') { // <=
            printf("%c%c|", ch, file[i + 1]);
            i++;
          } else { // <
            printf("%c|", ch);
          }
        }
        break;
      case '>':
        if (isNext && file[i + 1] == '=') { // >=
          printf("%c%c|", ch, file[i + 1]);
          i++;
        } else { // >
          printf("%c|", ch);
        }
        break;
      case ';':
        printf("%c|", ch);
        break;
      case ':':
        if (isNext && file[i + 1] == '=') { // :=
          printf("%c%c|", ch, file[i + 1]);
          i++;
        }
        break;
      default:
        break;
      }
    }
  }

  return 0;
}