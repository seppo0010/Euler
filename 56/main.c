#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <bigint.h>
#include <string.h>

char * bi_to_str(bigint num) {
	char* tmp;
	int pos = 0;
	if ( bi_compare( bi_copy( num ), bi_10 ) >= 0 ) {
		tmp = bi_to_str(bi_int_divide( bi_copy( num ), 10 ));
		pos = strlen(tmp);
		tmp = realloc(tmp, sizeof(char) * pos + 2);
	} else {
		tmp = malloc(sizeof(char) * 2);
	}
	tmp[pos] = bi_int_mod( bi_copy(num), 10 ) + '0';
	tmp[pos+1] = '\0';
	bi_free(num);
	return tmp;
}

int bi_digit_sum(bigint num) {
	char* str = bi_to_str(num);
	int i, c, sum = 0;
	c = strlen(str);
	for (i=0;i<c;++i) {
		sum += str[i] - '0';
	}
	return sum;
}

int main() {
	int a, b, v, max = 0;
	bi_initialize();
	for (a=1;a<100;++a)
	for (b=1;b<100;++b) {
		v = bi_digit_sum(bi_power(int_to_bi(a), int_to_bi(b)));
#ifdef DEBUG
		printf("sum(%d^%d)=%d\n", a, b, v);
#endif
		if (v > max) max = v;
	}
	bi_terminate();
	printf("%d\n", max);
	return 0;
}
