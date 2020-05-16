#include <stdio.h>
#include <string.h>

int gcd(int a, int b) {
    if(a % b == 0) return b;
    else return gcd(b, a%b);
}

int main() {
    int t, i, lenarr[2];
    scanf("%d", &t);
    for(i=1; i<=t; i++) {
        char S[101];
        int cha[26] = {0};
        scanf("%s", S);
        int j;
        int same=0, len = strlen(S);
        if(i % 3 == 1) lenarr[0] = len;
        else if(i % 3 == 2) lenarr[1] = len;
        for(j=0; j<len; j++) {
            if(S[j]>='A' && S[j]<='Z') {
                cha[S[j]-'A']++;
            } else if(S[j]>='a' && S[j]<='z') {
                cha[S[j]-'a']++;
            }
        }
        for(j=0; j<26; j++) {
            // printf("%c: %d\n", j+'A', cha[j]);
            if(cha[j]>1) {
                same += (cha[j]-1);
                // printf("%c: %d\n", j+'A', cha[j]);
            }
        }
        // printf("%d\n", len-same);
        if (i % 3 == 0) {
            int a = lenarr[0]+lenarr[1];
            int b = len;
            int temp = a;
            if(a<b) {
                a = b;
                b = temp;
            }
            if(gcd(a, b) % 3 == 0) printf("Congratulation, the gate is opened, but you must continue to try other combination.\n");
            else printf("Please try again.\n");
        } else if((len-same) % 2 == 0) printf("Somehow the puzzle is solved.\n");
        else printf("The puzzle is still unsolved.\n");
    }
    return 0;
}