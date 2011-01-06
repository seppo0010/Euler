#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <bigint.h>

int main() {
	bi_initialize();
	bigint sum = int_to_bi(0);
	int a,b,c,d,e,f,g,h,i,j;
	int n;
	for (a=9;a>0;--a) {
	for (b=9;b>=0;--b) {
		if (b==a) continue;
	for (c=9;c>=0;--c) {
		if (c==a||c==b) continue;
	for (d=9;d>=0;--d) {
		if (d==a||d==b||d==c) continue;
	for (e=9;e>=0;--e) {
		if (e==a||e==b||e==c||e==d) continue;
	for (f=9;f>=0;--f) {
		if (f==a||f==b||f==c||f==d||f==e) continue;
	for (g=9;g>=0;--g) {
		if (g==a||g==b||g==c||g==d||g==e||g==f) continue;
	for (h=9;h>=0;--h) {
		if (h==a||h==b||h==c||h==d||h==e||h==f||h==g) continue;
	for (i=9;i>=0;--i) {
		if (i==a||i==b||i==c||i==d||i==e||i==f||i==g||i==h) continue;
	for (j=9;j>=0;--j) {
		if (j==a||j==b||j==c||j==d||j==e||j==f||j==g||j==h||j==i) continue;
		if ((b * 100 + c * 10 + d) % 2 == 0)
		if ((c * 100 + d * 10 + e) % 3 == 0)
		if ((d * 100 + e * 10 + f) % 5 == 0)
		if ((e * 100 + f * 10 + g) % 7 == 0)
		if ((f * 100 + g * 10 + h) % 11 == 0)
		if ((g * 100 + h * 10 + i) % 13 == 0)
		if ((h * 100 + i * 10 + j) % 17 == 0) {
			n = 
			    b * 100000000 +
			    c * 10000000 +
			    d * 1000000 +
			    e * 100000 +
			    f * 10000 +
			    g * 1000 +
			    h * 100 +
			    i * 10 +
			    j * 1;
			sum = bi_add(sum, int_to_bi(n));
			sum = bi_add(sum, bi_int_multiply(int_to_bi(1000000000), a));
#ifdef DEBUG
printf("%d%d%d%d%d%d%d%d%d%d\n", a,b,c,d,e,f,g,h,i,j);
bi_print(stdout,bi_copy(sum));
printf("\n");
#endif
		}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	bi_print(stdout,sum);
	printf("\n");
	bi_terminate();
	return 0;
}
