#include <stdio.h>

void getSolutions(int, int, int, int, int);

int main() {
    int t,i;
    scanf("%d", &t);
    for(i=0; i<t;i++) {
        int var;
        scanf("%d", &var);
        int x=0, y=0, z=0, a;
        if(var==0) {
            scanf("%d", &a);
        } else if(var==1) {
            scanf("%d %d", &x, &a);
        } else if(var==2) {
            scanf("%d %d %d", &x, &y, &a);
        } else if(var==3) {
            scanf("%d %d %d %d", &x, &y, &z, &a);
        }
        getSolutions(var, x,y,z,a);
    }
}

void getSolutions(int var, int x, int y, int z, int a) {
    if(var==0) {
        printf("Puzzle Salah, coba lagi!\n");
    } else if(var==1) {
        printf("Puzzle Benar 1\n");
    } else if(var==2) {
        int i=0, count=0;
        while(x*i<=a) {
            int j=0;
            while((x*i) + (y*j)<=a) {
                //printf(" %d %d ", i, j);
                if((x*i) + (y*j)==a){
                    count++;
                }
                j++;
            }
            i++;
        }
        if(count!=0)
            printf("Puzzle Benar %d\n", count);
        else printf("Puzzle Salah, coba lagi!\n");
    } else if(var==3) {
        int i=0, count=0;
        while(x*i<=a) {
            int j=0;
            while((x*i) + (y*j)<=a) {
                int k=0;
                while((x*i) + (y*j) + (z*k) <=a) {
                    if((x*i) + (y*j) + (z*k) ==a) count++;
                    k++;
                }
                j++;
            }
            i++;
        }
        if(count!=0)
            printf("Puzzle Benar %d\n", count);
        else printf("Puzzle Salah, coba lagi!\n");
    }
}