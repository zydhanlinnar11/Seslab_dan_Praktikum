#include <stdio.h>
#include <stdlib.h>
#define us unsigned

int main() {
    us n, m;
    printf("Input N and M for N x M array: ");
    scanf("%d %d", &n, &m);
    int ** array = (int **) malloc(n*sizeof(int));
    us i,j;
    for(i=0; i<n; i++) {
        *(array + i) = (int *) malloc(m*sizeof(int));
        for(j=0; j<m; j++) {
            scanf("%d", &array[i][j]);
        }
    }
    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            printf("%d%c", array[i][j], j!=m-1 ? ' ' : '\n');
        }
    }
    return 0;
}