#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  printf ("%d\n", argc);
  for (int i=1; i < argc; i++) {
    printf("%s\n", argv[i]);
  }

  char* firstLetter = argv[1];
  printf("%p\n", firstLetter);

  printf("%c\n", firstLetter);
  return 0;
}
