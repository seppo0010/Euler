#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 6

int is_permutation(int n1, int n2) {
	int digits = 1+(int)floor(log10((double)n1));
	if (1+(int)floor(log10((double)n2)) != digits) return 0;

	int values[10];
	int i;
	for (i=0;i<10;++i) values[i] = 0;

	for (i=0;i<digits;++i) {
		++values[(n1/(int)pow(10, i))%10];
	}
	for (i=0;i<digits;++i) {
		if (--values[(n2/(int)pow(10, i))%10] < 0) return 0;
	}
	return 1;
}

int main() {
	int i, j;
	for (i=1;;++i) {
		for (j=2;j<=MAX;++j) {
			if (!is_permutation(i, i*j)) break;
			if (j == MAX) {
				printf("%d\n", i);
				return 0;
			}
		}
#ifdef DEBUG
	if (i % 1000 == 0) printf("%d\n", i);
#endif
	}
	return 0;
}
