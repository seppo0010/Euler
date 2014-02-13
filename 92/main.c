#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10000000

int sum_square_digits(int num) {
	int v = 0;
	while (num != 0) {
		v += (num % 10) * (num % 10);
		num /= 10;
	}
	return v;
}

int main() {
	int i, v, prev_v, c = 0;

	for (i = 1; i < SIZE; i++) {
		v = sum_square_digits(i);
		while (v != 89 && v != 1) {
			prev_v = v;
			v = sum_square_digits(v);
		}
		if (v == 89) {
			c++;
		}
	}
	printf("%d\n", c);
	return 0;
}
