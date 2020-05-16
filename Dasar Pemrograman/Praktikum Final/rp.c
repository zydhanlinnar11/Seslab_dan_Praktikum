#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    int t, i;
    scanf("%d", &t);
    for(i=1; i<=t; i++) {
        int l;
        scanf("%d", &l);
        char x[100][41];
        int j;
        for(j=0; j<l; j++) {
            scanf("%s", x[j]);
        }
        char aaa[41];
        scanf("%s", aaa);
        bool found = false;
        for(j=0; j<l; j++) {
            if(strcmp(aaa, x[j])==0) {
                printf("Yay ada di laci ke-%d (/^_^)/\n", j+1);
                found = true;
                break;
            }
        }
        if(!found) printf("Ga ketemuu (-_-;)\n");
    }
    return 0;
}
