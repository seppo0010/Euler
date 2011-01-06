#include <stdio.h>

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
/*
int is_prime(int num) {
	if (num == 0) return 1;
	if (num == 1) return 0;
	if (num == 2) return 1;
	if (num != 2 && num % 2 == 0) return 0;
	int num2, num3;
	for (num3 = 2; num3 < num / 2; ++num3) {
		num2 = num / num3;
		if (num % num2 == 0) {
			return 0;
		}
	}
	return 1;
}
*/
int main() {
	int i;
	unsigned long long total = 0;
	for (i = 2; i < 2000000; ++i) {
		if (is_prime(i)) {
			total+=i;
		}
	}
	printf("%llu\n", total);
}
