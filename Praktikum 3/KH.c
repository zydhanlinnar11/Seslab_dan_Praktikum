#include <stdio.h>
#include <math.h>

int array[] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100};

int brpRumah(short);

int main() {
    short t, i, a;
    scanf("%hd", &t);
    for(i=0; i<t; i++) {
        scanf("%hd", &a);
        printf("%d rumah\n", brpRumah(a));
    }
    return 0;
}

int brpRumah(short a) {
    int i=10;
    int counter=0;
    while(a>0 && i>=0) {
        if(array[i]<=a) {
            a-=array[i];
            counter++;
        } else {
            i--;
        }
    }
    return counter;
}