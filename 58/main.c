#include <stdio.h>
#include <bigint.h>

int main() {
	bi_initialize();
	bigint last = int_to_bi(1);
	int i, j;
	int number_of_primes = 0;
	for (i = 1;; ++i) {
		for (j = 0; j < 4; ++j) {
			last = bi_add(last, bi_int_multiply(int_to_bi(i), 2));
			if (j != 3 && bi_is_probable_prime(bi_copy(last), 4)) {
				++number_of_primes;
			}
		}
		if ((double)number_of_primes / (4*i+1) < 0.1) {
			printf("%d\n", i*2+1);
			break;
		}
#ifdef DEBUG
		printf("%d/%d on iteration %d ~%f\n", number_of_primes, (4*i+1), i, (float)number_of_primes/(4*i+1));
#endif
	}
	bi_free(last);
	bi_terminate();
	return 0;
}
