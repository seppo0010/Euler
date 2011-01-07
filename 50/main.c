#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <bigint.h>

#define SIZE 1000000

int is_prime(int num) {
	if (num == 1) return 0;
	if (num == 2 || num == 5 || num == 7 || num == 3) return 1;
	if ((num&1)==0) return 0;
	if (num < 11) return 0;
	if (num % 3 == 0) return 0;
	int r = sqrt(num);
	int f;
	for (f = 5; f <= r; f+=6) {
		if (num % f == 0) return 0;
		if (num % (f+2) == 0) return 0;
	}
	return 1;
}

int main() {
	int i, j;
	int max, max_count;
	int current, current_count;
	bi_initialize();
	for (i=2;i<SIZE;i+=i%2+1) {
		if (!is_prime(i)) continue;
		current = i;
		current_count = 1;
		for (j=i+1;j<SIZE;j+=j%2+1) {
			if (is_prime(j)) {
				current_count++;
				current += j;
				if (current > SIZE) break;
				if (is_prime(current) && current_count >= max_count) {
					max = current;
					max_count = current_count;
				}
			}
		}
	}
	bi_terminate();
	printf("%d\n", max);
	return 0;
}
