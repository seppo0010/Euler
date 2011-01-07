#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <bigint.h>

#define TARGET 8

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

int primes_in_permutations(int num, int pos) {
	int i, j, c = 0;
	int base = num;
	int start=0;
	int size = (int)ceil(log10(num));
	for (i=size;i>=0;--i) {
		if (((int)pow(2,i) & pos) > 0) {
			base -= ((num / (int)pow(10, i+1)) % 10) * (int)pow(10, i+1);
			if (i+2 == size) ++start;
		}
	}

	int v;
	
	for (j=start;j<10;++j) {
		v = base;
		for (i=size;i>=0;--i) {
			if (((int)pow(2,i) & pos) > 0) {
				v += j * (int)pow(10, i+1);
			}
		}
		if (is_prime(v)) ++c;
		if (c+9-j<TARGET) return 0;
	}
	if (c>=TARGET) {
		for (j=start;j<10;++j) {
			v = base;
			for (i=size;i>=0;--i) {
				if (((int)pow(2,i) & pos) > 0) {
					v += j * (int)pow(10, i+1);
				}
			}
			if (is_prime(v)) {
				printf("%d\n", v);
				break;
			}
		}
		return 1;
	}
	return 0;
}

int main() {
	int i, j;
	int size;
	for (i=11;;++i) {
		size = (int)floor(log10(i)) + 1;
		for (j=pow(2, size - 1)*2-1; j > 0; --j) {
			if (primes_in_permutations(10*i+3, j)) {
				return 0;
			}
		}
#ifdef DEBUG
	if (i % 1000 == 0) printf("%d\n", i);
#endif
	}
	return 0;
}
