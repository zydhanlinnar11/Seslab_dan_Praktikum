#include <stdio.h>

int main() {
	int a,b,c,d,sdh=0,sa,sb;
	int i,j;
	scanf("%d %d %d %d", &a,&b,&c,&d);
	for(i=1; i<=c; i++) {
		if(b==1) {
			for (j=1; j<=d; j++) {
				if(i>(c-a))
					printf("=");
				else {
					if(j==(d/2)+1)
						printf("0");
					else printf("#");
				}
			}
			printf("\n");
		} else if(b==2) {
			for (j=1; j<=d; j++) {
				if(i>(c-a))
					printf("=");
				else if(i%2==0) {
					if(j==(d/2)+1)
						printf("0");
					else printf("#");
				} else printf("#");
			}
			printf("\n");
		} else {
				if(i<(b-1)) {
					for (j=1; j<=d; j++) {
						printf("=");
					}
					printf("\n");
					sdh++;
					continue;
				}
				if((c-i+1)<=(a-sdh)) {
					for(j=1; j<=d; j++) {
						printf("=");
					}
					printf("\n");
				} else if (i%b==0) {
					for (j=1; j<=d; j++) {
						if(j==(d/2)+1)
							printf("0");
						else printf("#");
					}
					sa=i+2;
					sb=i+b-2;
					printf("\n");
				} else if(i>=sa && i<=sb && (sdh!=a)) {
					for (j=1; j<=d; j++) {
						printf("=");
					}
					printf("\n");
					sdh++;
				} else {
					for(j=1; j<=d; j++) {
						printf("#");
					}
					printf("\n");
				}
		}
	}
	return 0;
}
