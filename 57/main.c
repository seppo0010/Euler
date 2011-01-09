#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <bigint.h>
#include <string.h>

#define DEBUG

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

int main() {
	int i;
	int c = 0;
	bi_initialize();
	bigint num=int_to_bi(1), den=int_to_bi(1);
	bigint new_den, new_num;
	for (i=0;i<1000;++i) {
		new_den = bi_add(bi_copy(den), num);
		new_num = bi_add(bi_copy(new_den), den);
		den = new_den;
		num = new_num;

		if (strlen(bi_to_str(bi_copy(den))) < strlen(bi_to_str(bi_copy(num)))) ++c;
#ifdef DEBUG
		//printf("%llu/%llu -> %d/%d -> %d\n", num, den, (int)floor(log10(num)), (int)floor(log10(den)), c);
#endif
	}

	bi_free(den);
	bi_free(num);
	bi_terminate();
	printf("%d\n", c);
	return 0;
}
