#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <bigint.h>


int main() {
	bi_initialize();
	int i;
	bigint v = int_to_bi(0);
	for (i=1;i<=1000;++i) {
		v = bi_add(v, bi_power(int_to_bi(i), int_to_bi(i)));
	}
	bi_print(stdout, v);
	printf("\n");
	bi_terminate();
	return 0;
}
