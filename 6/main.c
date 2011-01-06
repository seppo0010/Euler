#include <stdio.h>

int main() {
	unsigned long long total;
	unsigned long long cur;
	total = (100 * 101) / 2;
	total *= total;
	for (cur = 1; cur <= 100; ++cur) {
		total -= cur*cur;
	}
	printf("%llu\n", total);
}
