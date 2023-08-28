#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int test(int x) {
  for (;x < 10; --x) {printf("%d\n", x);}
}

int main(int argc, char **argv) {
  int x = (atoi(argv[1]));
  test(x);
}
