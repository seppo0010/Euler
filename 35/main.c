#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <bigint.h>

int is_prime(int num) {
	return bi_is_probable_prime(int_to_bi(num), 9);
}

#define SIZE 1000000

#define STATE_UNKNOWN 0
#define STATE_NOT_PRIME 1
#define STATE_PRIME 2

#define DEBUG
#define DEBUG_STEP 1000

int main() {
	int i, j, k, c_digits;
	int value, prime, total;

	int cache[SIZE];
	for (i=0;i<SIZE;++i) cache[i] = STATE_UNKNOWN;

	total = 0;
	bi_initialize();
#ifdef DEBUG
	int from_cache = 0;
#endif
	for (i=2;i<SIZE;++i) {
		if (cache[i] == STATE_UNKNOWN) {
			c_digits = (int)ceil(log10((double)i));
			int* digits = malloc(sizeof(int) * c_digits);
			prime = 1;
			for (j=0;j<c_digits;j++) {
				digits[j] = (int)(i / pow(10, j)) % 10;
				if (digits[j] == 0 || (i != 5 && digits[j] == 5) || (i != 2 && digits[j] == 2) || digits[j] == 4 || digits[j] == 6 || digits[j] == 8) {
					prime = 0;
					break;
				}
			}
			if (prime == 0) continue;
			for (j=0;j<c_digits;j++) {
				value = 0;
				for (k=0;k<c_digits;k++) {
					value += digits[k] * pow(10, (k+j) % c_digits);
				}
				if (cache[value] != STATE_UNKNOWN) {
					prime = cache[i] == STATE_PRIME;
					break;
				}
				if (!is_prime(value)) {
					prime = 0;
					break;
				}
			}
			for (j=0;j<c_digits;j++) {
				value = 0;
				for (k=0;k<c_digits;k++) {
					value += digits[k] * pow(10, (k+j) % c_digits);
				}
				if (value > i) {
					cache[value] = prime ? STATE_PRIME : STATE_NOT_PRIME;
				}
			}
			free(digits);
		} else {
#ifdef DEBUG
			++from_cache;
#endif
			prime = cache[i] == STATE_PRIME;
		}
		if (prime) {
			++total;
		}
#ifdef DEBUG
		if (i % DEBUG_STEP == 0) {
			printf("Checkpoint %d (%d/%d)\n", i, from_cache, DEBUG_STEP);
			from_cache = 0;
		}
#endif
	}
	free(cache);
	bi_terminate();
	printf("%d\n", total);
	return 0;
}
