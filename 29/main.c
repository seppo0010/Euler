#include <stdio.h>
#include <bigint.h>

#define SIZE 100

int main() {
	bi_initialize();
	bigint* numbers = malloc(sizeof(bigint) * 10000);
	int used = 0;
	int a, b, i;
	for (a = 2; a <= SIZE; ++a) {
		int cursor = 0;
		for (b = 2; b <= SIZE; ++b) {
			bigint value = bi_power(int_to_bi(a), int_to_bi(b));
			while (cursor < used && bi_compare(bi_copy(value), bi_copy(numbers[cursor])) > 0) {
				++cursor;
			}

			if (cursor >= used || bi_compare(bi_copy(value), bi_copy(numbers[cursor])) < 0) {
				for (i=used;i>cursor;--i) {
					numbers[i] = numbers[i-1];
				}
				numbers[cursor] = value;
				++used;
			} else {
				bi_free(value);
			}
		}
	}
	printf("%d\n", used);
	for (i=0;i<used;++i) {
		bi_free(numbers[i]);
	}
	free(numbers);
	bi_terminate();
	return 0;
}
