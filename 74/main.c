#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define SIZE 1000000
//#define SIZE 50

int factorial(int n) {
	switch (n) {
		case 0:
		case 1:
			return 1;
		case 2:
			return 2;
		case 3:
			return 6;
		case 4:
			return 24;
		case 5:
			return 120;
		case 6:
			return 720;
		case 7:
			return 5040;
		case 8:
			return 40320;
		case 9:
			return 362880;
		default:
			return n * factorial(n-1);
	}
}

int sum_digits_factorials(int num) {
	int i, v = 0;
	int size = (int)floor(log10(num))+1;
	for (i=0;i<size;++i) {
		v += factorial((unsigned long long)(num/pow(10,i)) % 10);
	}
	return v;
}

int has_factorials(int factorials[], int factorials_pos, int sum) {
	int i;
	for (i = 0; i < factorials_pos; i++) {
		if (factorials[i] == sum) return 1;
	}
	return 0;
}

int main() {
	int c_total = 0;
	int i, sum;
	int factorials[60];
	int factorials_pos;

	for (i = 0; i < SIZE; i++) {
		factorials_pos = 0;
		sum = i;
		do {
			factorials[factorials_pos++] = sum;
			sum = sum_digits_factorials(sum);
			if (factorials_pos == 60) break;
		} while (!has_factorials(factorials, factorials_pos, sum));
		if (factorials_pos == 60) {
			c_total++;
		}
	}
	printf("%d\n", c_total);
	return 0;
}
