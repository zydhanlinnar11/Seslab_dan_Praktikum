#include <stdio.h>
#include <string.h>

int main() {
    char tawa[51], anjay[51];
    scanf("%s", &tawa);
    int i;
    int j=0;
    for(i=0; i<strlen(tawa); i++) {
        if(tawa[i]=='a' || tawa[i]=='i' || tawa[i]=='u' || tawa[i]=='e' || tawa[i]=='o') {
            anjay[j]=tawa[i];
            j++;
        }
    }
    int palin=1;
    int len = strlen(anjay);
    for(i=0; i<len/2; i++) {
        if(anjay[i]!=anjay[len-i-1]) {
            palin=0;
            break;
        }
    }
    printf("%s\n", (palin==1) ? "ngakak beneran" : "pura-pura ngakak");
    return 0;
}