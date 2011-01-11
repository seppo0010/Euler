#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int is_prime(unsigned long long num) {
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

unsigned long long concat(unsigned long long n1, unsigned long long n2) {
	int digits = (int)floor(log10((double)n2))+1;
	return n1 * (int)pow(10, digits) + n2;
}

int main() {
	int v, min = 0;
	unsigned long long numbers[4];
	for (numbers[0] = 11;min==0||min>numbers[0];numbers[0]+=2) {
		if (!is_prime(numbers[0])) continue;
		if (numbers[0] == 5) continue;
	for (numbers[1] = numbers[0]-2; numbers[1]>1;numbers[1]-=2) {
		if (!is_prime(numbers[1])) continue;
		if (numbers[1] == 5) continue;
		if (!is_prime(concat(numbers[0], numbers[1])) || !is_prime(concat(numbers[1], numbers[0]))) continue;
	for (numbers[2] = numbers[1]-2; numbers[2]>1;numbers[2]-=2) {
		if (!is_prime(numbers[2])) continue;
		if (numbers[2] == 5) continue;
		if (!is_prime(concat(numbers[0], numbers[2])) || !is_prime(concat(numbers[2], numbers[0]))) continue;
		if (!is_prime(concat(numbers[1], numbers[2])) || !is_prime(concat(numbers[2], numbers[1]))) continue;
	for (numbers[3] = numbers[2]-2; numbers[3]>1;numbers[3]-=2) {
		if (!is_prime(numbers[3])) continue;
		if (numbers[3] == 5) continue;
		if (!is_prime(concat(numbers[0], numbers[3])) || !is_prime(concat(numbers[3], numbers[0]))) continue;
		if (!is_prime(concat(numbers[1], numbers[3])) || !is_prime(concat(numbers[3], numbers[1]))) continue;
		if (!is_prime(concat(numbers[2], numbers[3])) || !is_prime(concat(numbers[3], numbers[2]))) continue;
	for (numbers[4] = numbers[3]-2; numbers[4]>1;numbers[4]-=2) {
		if (!is_prime(numbers[4])) continue;
		if (numbers[4] == 5) continue;
		if (!is_prime(concat(numbers[0], numbers[4])) || !is_prime(concat(numbers[4], numbers[0]))) continue;
		if (!is_prime(concat(numbers[1], numbers[4])) || !is_prime(concat(numbers[4], numbers[1]))) continue;
		if (!is_prime(concat(numbers[2], numbers[4])) || !is_prime(concat(numbers[4], numbers[2]))) continue;
		if (!is_prime(concat(numbers[3], numbers[4])) || !is_prime(concat(numbers[4], numbers[3]))) continue;
		v = numbers[0] + numbers[1] + numbers[2] + numbers[3] + numbers[4];
#ifdef DEBUG
		printf("%llu %llu %llu %llu %llu\n", numbers[0], numbers[1], numbers[2], numbers[3], numbers[4]);
		printf("%d>=%d\n", v, min);
#endif
		if (min == 0 || v < min) min = v;
		numbers[1] = numbers[2] = numbers[3] = numbers[4] = numbers[0];
		numbers[0] = min;
	}
	}
	}
	}
#ifdef DEBUG
		printf("%llu\n", numbers[0]);
#endif
	}
	printf("%d\n", min);
	return 0;
}
