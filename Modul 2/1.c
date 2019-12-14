#include <stdio.h>
#include <stdlib.h>

int main() {
    int t;
    scanf("%d", &t);
    int *n = malloc(t*sizeof(int));
    int i;
    for(i=0; i<t; i++) {
        scanf("%d", &n[i]);
    }
    for(i=i-1; i>=0; i--) {
        printf("%d\n", n[i]);
    }

    return 0;
}