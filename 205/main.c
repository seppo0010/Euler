#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NUMBER 1000000000

int main() {
	int i, j, k, l, m, n, o, q, r, p[37], c[37], p_total = 0, c_total = 0;
	for (i = 0; i < 37; i++) {
		p[i] = 0;
		c[i] = 0;
	}

	for (i = 1; i <= 4; i++)
	for (j = 1; j <= 4; j++)
	for (k = 1; k <= 4; k++)
	for (l = 1; l <= 4; l++)
	for (m = 1; m <= 4; m++)
	for (n = 1; n <= 4; n++)
	for (o = 1; o <= 4; o++)
	for (q = 1; q <= 4; q++)
	for (r = 1; r <= 4; r++) {
		p[i + j + k + l + m + n + o + q + r]++;
		p_total++;
	}

	for (i = 1; i <= 6; i++)
	for (j = 1; j <= 6; j++)
	for (k = 1; k <= 6; k++)
	for (l = 1; l <= 6; l++)
	for (m = 1; m <= 6; m++)
	for (n = 1; n <= 6; n++) {
		c[i + j + k + l + m + n]++;
		c_total++;
	}

	unsigned long long pr = 0;
	for (i = 1; i <= 36; i++)
	for (j = i - 1; j > 0; j--) {
		pr += p[i] * c[j];
	}

	pr = 100000000 * pr / p_total / c_total;
	printf("0.%lld", pr / 100);
	printf("%lld\n", (pr % 100 / 10) + (pr % 10 >= 5 ? 1 : 0));
	return 0;
}
