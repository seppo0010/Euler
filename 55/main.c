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

bigint bi_revert(bigint num) {
	char *str = bi_to_str(bi_copy(num));
	int digits = strlen(str);
	if (digits < 2) { free(str); return num; }
	char *ret = malloc(sizeof(char) * digits + 1);
	int i;
	for (i=0;i<digits;++i) {
		ret[digits-i-1] = str[i];
	}
	ret[digits] = '\0';
	bigint bi = str_to_bi(ret);
	free(str);
	free(ret);
	bi_free(num);
	return bi;
}

int bi_is_palindromic(bigint num) {
	char *str = bi_to_str(bi_copy(num));
	int digits = strlen(str);
	int i;
	int ret = 1;
	for (i=0;i<digits/2;++i) {
		if (str[i] != str[digits-i-1]) { ret = 0; break; }
	}
	free(str);
	bi_free(num);
	return ret;
}

int is_palindromic(int num) {
	int digits = (int)floor(log10((double)num))+1;
	int i;
	for (i=0;i<digits/2;++i) {
		if ((int)(num / pow(10, i)) % 10 != (int)(num / pow(10, digits-i-1)) % 10) return 0;
	}
	return 1;
}

int revert(int num) {
	int digits = (int)floor(log10((double)num))+1;
	if (digits < 2) return num;
	int i;
	int r=0;
	for (i=0;i<digits;++i) {
		r += ((int)(num / pow(10, i)) % 10) * (int)pow(10, digits-i-1);
	}
	return r;
}

int main() {
	int i, j, c = 0;
	int lychrels[10001];
	for (i=1;i<=10000;++i) {
		lychrels[i] = -1;
	}

	int n;
	bi_initialize();
	bigint n2;
	for (i=10000;i>=10;--i) {
		if (lychrels[i] == -1) {
			n = i;
			for (j=0;j<50;++j) {
				if (n > 0) {
					n += revert(n);
					if (n > 100000000) {
						n2 = int_to_bi(n);
						n = 0;
						--j;
						continue;
					}
					if (n < 10000 && lychrels[n] == 0) {
						lychrels[i] = 0;
						break;
					} else if (is_palindromic(n)) {
						lychrels[i] = 0;
						break;
					}
				} else {
					n2 = bi_add(n2, bi_revert(bi_copy(n2)));
					if (bi_is_palindromic(bi_copy(n2))) {
						lychrels[i] = 0;
						bi_free(n2);
						break;
					} else if (j == 49) {
						bi_free(n2);
						break;
					}
				}
			}
			if (lychrels[i] == -1) lychrels[i] = 1;
		}
		c += lychrels[i];
#ifdef DEBUG
		printf("%d? %d\n", i, lychrels[i]);
#endif
	}
	printf("%d\n", c);
	bi_terminate();
	return 0;
}
