#include <stdio.h>
#include <string.h>

int main() {
    char s[101];
    int a=0;
    int i=0;
    int u=0;
    int e=0;
    int o=0;
    int p;
    gets(s);

    for(p=0;p<strlen(s);p++) {
        if(s[p] == 'A' || s[p] == 'a') {
            a++;
        } else if(s[p] == 'I' || s[p] == 'i') {
            i++;
        } else if(s[p] == 'U' || s[p] == 'u') {
            u++;
        } else if(s[p] == 'E' || s[p] == 'e') {
            e++;
        } else if(s[p] == 'O' || s[p] == 'o') {
            o++;
        }
    }

    printf("A/a : %d\n", a);
    printf("I/i : %d\n", i);
    printf("U/u : %d\n", u);
    printf("E/e : %d\n", e);
    printf("O/o : %d\n", o);

    return 0;
}