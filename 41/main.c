#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <bigint.h>

int main() {
	int n;
	int a,b,c,d,e,f,g,h,i;
	int max = 9;
	bi_initialize();
	for (a=9;a>=0;--a) {
		if (a == 0) max = 8;
	for (b=max;b>=0;--b) {
		if (b==a&&b!=0) continue;
		if (b == 0)
			if (a == 0) max = 7;
			else continue;
	for (c=max;c>=0;--c) {
		if (c!=0&&(c==a||c==b)) continue;
		if (c == 0)
			if (b == 0) max = 6;
			else continue;
	for (d=max;d>=0;--d) {
		if (d!=0&&(d==a||d==b||d==c)) continue;
		if (d == 0)
			if (c == 0) max = 5;
			else continue;
	for (e=max;e>=0;--e) {
		if (e!=0&&(e==a||e==b||e==c||e==d)) continue;
		if (e == 0)
			if (d == 0) max = 4;
			else continue;
	for (f=max;f>=0;--f) {
		if (f!=0&&(f==a||f==b||f==c||f==d||f==e)) continue;
		if (f == 0)
			if (e == 0) max = 3;
			else continue;
	for (g=max;g>=0;--g) {
		if (g!=0&&(g==a||g==b||g==c||g==d||g==e||g==f)) continue;
		if (g == 0)
			if (f == 0) max = 2;
			else continue;
	for (h=max;h>=0;--h) {
		if (h!=0&&(h==a||h==b||h==c||h==d||h==e||h==f||h==g)) continue;
		if (h == 0)
			if (g == 0) max = 1;
			else continue;
	for (i=max;i>=0;i-=2) {
		if (i==a||i==b||i==c||i==d||i==e||i==f||i==g||i==h) continue;
		n = a * 100000000 +
		    b * 10000000 +
		    c * 1000000 +
		    d * 100000 +
		    e * 10000 +
		    f * 1000 +
		    g * 100 +
		    h * 10 +
		    i * 1;
#ifdef DEBUG
printf("Checking %d\n", n);
#endif
		if (bi_is_probable_prime(int_to_bi(n), 10)) {
			printf("%d\n", n);
			return 0;
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
	bi_terminate();
	return 0;
}
