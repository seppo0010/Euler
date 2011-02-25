#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define DEBUG

int is_prime(int num) {
	if (num == 1) return 0;
	if (num == 2 || num == 5 || num == 7 || num == 3) return 1;
	if ((num&1)==0) return 0;
	if (num < 11) return 0;
	if (num % 3 == 0) return 0;
	int r = sqrt(num);
	int f;
	for (f = 5; f <= r; f+=6) {
		if (num % f == 0) return 0;
		if (num % (f+2) == 0) return 0;
	}
	return 1;
}

int are_coprime(int num1, int num2) {
	if ((num1 & 1) == 0 && (num2 & 1) == 0) return 0; // even check
	int i;
	for (i = 3; i <= num1; i+=2) {
		if (num1 % i == 0 && num2 % i == 0) return 0;
	}
	return 1;
}

int main() {
	int i,j,c;
	int broken;
	int max_i=0;
	double ratio,max_ratio=0.0;
	for (i=2;i<=10000;++i) {
		c = 1;
		broken = 0;
		if (is_prime(i)) {
			c = i-1;
		} else {
			for (j=i-1;j>=2;j--) {
				c += are_coprime(i,j);
				if ((double)i/c < max_ratio) {broken=1;break;}
			}
			if (broken) continue;
		}
#ifdef DEBUG
		printf("%d %d\n", i, c);
#endif
		ratio = (double)i/c;
		if (ratio > max_ratio) {
			max_ratio = ratio;
			max_i = i;
		}
	}
	printf("%d\n", max_i);
	return 0;
}
