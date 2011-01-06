#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_int(double num) {
	int n = (int)floor(num);
	return (n-num)*(n-num) < 0.000000001;
}

int is_pentagonal(int n) {
	return is_int((0.5+sqrt(0.25+6*(double)n)) / 3);
}

int main() {
	int i, j;
	int vi, vj;
	for (i=2;;++i)
	for (j=1;j<i;++j) {
		vi = (i * (3*i-1)) / 2;
		vj = (j * (3*j-1)) / 2;
		if (is_pentagonal(vi+vj) && is_pentagonal(vi-vj)) {
			printf("%d\n", vi-vj);
			return 0;
		}
	}
	return 0;
}
