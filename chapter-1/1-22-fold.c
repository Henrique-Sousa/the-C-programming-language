#include <stdio.h>
#define OUT 0
#define IN 1
#define TEXTWIDTH 80
#define MAXWORDLENGTH 1000


int wi, c, numchars;
char lastword[MAXWORDLENGTH];

void printfolded();

int main() {
  int i, state;
  
  for (i=0; i<MAXWORDLENGTH; i++) {
    lastword[i] = ' ';
  }

  state = OUT;
  numchars = 0;
  wi = 0; 
  while ((c = getchar()) != EOF) {
    ++numchars;
    if (c == ' ') {
      if (state == IN) {  // just finished recording last word?
        printfolded();
        for (i=0; i<=wi; i++) { // erase lastword array
          lastword[i] = ' ';
        }
        wi = 0;
      } else {
        if (numchars > TEXTWIDTH) {
          putchar('\n');
        }
        putchar(c);
      }
      state = OUT;
    } else if (state == OUT) {
      state = IN;
    }
    
    if (c != ' ') {
      lastword[wi] = (char) c;
      ++wi;
    }
  }
  printfolded();
}

void printfolded() {
  lastword[wi+1] = '\0';
  if (numchars > TEXTWIDTH) {  // line lenght so far > TEXTWIDTH ?
    printf("\n%s ", lastword);  // break the line before printing the word
    numchars = 0;
  } else if (numchars == (TEXTWIDTH + 1)) {  // if last word completed TEXTWIDTH chars in a line, print the word without a trailing space
    printf("%s\n", lastword);
    numchars = 0;
  } else if (c == EOF){
    printf("%s", lastword);
  } else {  // just a word in the middle of the line? just print it! with the current space added to the end
    printf("%s ", lastword);
  }
}
