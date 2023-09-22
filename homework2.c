#include <regex.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY_LENGTH 100
#define MAX_DIGITS_LENGTH 5
#define MAX_CHARACTER_LENGTH 11

typedef enum { 
skipsym = 1, 
identsym = 2, 
numbersym = 3,  //....
plussym = 4,  //....
minussym = 5, //...
multsym = 6, //.... 
slashsym = 7, //.....
ifelsym = 8,  
eqlsym = 9, //...
neqsym = 10, 
lessym = 11, //...
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


//   //symboles in pl0//
//   // nulsym: 
//   // idsym: vaiable names
//   // numbersym:  
//   // plussym: +
//   // minussym: -
//   // multsym: *
//   // slashsym: /
//   // oddsym: odd
//   // eqsym: =
//   // neqsym: <>
//   // lessym: <
//   // leqsym: <=
//   // gtrsym: >
//   // geqsym: >=
//   // lparentsym: (
//   // rparentsym: )
//   // commasym: ,
//   // semicolonsym: ;
//   // periodsym: .
//   // becomessym: :=
//   // beginsym: begin
//   // endsym: end
//   // ifsym: if
//   // thensym: then
//   // whilesym: while
//   // dosym: do
//   // callsym: call
//   // constsym: const
//   // varsym: var
//   // procsym: procedure
//   // writesym: write
//   // writelnsym: writeln
//   // oddsym: odd
//   // proceduresym: procedure
  
//   //print geqsym
//   printf("%d", becomessym);
  
  
//   return 0;
// }


int identify_element(ch){

  if(ch >= 'a' && ch <= 'z'){}
  else if(ch >= 'A' && ch <= 'Z'){}
  else if(ch >= '0' && ch <= '9'){
    return numbersym;
  }
  else if(ch == '+'){
    return plussym;
  }
  else if(ch == '-'){
    return minussym;
  }
  else if(ch == '*'){
    return multsym;
  }
  else if(ch == '/'){
    return slashsym;
  }
  else if(ch == '='){
    
    
    return eqlsym;
    
  }
  else if(ch == '<'){
    return lessym;
  }


    
    
  else if(ch == '_'){}
  else if(ch == ){}
  
  
}

int main( int argc, char *argv[]){

  if(argc < 2){
    printf("Error : please include the file name");
    return 1;
  }
  
  FILE *fp = fopen(argv[1], "r");

  if(fp == NULL){
    printf("Error : cannot open file");
    return 1;
  
  }

  char arr[MAX_ARRAY_LENGTH];
  int arrTracker = 0;
  char c;
  //read character input by fscanf
  while(fscanf(fp, "%c", &c) != EOF){
    //reads the file and store chacracter bt chacracter in the arr
    arr[arrTracker] = c;
    arrTracker++;
  }
  //arrTracker is the last index of the array
  for(int i = 0; i < arrTracker; i++){
    printf("%c", arr[i]);
  }
  
  


  return 0;
  
}
