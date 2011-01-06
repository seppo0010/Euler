#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <bigint.h>

#define MAX_NEEDLE 1000000

int main() {
	int current, current_size;
	int cursor = 0;
	int prod = 1;
	int needle;
	int finished = 0;
	for (current=1;finished==0;current++) {
		current_size = (int)floor(log10(current)) + 1;
		for (needle = 1; needle <= MAX_NEEDLE; needle *= 10) {
			if (cursor < needle && cursor + current_size >= needle) {
				int pos = needle - cursor;
				int v = (current / (int)pow(10, current_size - pos)) % 10;
				prod *= v;
				if (needle == MAX_NEEDLE) finished=1;
				break;
			} else if (needle > cursor + current_size) {
				break;
			}
		}
		cursor += current_size;
	}
	printf("%d\n", prod);
	return 0;
}
