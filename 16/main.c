#include <stdio.h>

#define SIZE 305

void duplicate(int* digits) {
	int i;
	int extra = 0;
	for (i=SIZE-1;i>=0;--i) {
		digits[i] *= 2;
		digits[i] += extra;
		extra = 0;
		if (digits[i] >= 10) {
			int new_digit = digits[i] % 10;
			extra = digits[i] / 10;
			digits[i] = new_digit;
		}
	}
}

int main() {
	int digits[SIZE];
	int i;

	for (i=0; i < SIZE;i++) {
		digits[i] = 0;
	}

	digits[SIZE-1] = 1;

	for (i=0; i < 1000;i++) {
		duplicate(digits);
	}

	unsigned long long total = 0;
	for (i=0; i < SIZE;i++) {
		total += digits[i];
	}
	printf("%llu\n", total);
}
