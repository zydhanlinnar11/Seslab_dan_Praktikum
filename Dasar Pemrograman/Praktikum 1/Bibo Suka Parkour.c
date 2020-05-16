#include <stdio.h>

int main() {
	int p,hi1,hi2,n,i=1;
	int a,b,gagal=0;
	
	scanf("%d %d", &p,&n);
	for( i=1; i<=n; i++) {
		if(i==1) {
			scanf("%d %d",&hi1,&hi2);
		} else if(i==2){
			continue;
		} else {
			hi1=hi2;
			scanf("%d",&hi2);
		}
		if((hi2-hi1)>0) {
			if ((hi2-hi1)<p) {
				continue;
			} else {
				gagal=1;
				break;
			}
		} else {
			if ((hi1-hi2)<p) {
				continue;
			} else {
				gagal=1;
				break;
			}
		}
	}
	
	if(gagal==1) {
		printf("GAGAL!\n");
	} else {
		printf("BERHASIL!\n");
	}
	return 0;
}
