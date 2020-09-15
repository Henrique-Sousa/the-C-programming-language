#include <stdio.h>

#define IN 1
#define OUT 0
#define MAX_LENGTH 20

int main() {
  int c, nc, state, i, j;
  int lengths[MAX_LENGTH];

  for(i = 0; i < MAX_LENGTH; i++) {
    lengths[i] = 0;
  }

  state = OUT;
  nc = 0;
  while((c = getchar()) != EOF) {
    if (c < 65 || (90 < c && c < 97) || c > 122) {
      state = OUT;
    } else if (state == OUT) {
      state = IN;
    } 
    if (state == IN) {
      ++nc;
    } else if (nc != 0) {
      ++lengths[nc]; 
      nc = 0;
    }
  }

  printf("lengths: \n");
  for(i = 0; i < MAX_LENGTH; i++) {
    printf("%d: ", i);
    for(j = 0; j < lengths[i]; j++) {
      printf("*");
    }
    printf("\n");
  }

}
