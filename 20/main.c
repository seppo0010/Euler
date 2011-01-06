#include <stdio.h>

#define SIZE 160

void multiple(int* digits, int by) {
	int i;
	int extra = 0;
	for (i=SIZE-1;i>=0;--i) {
		digits[i] *= by;
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

	for (i=2; i < 100;i++) {
		multiple(digits, i);
	}

	int total = 0;
	for (i=0; i < SIZE;i++) {
		total += digits[i];
	}
	printf("%d\n", total);
}
