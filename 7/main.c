#include <stdio.h>

int main() {
	int counter = 1;
	unsigned long long num;
	for (num = 3; counter < 10001/**/; num+=2) {
		if (is_prime(num)) ++counter;
	}
	printf("%llu\n", num-2);
}

int is_prime(int num) {
	if (num == 0) return 1;
	if (num == 1) return 0;
	if (num == 2) return 1;
	if (num != 2 && num % 2 == 0) return 0;
	int num2, num3;
	for (num3 = 2; num3 < num / 2; ++num3) {
		num2 = num / num3;
		if (num % num2 == 0) {
			if (is_prime(num2)) {
				return 0;
			}
		}
	}
	return 1;
}
