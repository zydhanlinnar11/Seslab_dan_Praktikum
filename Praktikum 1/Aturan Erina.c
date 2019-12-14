#include <stdio.h>

int main() {
	unsigned long long t, n, sum;
	scanf("%llu",&t);
	while (t--) {
		scanf("%llu", &n);
		if(n==1) {
			printf("1\n");
		} else {
			sum=(n/2)+((n-2)*(n+1)/2);
			printf("%llu\n", sum);
		}
	}
	return 0;
}
