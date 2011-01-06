#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <bigint.h>

int main() {
	int max = 0;
	int max_value = 0;
	int i, j, k;
	double sq;
	int options;
	for (i=3;i<=1000;++i) {
		options = 0;
		for (j=1;j<=i;j++) {
			for (k=1;k<=j;k++) {
				sq = sqrt(j*j+k*k);
				if ((round(sq) - sq) * (round(sq) - sq) < 0.0000000000001 && i == j + k + (int)sq) { // is there a better way to know if it's an integer?
					++options;
				}
			}
		}
		if (options > max_value) {
			max_value = options;
			max = i;
		}
	}
	printf("%d\n", max);
	return 0;
}
