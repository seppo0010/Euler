#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <bigint.h>

#define SIZE 4

int number_of_factors(int num) {
	int i,c = 0;
	for (i=2;num>1;++i) {
		if (num % i == 0 && bi_is_probable_prime(int_to_bi(i), 9)) {
			++c;
			do { num /= i; } while (num % i == 0);
		}
	}
	return c;
}

int main() {
	bi_initialize();
	int i;
	int consecutive = 0;
	for (i=2;;++i) {
		if (bi_is_probable_prime(int_to_bi(i), 9)) {
			consecutive = 0;
			continue;
		}

		if (number_of_factors(i) >= SIZE) {
			if (++consecutive == SIZE) {
				printf("%d\n", i-SIZE+1);
				break;
			}
		} else {
			consecutive = 0;
		}
	}
	bi_terminate();
	return 0;
}
