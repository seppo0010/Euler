#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_int(double num) {
	int n = (int)floor(num);
	return (n-num)*(n-num) < 0.000000000001;
}

int is_pentagonal(int n) {
	return is_int((0.5+sqrt(0.25+6*(double)n)) / 3);
}

int is_triangle(int n) {
	return is_int(sqrt(0.25+(double)n*2)+0.5);
}

int main() {
	int i, vi;
	for (i=144;;++i) {
		vi = 2*i*i-i;
		if (is_pentagonal(vi) && is_triangle(vi)) {
			printf("%d\n", vi);
			return 0;
		}
	}
	return 0;
}
