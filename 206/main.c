#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
	unsigned long long i, s;

	for (i = 0;;i++) {
		s = i * i;
		if (s % 10 == 0 &&
				(s / 100) % 10 == 9 &&
				(s / 10000) % 10 == 8 &&
				(s / 1000000) % 10 == 7 &&
				(s / 100000000) % 10 == 6 &&
				(s / 10000000000) % 10 == 5 &&
				(s / 1000000000000) % 10 == 4 &&
				(s / 100000000000000) % 10 == 3 &&
				(s / 10000000000000000) % 10 == 2 &&
				(s / 1000000000000000000) % 10 == 1) {
			printf("%llu\n", i);
			break;
		}
	}
	return 0;
}
