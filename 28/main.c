#include <stdio.h>
#include <bigint.h>

#define SIZE 1001

int main() {
	bi_initialize();
	bigint sum = int_to_bi(1);
	bigint last = int_to_bi(1);
	int i, j;
	for (i = 1; i <= (SIZE-1)/2; ++i) {
		for (j = 0; j < 4; ++j) {
			last = bi_add(last, bi_int_multiply(int_to_bi(i), 2));
			sum = bi_add(sum, bi_copy(last));
		}
	}
	bi_print(stdout, sum);
	printf("\n");
	bi_free(last);
	bi_terminate();
	return 0;
}
