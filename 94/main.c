#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//#include <bigint.h>

#define MAX_PERIMETER 1000000000

#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)

int gcd(long long num1, long long num2) {
	long long remainder = num1 % num2;
	if (remainder == 0) return num2;
	return gcd(MAX(num2, remainder), MIN(num2, remainder));
}

int are_coprime(long long num1, long long num2) {
	return gcd(num1, num2) == 1;
}

int main() {
	long long u, v, divisor, a, b, c = 0;
	for (u = 1;u < MAX_PERIMETER;u++) {
		for (v = 1; v < u; v++) {
			if (!are_coprime(u, v)) continue;
			a = 2 * (u * u - v * v);
			b = u * u + v * v;
			if (b + b + a > MAX_PERIMETER) {
				v = u = MAX_PERIMETER;
				break;
			}
			divisor = abs(b - a);
			if (b % divisor == 0 && a % divisor == 0) {
				c += (b + b + a) / divisor;
			}
		}
	}
	printf("%lld\n", c);
	return 0;
}
