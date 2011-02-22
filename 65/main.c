#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <bigint.h>

int main() {
	bi_initialize();
	bigint prev = int_to_bi(2);
	bigint cur = int_to_bi(3);
	bigint prev_prev;
	int i = 2;
	int m;
	while (++i <= 100) {
		if (i % 3 == 0) m = 2 * (i / 3);
		else m = 1;
		prev_prev = prev;
		prev = bi_copy(cur);
		cur = bi_add(bi_int_multiply(prev, m), prev_prev);
#ifdef DEBUG
		bi_print(stdout, bi_copy(cur));
		printf("\n");
#endif
	}

	int r = 0;
	bigint zero = int_to_bi(0);
	while (1) {
		r += bi_int_mod(bi_copy(cur), 10);
		cur = bi_int_divide(cur, 10);
		if (bi_compare(bi_copy(cur), bi_copy(zero)) == 0) break;
	}
	printf("%d\n", r);
	bi_free(zero);
	bi_free(prev);
	bi_free(cur);
	bi_terminate();
	return 0;
}
