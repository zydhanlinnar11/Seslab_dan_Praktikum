#include <stdio.h>
#include <string.h>

int main() {
    char s[101];
    int und=0;
    int i;
    scanf("%s", &s);
    int len=strlen(s);
    for(i=0; i<len; i++) {
        if(s[i]>='A' && s[i]<='Z') {
            if(s[i]=='_') {
                continue;
            }
            if(s[i]!=0 && s[i-1]=='_') {
                putchar(s[i]);
            } else {
                putchar((s[i]-'A'+'a'));
            }
        } else {
            if(s[i]=='_') {
                continue;
            }
            if(s[i]!=0 && s[i-1]=='_') {
                putchar((s[i]-'a'+'A'));
            } else {
                putchar(s[i]);
            }
        }
    }
    printf("\n");
    return 0;
}