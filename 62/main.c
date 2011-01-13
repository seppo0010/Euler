#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int is_permutation(unsigned long long num1, unsigned long long num2) {
	int digits[10];
	int i;
	for (i=0;i<10;++i) digits[i]=0;
	int size = (int)floor(log10(num1))+1;
	for (i=0;i<size;++i) digits[(unsigned long long)(num1/pow(10,i)) % 10]++;
	for (i=0;i<size;++i) if (--digits[(unsigned long long)(num2/pow(10,i)) % 10] < 0) return 0;
	return 1;
}

#define TARGET 4
#define MAX 20000

int main() {
	int i, j, digits, predigits;
	unsigned long long v;
	unsigned long long found[MAX];
	int used = 0, finished = 0;
	int c;
	for (i=345;finished==0;++i) {
		v = (unsigned long long)pow(i,3);
		digits = (int)floor(log10(v)) + 1;
		if (digits != predigits) used = 0;

		if (used >= TARGET) {
			c = 0;
			for (j=0;j<used;j++) {
				c += is_permutation(v, found[j]);
			}
			if (c >= TARGET) {
				for (j=0;j<used;j++) {
					if (is_permutation(v, found[j])) {
						printf("%llu\n", found[j]);
						break;
					}
				}
				break;
			}
		}
		if (used == MAX) {
			printf("Hitted max size\n");
			return 1;
		}
		found[used++] = v;

		predigits = digits;
	}
	return 0;
}
