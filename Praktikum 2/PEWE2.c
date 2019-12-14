#include <stdio.h>
#include <string.h>

int main() {
    char n[1001];
    gets(n);
    int t;
    scanf("%d", &t);
    int z;
    for(z=1; z<=t; z++) {
        char anu[5];
        int ke;
        scanf("%s %d", &anu, &ke);
        int i;
        int spasi=0;
        int kosong=0;
        for(i=0; i<strlen(n); i++) {
            if(n[i]== ' ') {
                spasi++;
                continue;
            }
            if(ke==spasi+1) {
                break;
            } else if((i==strlen(n)-1) && (ke!=spasi+1)) {
                kosong=1;
            }
        }
        if(kosong==0) {
            int j=i;
            while(!(n[j]==' ' || n[j]== '\0')) {
                j++;
            }
            int p;
            for(p=i; p<=j;p++) {
                if ((n[p]>='A'&& n[p]<='Z') || (n[p]>='a'&&n[p]<='z')) {
                    putchar(n[p]);
                }
            }
            } else {
                printf("Kosong!");
            }
        putchar('\n');
    }
    
    return 0;
}