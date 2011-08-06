#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define SIZE 1000000
//#define SIZE 8

#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)

static inline int is_prime(int num) {
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

int gcd(int num1, int num2) {
	int remainder = num1 % num2;
	if (remainder == 0) return num2;
	return gcd(MAX(num2, remainder), MIN(num2, remainder));
}

int are_coprime(int num1, int num2) {
	return gcd(num1, num2) == 1;
}

int main() {
	int i, j, p=0;
	double target = 3.0 / 7.0;
	double value;
	double parcial = 0.0;
	int parcial_num = 0;
	for (i = 8; i <= SIZE; i++) {
		for (j = p; j < i; j++) {
			value = (double) j / i;
			if (value < target) {
				p++;
				if (value > parcial) {
					if (!are_coprime(i,j)) continue;
					parcial = value;
					parcial_num = j;
				}
			} else {
				break;
			}
		}
	}
	printf("%d\n", parcial_num);
	return 0;
}
