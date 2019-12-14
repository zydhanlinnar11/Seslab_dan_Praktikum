#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int n;

int max(int *a) {
    int h = INT_MIN;
    int i;
    for(i=0; i<n; i++) {
        if(h<a[i]) {
            h = a[i];
        }
    }
    return h;
}

int min(int *a)  {
    int h = INT_MAX;
    int i;
    for(i=0; i<n; i++) {
        if(h>a[i]) {
            h = a[i];
        }
    }
    return h;
}

int main() {
    scanf("%d", &n);
    int *a = malloc(n*sizeof(int));
    int i;
    for(i=0;i<n;i++) {
        scanf("%d", &a[i]);
    }
    printf("max: %d\n", max(a));
    printf("min: %d\n", min(a));
}