#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <bigint.h>

int is_permutation(int n1, int n2) {
	int values[10];
	int i;
	for (i=0;i<10;++i) values[i] = 0;
	++values[n1%10];
	++values[(n1/10)%10];
	++values[(n1/100)%10];
	++values[(n1/1000)%10];
	if (--values[n2%10] < 0) return 0;
	if (--values[(n2/10)%10] < 0) return 0;
	if (--values[(n2/100)%10] < 0) return 0;
	if (--values[(n2/1000)%10] < 0) return 0;
	return 1;
}

int is_prime(int num) {
        return bi_is_probable_prime(int_to_bi(num), 9);
}

int main() {
	bi_initialize();
	int i, j;
	for (i=1000;i<=10000;++i) {
		if (i==1487) continue;
		if (!is_prime(i)) continue;
		for (j=(10000-i)/2; j>0;--j) {
			if (is_prime(i+j) && is_prime(i+2*j)) {
				if (is_permutation(i,i+j) && is_permutation(i,i+2*j)) {
					printf("%d%d%d\n",i,i+j,i+2*j);
					i = 10000;
					break;
				}
			}
		}
	}
	bi_terminate();
	return 0;
}
