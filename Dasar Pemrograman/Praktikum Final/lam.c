#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool rusuh = false;
int salipan[100010] = {0};
int sum;

void swap(int * a, int * b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void bubblesort(int arr[], int size) {
    bool urut = false;
    while (!(urut || rusuh)){
        int i;
        urut = true;
        for(i=0; i<size; i++) {
            if(arr[i] > arr[i+1]) {
                urut = false;
                swap(&arr[i], &arr[i+1]);
                sum++;
            }
        }
    }
}

int main() {
    int i, t;
    int n[100010];
    scanf("%d", &t);
    for(i=0; i<t; i++) {
        rusuh = false;
        sum = 0;
        int j, antrian;
        scanf("%d", &antrian);
        for(j=0; j<antrian; j++) {
            if(rusuh) {
                scanf("%*d");
                continue;
            }
            salipan[j] = 0;
            scanf("%d", &n[j]);
            if(n[j] > j && (n[j]-j - 1) > 2) {
                rusuh = true;
                // printf("rusuh di index %d dengan nilai %d\n", j, n[j]);
            }
        }
        if(!rusuh) bubblesort(n, antrian-1);
        // for(j=0; j<antrian; j++)
        //     printf("%d nyalip %dx\n", j+1, salipan[j]);
        if(rusuh) printf("Rusuh gan\n");
        else printf("%d\n", sum);
    }
    return 0;
}