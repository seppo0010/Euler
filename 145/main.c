#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NUMBER 1000000000

int is_all_odd(long long num) {
	while (num != 0) {
		if (num % 2 == 0) return 0;
		num /= 10;
	}
	return 1;
}

long long reverse(long long num) {
	long long r = 0;
	while (num != 0) {
		r *= 10;
		r += num % 10;
		num /= 10;
	}
	return r;
}

int main() {
	long long i, c = 0;
	for (i = 0; i < MAX_NUMBER; i++) {
		if (i % 10 == 0) continue;
		c += is_all_odd(i + reverse(i));
	}
	printf("%lld\n", c);
	return 0;
}
