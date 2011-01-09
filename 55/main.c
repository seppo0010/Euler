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
	tmp[pos] = bi_int_mod( num, 10 ) + '0';
	tmp[pos+1] = '\0';
	return tmp;
}

bigint bi_revert(bigint num) {
}
int bi_is_palindromic(bigint num) {
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
	for (i=9999;i>=1;--i) {
		if (lychrels[i] == 0) continue;
		else if (lychrels[i] == 1) {
			++c;
			continue;
		} else {
			n = i;
			for (j=0;j<50;++j) {
				if (n > 0) {
					n += revert(n);
					if (n > 100000000) {
						n2 = int_to_bi(n);
						--j;
						continue;
					}
					if (n < 10000 && lychrels[n] >= 0) {
						c += lychrels[n];
						break;
					} else if (is_palindromic(n)) {
						++c;
						lychrels[i] = 1;
						break;
					}
				} else {
					n2 = bi_add(n2, bi_revert(n2));
					if (bi_is_palindromic(n2)) {
						++c;
						lychrels[i] = 1;
						bi_free(n2);
						break;
					} else if (j == 49) {
						bi_free(n2);
						break;
					}
				}
			}
			if (lychrels[i] == -1) lychrels[i] = 0;
		}
	}
	printf("%d\n", c);
	bi_terminate();
	return 0;
}
