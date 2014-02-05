#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define SIZE 50000000

static inline int is_prime(int num) {
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
	int *results = malloc(sizeof(int) * SIZE);
	int i, j, k, n;
	int i_subtotal, j_subtotal;
	int max_i = pow(SIZE, 0.25);
	int max_j = pow(SIZE, 1.0 / 3);
	int max_k = pow(SIZE, 0.5);

	for (i = 0; i < SIZE; i++) {
		results[i] = 0;
	}

	for (i = 0; i < max_i; i++) {
		if (!is_prime(i)) continue;
		i_subtotal = i * i * i * i;
		for (j = 0; j < max_j; j++) {
			if (!is_prime(j)) continue;
			j_subtotal = j * j * j;
			for (k = 0; k < max_k; k++) {
				if (!is_prime(k)) continue;
				n = i_subtotal + j_subtotal + k * k;
				if ((int)n > SIZE) break;
				results[(int)n] += 1;
			}
		}
	}
	j = 0;
	for (i = 0; i < SIZE; i++) {
		if (results[i] != 0) {
			j++;
		}
	}
	printf("%d\n", j);
	return 0;
}
