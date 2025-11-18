#include <stdio.h>

char *s = "#include <stdio.h>%c%cchar *s = %c%s%c;%c%cint main(void) {%c    printf(s, 10, 10, 34, s, 34, 10, 10, 10, 10, 10, 10);%c    return 0;%c}%c%c";

int main(void) { 
    printf(s, 10, 10, 34, s, 34, 10, 10, 10, 10, 10, 10);
    return 0;
}
