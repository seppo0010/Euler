#include <stdio.h>

#define SIZE 10000

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

int* divisors(int val) {
	int* retval = malloc(sizeof(int) * SIZE);
	int i, j;
	for (i = 0; i < SIZE; i++) retval[i] = 0;
	retval[1] = 1;

	if (!is_prime(val)) {
		for (i = val/2; i > 1; --i) {
			if (val % i == 0) {
				retval[i] = 1;
			}
		}
	}
	return retval;
}

int sum_of_divisors(int num) {
	int i;
	int value = 0;
	int* a = divisors(num);
	for (i=0;i<SIZE;++i) {
		value += i * a[i];
	}
	return value;
}

int main() {
	int i;
	int total = 0;
	for (i=0;i<SIZE;++i) {
		if (is_prime(i)) continue;
		int s = sum_of_divisors(i);
		if (i < s && sum_of_divisors(s) == i) {
			total += i + s;
		}
	}
	printf("%d\n", total);
}
