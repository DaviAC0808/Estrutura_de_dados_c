#include <stdio.h>
#include <stdlib.h>

int main() {
    char s[30];
    fgets(s, 30, stdin);
    fflush(stdin);
    printf("Language\n"); //FGETS
    
    printf("Welcome To %s!!", s);
    puts("");
    fflush(stdin);
}
