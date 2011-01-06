#include <time.h>
#include <stdio.h>

int main() {
	clock_t start = clock();
	int prev = 1, cur = 1, total = 0;
	int new;

	while (cur < 4000000) {
		new = prev + cur;
		prev = cur;
		cur = new;
		if ((cur & 1) == 0) {
			total += cur;
		}
	}
	printf("%d\n", total);
	printf("Time elapsed: %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);
}
