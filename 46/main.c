#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <bigint.h>

#define DEBUG_STEP 1000

int main() {
	int i, j, k, v, found;
	bi_initialize();
	for (i=35;;i+=2) {
		if (bi_is_probable_prime(int_to_bi(i), 9)) continue;
		found = 0;
		for (j=i-2;j>2;j-=2) {
			if (!bi_is_probable_prime(int_to_bi(j), 9)) continue;
			for (k=1;k<i;++k) {
				v = j+2*k*k;
				if (v==i) {
					found = 1;
					break;
				} else if (v > i) {
					break;
				}
			}
			if (found) break;
		}
		if (!found) {
			printf("%d\n", i);
			break;
		}
#ifdef DEBUG
		if (i % DEBUG_STEP == 1)
			printf("%d\n", i);
#endif
	}
	bi_terminate();
	return 0;
}
