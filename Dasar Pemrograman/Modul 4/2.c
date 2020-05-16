#include <stdio.h>
#include <string.h>

void inputInt(int *);
void inputStr(char *);
void inputStrN(char *, int * const);

int main() {
    int a, b;
    char string[100], string2[100];
    printf("Input an integer: ");
    inputInt(&a);
    printf("Input string: ");
    inputStr(string);
    printf("Input string and length: ");
    char stringtmp[100];
    memset(string2, 0, 100);
    memset(stringtmp, 0, 100);
    inputStrN(stringtmp, &b);
    strncpy(string2, stringtmp, b);

    printf("Integer: %d\n", a);
    printf("String: %s\n", string);
    printf("StringN: %s\n", string2);

    return 0;
}

void inputInt(int * a) {
    scanf("%d", a);
    getchar();
}
void inputStr(char string[]) {
    gets(string);
}
void inputStrN(char string[], int * const a) {
    scanf("%s %d", string, a);
}