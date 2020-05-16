#include <stdio.h>

int main() {
    int t, i;
    scanf("%d", &t);
    for(i=0; i<t; i++) {
        int w, h, tujuan, j;
        int left[102] = {0}, right[102] = {0};
        scanf("%d %d %d", &w, &h, &tujuan);
        for(j=0; j<h; j++) {
            int a, b;
            scanf("%d %d", &left[j], &right[j]);
        }
        int start = tujuan;
        for(j=h-1; j>=0; j--) {
            if(left[j]==start) start = right[j];
            else if(right[j]==start) start = left[j];
        }
        printf("%d\n",start);
    }
    return 0;
}