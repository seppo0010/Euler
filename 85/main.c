#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <sys/stat.h>

#define TARGET 2000000
#define SQRT_TARGET 1415

int main() {
	int i, j, v, max_v = 0, area;
	int sums[SQRT_TARGET];
	sums[0] = 0;
	for (i = 1; i < SQRT_TARGET; i++) {
		sums[i] = sums[i - 1] + i;
	}

	for (i = 1; i < SQRT_TARGET; i++) {
		for (j = 1; j < SQRT_TARGET; j++) {
			v = sums[i] * sums[j];
			if (v > TARGET) {
				break;
			}
			if (v > max_v) {
				max_v = v;
				area = i * j;
			}
		}
	}
	printf("%d\n", area);
	return 0;
}
