#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define SIZE 1000000

int is_prime(int num) {
	if (num == 1) return 0;
	if (num == 2 || num == 5 || num == 7 || num == 3) return 1;
	if ((num&1)==0) return 0;
	if (num < 11) return 0;
	if (num % 3 == 0) return 0;
	int r = sqrt(num);
	int f;
	for (f = 5; f <= r; f+=6) {
		if (num % f == 0) return 0;
		if (num % (f+2) == 0) return 0;
	}
	return 1;
}

int main() {
	int new_n, n = 2, i;
	for (i=3;;i+=2) {
		if (is_prime(i)) {
			new_n = n * i;
			if (new_n > SIZE) break;
			n = new_n;
		}
	}
	printf("%d\n", n);
	return 0;
}
