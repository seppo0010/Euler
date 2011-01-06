#include <stdio.h>
#define MAX 1000
#define SIZE 10000

int module(int* tmp, int i) {
	int ret = 0;
	int j;
	for (j = SIZE-1;j>=0;--j) {
		ret = (tmp[j] + ret*10) % i;
	}
	return ret;
}

int p(int* n) {
	int printing = 0;
	int j;
	for (j = SIZE-1;j>=0;--j) {
		if (printing > 0 || n[j] > 0) {
			printing = 1;
			printf("%d", n[j]);
		}
	}
}

int main() {
	int i, j, k=0, digits;
	unsigned long long longer = 0, longer_count = 0;
	for (i=1;i<MAX;++i) {
		// 1, 9, 10, 90, 99, 100, 900, 990, 999, 1000, 9000, 9900, 9990, 9999, 10000
		int found = 0;
		for (digits=0;found==0;++digits) {
			for (j=0;j<digits+2;++j) {
				int tmp[SIZE];
				for (k=0;k<SIZE;++k) tmp[k] = 0;
				
				if (j==0) tmp[digits] = 1;
				else {
					for (k=1;k<=digits-j+2;++k) {
						tmp[digits-k+1] = 9;
					}
				}

				
//p(tmp);
//printf("mod %d=%d\n",i, module(tmp, i));
				if (module(tmp, i) == 0) {
//printf("%d\n",i);

					int periodic_digits = digits+2-j;
					if (periodic_digits > longer_count) {
						longer_count = periodic_digits;
						longer = i;
					}
//printf("%d %d\n", i, periodic_digits);
//printf("Longer: %llu\n", longer);
					found = 1;
					break;
				}
			}
		}
	}
	printf("%llu\n", longer);
}
