#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int is_bouncy(int n) {
	if (n < 100) return 0;
	int decreasing = 0, increasing = 0, last_digit = -1;
	while (n > 0) {
		if (last_digit != -1) {
			if (n % 10 > last_digit) increasing = 1;
			else if (n % 10 < last_digit) decreasing = 1;
		}
		last_digit = n % 10;
		n /= 10;
		if (increasing && decreasing) return 1;
	}
	return 0;
}

int main() {
	int i, bouncies = 0;
	for (i = 1;;i++) {
		bouncies += is_bouncy(i);
		if ((float)i * 99 / 100 < bouncies) {
			break;
		}
	}
	printf("%d\n", i);
	return 0;
}
