#include <stdio.h>
#include <stdlib.h>

typedef struct query {
    int val, min, index;
}q;

int main() {
    int i, n, index = 0;
    q *anjay = (q *) malloc(200000 * sizeof(q));
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        short qq;
        scanf("%hd", &qq);
        if(qq==2) {
            if(index == 0) printf("KOSONG!!\n");
            else {
                printf("Nilai sekarang : %d\nNilai minimum berada pada index ke-%d dengan nilai %d\n", anjay[index - 1].val, anjay[index - 1].index, anjay[index - 1].min);
                index--;
            }
        } else {
            scanf("%d", &anjay[index].val);
            if(index == 0) {
                anjay[0].min = anjay[0].val;
                anjay[0].index = 0;
            } else {
                if(anjay[index].val < anjay[index-1].min) {
                    anjay[index].min = anjay[index].val;
                    anjay[index].index = index;
                } else if(anjay[index].val == anjay[index-1].min) {
                    anjay[index].min = anjay[index-1].min;
                    anjay[index].index = anjay[index-1].index;
                } else {
                    anjay[index].min = anjay[index-1].min;
                    anjay[index].index = index - 1;
                }
            }
            index++;
        }
    }
    return 0;
}