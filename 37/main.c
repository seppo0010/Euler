#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <bigint.h>

int is_prime(int num) {
        return bi_is_probable_prime(int_to_bi(num), 9);
}

int main() {
	int found = 0;
	int i, j, k, n;
	int possible;
	int total = 0;
	bi_initialize();
	for (i=11;found<11;i+=2) {
#ifdef DEBUG
		if (i % 1000 == 1) {
			printf("Looping on %d\n", i);
		}
#endif
		int digits = 1+(int)floor(log10((double)i));
		possible = 1;
		for (j=0;j<digits;++j) {
			n = (i / (int)pow(10, j)) % 10;
			if (j == digits-1) {
				if (n != 2 && n != 3 && n != 5 && n != 7) {
					possible = 0; break;
				}
			} else if (j == 0) {
				if (n != 3 && n != 7) {
					possible = 0; break;
				}
			} else {
				if (n != 1 && n != 2 && n != 3 && n != 5 && n != 7 && n != 9) {
					possible = 0; break;
				}
			}
		}
		if (possible == 0) continue;
		if (!is_prime(i)) continue;

		for (j=1;j<digits;++j) {
			n = 0;
			for (k=0;k<j;++k) {
				n += ((i / (int)pow(10, k)) % 10) * pow(10, k);
			}
			if (!is_prime(n)) {
				possible = 0;
				break;
			}
		}
		if (possible == 0) continue;

		for (j=1;j<digits;++j) {
			n = 0;
			for (k=0;k<j;++k) {
				n += ((i / (int)pow(10, digits-k-1)) % 10) * (int)pow(10,j-k-1);
			}
			if (!is_prime(n)) {
				possible = 0;
				break;
			}
		}

		if (possible == 0) continue;

#ifdef DEBUG
		printf("%d\n", i);
#endif
		total += i;
		++found;
	}
	printf("%d\n", total);
	bi_terminate();
	return 0;
}
