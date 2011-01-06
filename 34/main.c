int factorial(int n) {
	if (n == 0 || n == 1) return 1;
	return n * factorial(n - 1);
}

int main() {
	int a, b, c, d, e, f, g;
	int sum, total;
	for (a=0;a<10;++a)
	for (b=0;b<10;++b)
	for (c=0;c<10;++c)
	for (d=0;d<10;++d)
	for (e=0;e<10;++e)
	for (f=0;f<10;++f)
	for (g=0;g<10;++g) {
		sum = 0;
		if (a == 0) sum -= 1;
		if (a == 0 && b == 0) sum -= 1;
		if (a == 0 && b == 0 && c == 0) sum -= 1;
		if (a == 0 && b == 0 && c == 0 && d == 0) sum -= 1;
		if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0) sum -= 1;
		if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0) continue; // skipping one digit;
		sum += factorial(a) + factorial(b) + factorial(c) + factorial(d) + factorial(e) + factorial(f) + factorial(g);
		if (sum == g * 1 + f * 10 + e * 100 + d * 1000 + c * 10000 + b * 100000 + a * 1000000) {
			total += sum;
		}
	}
	printf("%d\n", total);
	return 0;
}
