#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <bigint.h>

#define SIZE 10000

int mod_and_divide(bigint* v, int m) {
	int c = bi_int_mod(bi_copy(*v), m);
	*v = bi_int_divide(*v, m);
	return c;
}

int main() {
	bi_initialize();

	int digits[100];
	int j, k;
	unsigned long long t = 0;
	for (k = 2; k < 100; k++) {
		if (k == 4 || k == 9 || k == 16 || k == 25 || k == 36 || k == 49 || k == 64 || k == 81) continue;
		bigint i;
		i = bi_sqrt(bi_multiply(int_to_bi(k), bi_power(int_to_bi(10), int_to_bi(200))));
		for (j = 0; !bi_is_zero(bi_copy(i)); j++) {
			digits[j % 100] = mod_and_divide(&i, 10);
		}
		for (j = 0; j < 100; j++) {
			t += digits[j];
		}
		bi_free(i);
	}
	bi_terminate();
	printf("%llu\n", t);

	return 0;
}
