#include <stdio.h>

int main() {
	int x,i,sum=0;
	scanf("%d", &x);
	if(x%2==1)
		x+=1;
	sum = (5 * ((x << 1) + 8));
	sum >>= 1;
	printf("%d\n",sum);
	return 0;
}
