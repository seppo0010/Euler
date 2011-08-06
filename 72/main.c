#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define SIZE 1000000
//#define SIZE 8

#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)

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

int gcd(int num1, int num2) {
	int remainder = num1 % num2;
	if (remainder == 0) return num2;
	return gcd(MAX(num2, remainder), MIN(num2, remainder));
}

int are_coprime(int num1, int num2) {
	if (num2 == 1) return 1;
	if ((num1 & 1) == 0 && (num2 & 1) == 0) return 0; // even check
	if (num1 % num2 == 0) return 0;
	return gcd(num1, num2) == 1;
}

int divisors(int val, int *divisors_list) {
	int i, divisors_pos=0;

	if (!is_prime(val)) {
		i = val/2;
		if ((val&1)==0)divisors_list[divisors_pos++] = 2;
		if ((i&1)==0)i--;
		for (; i > 1; i-=2) {
			if (val % i == 0 && is_prime(i)) {
				divisors_list[divisors_pos++] = i;
			}
		}
	}

	return divisors_pos;
}

int main() {
	int *phis = malloc(sizeof(int) * (1+SIZE));

	int *temp_divisors = malloc(sizeof(int) * SIZE);
	int temp_pos = 0;

	int i, j, v, v2;
	unsigned long long c = 0llu;
	for (i=0;i<=SIZE;i++) phis[i]=0;
	phis[1] = 1;

	for (i=2;i<=SIZE;i++) {
		if (phis[i] == 0) {
			if (is_prime(i)) {
				phis[i] = i - 1;
				for (j=2;j<i;j++) {
					v = j * i;
					if (v > SIZE) break;
					if (phis[v] == 0) phis[v] = phis[i] * phis[j];
				}
			} else {
				temp_pos = divisors(i, temp_divisors);
				phis[i] = i;
				for (j=0;j<temp_pos;j++) {
					phis[i] *= (1 - 1.0 / temp_divisors[j]);
				}

				for (j=2;j<i;j++) {
					v2 = gcd(i, j);
					v = j * i;
					if (v > SIZE) break;
					if (v < i) break;
					if (phis[v] == 0) phis[v] = phis[i] * phis[j] * v2 / phis[v2];
				}
			}
		}
		c += phis[i];
		for (j = 2; ;j++) {
			v = pow(i, j);
			if (v > SIZE) break;
			if (v < i) break;
			phis[v] = pow(i, j - 1) * phis[i];
		}
	}
	free(phis);
	free(temp_divisors);
	printf("%llu\n", c);
	return 0;
}
