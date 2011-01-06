#include <stdio.h>
#include <bigint.h>

int main() {
	bi_initialize();
	int a, b, n;
	int max_number, prod;
	for (a = -999; a < 1000; ++a) {
		for (b = -999; b < 1000; ++b) {
			n = 0;
			for (;;) {
				bigint a_ = int_to_bi(a);
				bigint b_ = int_to_bi(b);
				bigint n_ = int_to_bi(n);
				bigint n2 = bi_multiply( bi_copy( n_ ), bi_copy( n_ ) );
				bigint an = bi_multiply(bi_copy(a_),bi_copy(n_));
				bigint num = bi_add(bi_copy(n2), bi_copy(an));
				bigint num2 = bi_add(bi_copy(num), bi_copy(b_));
				int should_break = 0;
				if (bi_is_probable_prime(bi_copy(num2), 99)) {
					++n;
				} else {
					if (n > max_number) {
						max_number = n;
						prod = a * b;
					}
					should_break = 1;
				}
				bi_free(num); 
				bi_free(num2); 
				bi_free(a_); 
				bi_free(b_); 
				bi_free(n_); 
				bi_free(n2);
				bi_free(an);
				if (should_break) break;
			}
		}
	}
	printf("%d\n", prod);
	bi_terminate();
	return 0;
}
