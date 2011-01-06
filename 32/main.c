#include <stdio.h>

int main() {
	int a, b, c, d, e;
	int f, g, h, i, j;
	int n1, n2, n3;
	unsigned long long sum = 0;
	int* results = malloc(sizeof(int) * 1000);
	int result_size = 0;
	int k;
	for (a=1;a<10;++a)
	for (b=1;b<10;++b)
	for (c=1;c<10;++c)
	for (d=1;d<10;++d)
	for (e=1;e<10;++e) {
		for (j=0;j<2;++j) {
			if (j == 0) {
				n1 = a;
				n2 = b * 1000 + c * 100 + d * 10 + e * 1;
			} else {
				n1 = a * 10 +b;
				n2 = c * 100 + d * 10 + e * 1;
			}
			n3 = n1 * n2;
			if (n3 > 999 && n3 < 10000) {
				f = n3 / 1000;
				g = (n3 / 100) % 10;
				h = (n3 / 10) % 10;
				i = (n3 / 1) % 10;
				if (
				a+b+c+d+e+f+g+h+i == 45 && a*b*c*d*e*f*g*h*i == 362880 &&
				a != b && a != c && a != d && a != e && a != f && a != g && a != h && a != i &&
				b != c && b != d && b != e && b != f && b != g && b != h && b != i &&
				c != d && c != e && c != f && c != g && c != h && c != i &&
				d != e && d != f && d != g && d != h && d != i &&
				e != f && e != g && e != h && e != i &&
				f != g && f != h && f != i &&
				g != h && g != i &&
				h != i
				) {
					for (k=0;k<result_size;++k) {
						if (results[k] == n3) {
							sum -= n3;
							break;
						}
					}
					sum += n3;
					results[result_size++] = n3;
				}
			}
		}
	}
	printf("%llu\n", sum);
	return 0;
}
