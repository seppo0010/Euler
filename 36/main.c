#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <bigint.h>

#define SIZE 1000000

int is_palindromic_b2(int num) {
	int digits = (int)floor(log2((double)num))+1;
#ifdef DEBUG
	printf("%d (%d)\n", num, digits);
#endif
	int i;
	for (i=0;i<digits/2;++i) {
#ifdef DEBUG
		printf("%d: %d != %d\n", num, (num & (int)pow(2,i)) > 0,(num & (int)pow(2,digits-i-1)) > 0);
#endif
		if ((num & (int)pow(2,i)) > 0 != (num & (int)pow(2,digits-i-1)) > 0) return 0;
	}
	return 1;
}

int is_palindromic(int num) {
	int digits = (int)ceil(log10((double)num));
	int i;
	for (i=0;i<digits/2;++i) {
		if ((int)(num / pow(10, i)) % 10 != (int)(num / pow(10, digits-i-1)) % 10) return 0;
	}
	return 1;
}

int main() {
	int i;
	unsigned long long total = 0;
	for (i=0;i<SIZE;++i) {
		if (is_palindromic_b2(i) && is_palindromic(i)) total += i;
	}
	printf("%llu\n", total);
	return 0;
}
