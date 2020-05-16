#include <stdio.h>
#define ull unsigned long long

int main() {
    int n, k,i;
    int L[10000];
    ull sum = 0;
    scanf("%d %d", &n, &k);
    for(i=0; i<n; i++) {
        scanf("%d", &L[i]);
        sum += L[i];
    }
    int max = sum/k, min=0;
        //printf("max: %d\n", max);
    ull sum2;
    int mid;
    while(max>min) {
        mid = (max+min)/2;
        int j;
        sum2=0;
        for(j=0; j<n; j++) {
            sum2 += L[j]/mid;
        }
        if(sum2 == k) {
            break;
        } else if(sum2 >= k) {
            min = mid+1;
        } else {
            max = mid-1;
        }
    }
    while(sum2==k) {
        int j;
        mid++;
        sum2=0;
        for(j=0; j<n; j++) {
            sum2 += L[j]/mid;
        }
    }
    printf("%d\n", mid-1);
    return 0;
}