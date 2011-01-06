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

int num_divisors(unsigned long long num) {
	if (num == 1) return 1;
	if (is_prime(num)) return 2;

	int r = sqrt(num);
	int c = 2;
	int i;
	for (i = 2; i < num; ++i) {
		if (num % i == 0) ++c;
	}
	return c;
}

int main() {
	unsigned long long num;
	unsigned long long i;
	for (i = 0;;++i) {
		num = (i * (i+1)) / 2;
		int c = num_divisors(num);
		if (c > 500) break;
	}
	printf("%llu\n", num);
}
