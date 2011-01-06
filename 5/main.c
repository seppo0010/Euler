#include <stdio.h>

#define MAX(a,b) a > b ? a : b;

int position(int prime) {
	switch (prime) {
		case 2: return 0;
		case 3: return 1;
		case 5: return 2;
		case 7: return 3;
		case 11: return 4;
		case 13: return 5;
		case 17: return 6;
		case 19: return 7;
	}
	return -1;
}

int* divisors(int val) {
	int* retval = malloc(sizeof(int) * 8);
	int i, j;
	for (i = 0; i < 8; i++) retval[i] = 0;

	int pos = position(val);
	if (pos > -1) {
		retval[pos] = 1;
	} else {
		for (i = val / 2; i > 1; --i) {
			if (val % i == 0) {
				int* divs = divisors(i);
				for (j = 0; j < 8; ++j) {
					retval[j] = retval[j] + divs[j];
				}
				free(divs);

				divs = divisors(val/i);
				for (j = 0; j < 8; ++j) {
					retval[j] = retval[j] + divs[j];
				}
				free(divs);

				break;
			}
		}
	}
	return retval;
}

int main() {
	int primes[8] = {0,0,0,0,0,0,0,0};
	int i, j;
	for (i = 20; i > 0; --i) {
		if (is_prime(i)) {
			int pos = position(i);
			if (primes[pos] == 0) primes[pos] = 1;
		} else {
			int* local_primes = divisors(i);
			for (j = 0; j < 8; j++) {
				if (local_primes[j] > primes[j]) primes[j] = local_primes[j];
			}
			free(local_primes);
		}
	}

	int total = 1;
	for (i = 20; i > 0; --i) {
		if (is_prime(i)) {
			int pos = position(i);
			for (j = 0; j < primes[pos]; ++j) {
				total *= i;
			}
		}
	}
	printf("%d\n", total);
}

int is_prime(int num) {
	if (num == 0) return 1;
	if (num == 1) return 0;
	if (num == 2) return 1;
	if (num != 2 && num % 2 == 0) return 0;
	int num2, num3;
	for (num3 = 2; num3 < num / 2; ++num3) {
		num2 = num / num3;
		if (num % num2 == 0) {
			if (is_prime(num2)) {
				return 0;
			}
		}
	}
	return 1;
}
