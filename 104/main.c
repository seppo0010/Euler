#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <bigint.h>

int is_pandigital(int num) {
	int i, nums[10];
	for (i = 0; i < 10; i++) nums[i] = 0;
	while (num != 0) {
		if (num % 10 == 0) return 0;
		if (nums[num % 10]++ > 0) {
			return 0;
		}
		num /= 10;
	}
	return 1;
}

int main() {
	bi_initialize();
	int k = 2;
	bigint f1 = int_to_bi(1), f2 = int_to_bi(1), f3, tmp;
	bigint zeros = int_to_bi(1000000000);
	while (1) {
		k++;
		f3 = bi_add(f1, bi_copy(f2));
		int mod = bi_int_mod(bi_copy(f3), 1000000000);
		if (mod >= 100000000) {
			if (is_pandigital(mod)) {
				tmp = bi_copy(f3);
				while (bi_compare(bi_copy(tmp), bi_copy(zeros)) > 0) {
					tmp = bi_int_divide(tmp, 10);
				}
				if (is_pandigital(bi_to_int(tmp))) {
					break;
				}
			}
		}
		f1 = f2;
		f2 = f3;
	}
	bi_free(f2);
	bi_free(f3);
	bi_free(zeros);
	printf("%d\n", k);
	bi_terminate();
	return 0;
}
