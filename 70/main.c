#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define SIZE 10000000
//#define SIZE 10

static inline int is_prime(int num) {
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

int is_permutation(unsigned long long num1, unsigned long long num2) {
	int digits[10];
	int i;
	for (i=0;i<10;++i) digits[i]=0;
	int size = (int)floor(log10(num1))+1;
	for (i=0;i<size;++i) digits[(unsigned long long)(num1/pow(10,i)) % 10]++;
	for (i=0;i<size;++i) if (--digits[(unsigned long long)(num2/pow(10,i)) % 10] < 0) return 0;
	return 1;
}

int main() {
	int *primes = malloc(sizeof(int) * SIZE);
	int q_primes = 0;
	int i, j;
	float ratio = -1.0;
	int min;
	for (i=0;i<SIZE;i++) {
		if (is_prime(i))
			primes[q_primes++] = i;
	}

	int n, v;
	for (i=0;i<q_primes;i++) {
		for (j=i;j<q_primes;j++) {
			n = primes[i] * primes[j];
			if (n < 0 || n < primes[i] || n < primes[j])  {
				if (j == i) break;
				else continue;
			}
			if (n > SIZE) {
				if (j == i) break;
				else continue;
			}
			v = (primes[i] - 1) * (primes[j] - 1);
			if (is_permutation(v, n)) {
				if ((float)n / v < ratio || ratio == -1.0) {
					ratio =  (float)n / v;
					min = n;
				}
			}
		}
	}
	printf("%d: %f\n", min, ratio);
	return 0;
}
