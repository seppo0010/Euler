#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <bigint.h>

int main() {
	int i, j, prod;
	unsigned long long num, max_num = 0;
	int a,b,c,d,e,f,g,h,z;
	for (i = 1; i < 987654321; ++i) {
		num = 0;
		for (j=1;;++j) {
			prod = i * j;
			if (num > 0) {
				num = num * (int)pow(10, (int)floor(log10(prod)) + 1);
			}
			num += prod;

			if (num > 987654321 && j <= 2) { // All future numbers will exceed the maximum value
				i = 987654321;
				break;
			}
			if (num > 987654321) break;

			if (num >= 123456789 && num > max_num) {
				a = (num / 100000000) % 10;
				b = (num / 10000000) % 10;
				c = (num / 1000000) % 10;
				d = (num / 100000) % 10;
				e = (num / 10000) % 10;
				f = (num / 1000) % 10;
				g = (num / 100) % 10;
				h = (num / 10) % 10;
				z = (num / 1) % 10;
				if (
					a+b+c+d+e+f+g+h+z == 45 && a*b*c*d*e*f*g*h*z == 362880 &&
					a != b && a != c && a != d && a != e && a != f && a != g && a != h && a != z &&
					b != c && b != d && b != e && b != f && b != g && b != h && b != z &&
					c != d && c != e && c != f && c != g && c != h && c != z &&
					d != e && d != f && d != g && d != h && d != z &&
					e != f && e != g && e != h && e != z &&
					f != g && f != h && f != z &&
					g != h && g != z &&
					h != z
				) {
					max_num = num;
				}
			}
		}
	}
	printf("%llu\n", max_num);
	return 0;
}
