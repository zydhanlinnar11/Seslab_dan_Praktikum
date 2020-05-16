#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct hh {
    char y[21];
    int kelipatan;
}ya;

int main() {
    int t, i, n;
    scanf("%d", &t);
    ya *yagitu = malloc(t*sizeof(ya));
    for(i=0; i<t; i++) {
        scanf("%d", &yagitu[i].kelipatan);
        scanf("%s", yagitu[i].y);
    }
    scanf("%d", &n);
    for(i=1; i<=n; i++) {
        bool k = false;
        int j;
        for(j=0; j<t; j++) {
            if(i % yagitu[j].kelipatan == 0) {
                printf("%s", yagitu[j].y);
                k = true;
            }
        }
        if(!k) printf("%d", i);
        printf("\n");
    }
    return 0;
}