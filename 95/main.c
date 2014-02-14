#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000000
#define MIN(a,b) (a<b?a:b)

int sum_of_divisors(int num) {
	int i, value = 0;
	for (i = 1; i <= num / 2; i++) {
		if (num % i == 0) {
			value += i;
		}
	}
	return value;
}

int main() {
	short chain[SIZE];
	int used[SIZE];
	int used_length = 0, i, j, v, length, max_length, max_length_member;
	for (i = 0; i < SIZE; i++) {
		chain[i] = 0;
	}

	for (i = 1; i < SIZE; i++) {
		for (j = 0; j < used_length; j++) {
			//chain[used[j]] = 0;
		}
		used_length = 0;

		v = i;
		while (chain[v] == 0) {
			chain[v] = 1;
			used[used_length++] = v;
			v = sum_of_divisors(v);
			if (v > SIZE) {
				used_length = 0;
				break;
			}
		}
		for (j = 0; j < used_length; j++) {
			if (used[j] == v) {
				length = used_length - j;
				if (length > max_length) {
					max_length = length;
					max_length_member = used[j];
					for (j = j + 1;j < used_length; j++) {
						max_length_member = MIN(max_length_member, used[j]);
					}
				}
				break;
			}
		}
	}
	printf("%d %d\n", max_length_member, max_length);
}
