#include <stdio.h>

int main() {
	unsigned long long num = 600851475143;
	unsigned long long max = 0;
	printf("%d\n", is_prime(num, &max));
	printf("%llu\n", max);
}

int is_prime(unsigned long long num, unsigned long long* max) {
	if (num == 0) return 1;
	if (num == 1) return 0;
	if (num == 2) return 1;
	if (num != 2 && num % 2 == 0) return 0;
	unsigned long long num2, num3;
	for (num3 = 2; num3 < num / 2; ++num3) {
		num2 = num / num3;
		if (num % num2 == 0) {
			if (is_prime(num2, max)) {
				if (num2 > *max) *max = num2;
				return 0;
			}
		}
	}
	return 1;
}
