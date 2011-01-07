#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MIN(a,b) (a>b?b:a)
#define MAX(a,b) (a<b?b:a)

unsigned long long factorial (unsigned long long n, unsigned long long upto) {
	if (n == upto || n < 2) return 1;
	return n * factorial(n-1, upto);
}

unsigned long long combinatorics(unsigned long long n, unsigned long long r) {
	return factorial(n, MAX(r, n-r)) / factorial(MIN(r, n-r), 1);
}

int main() {
	int i, j, c = 0;
	for (i=1;i<=100;++i) {
		for (j=1;j<i/2;++j) {
			if (combinatorics(i, j) > 1000000) {
#ifdef DEBUG
				printf("%dc%d + %d\n", i, j,i-2*j+1);
#endif
				c += i-2*j+1;
				j += i;
			}
		}
#ifdef DEBUG
	if (i % 1000 == 0) printf("%d\n", i);
#endif
	}
	printf("%d\n", c);
	return 0;
}
