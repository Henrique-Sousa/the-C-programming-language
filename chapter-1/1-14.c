#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
  int c, i, j;
  int frequencies[128];

  for(i = 0; i < 128; i++) {
    frequencies[i] = 0;
  }

  while((c = getchar()) != EOF) {
    ++frequencies[c];
  }

  for(i = 32; i < 128; i++) {
    printf("%c: ", i);
    for(j = 0; j < frequencies[i]; j++) {
      printf("*");
    }
    printf("\n");
  }

}
