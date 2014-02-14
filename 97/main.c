#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int i;
	long long v = 1;
	for (i = 0; i < 7830457; i++) {
		v *= 2;
		v %= 10000000000;
	}
	v *= 28433;
	v += 1;
	v %= 10000000000;
	printf("%lld\n", v);
	return 0;
}
