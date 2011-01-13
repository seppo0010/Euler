#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int is_int(double num) {
        int n = (int)floor(num);
        return (n-num)*(n-num) < 0.000000000001;
}

int is_pentagonal(int n) {
        return is_int((0.5+sqrt(0.25+6*(double)n)) / 3);
}

int is_triangle(int n) {
        return is_int(sqrt(0.25+(double)n*2)+0.5);
}

int is_square(int n) {
        return is_int(sqrt(n));
}

int is_hexagonal(int n) {
	return is_int(sqrt((double)n*8+1));
}

int is_heptagonal(int n) {
	return is_int((3.0/2+sqrt(9.0/4+n*10))/5) || is_int((3.0/2-sqrt(9.0/4+n*10))/5);
}

int is_octogonal(int n) {
	return is_int((2.0+sqrt(4.0+12*n))/6) || is_int((2.0-sqrt(4.0+12*n))/6);
}

int concat(int n1, int n2) {
	return n1 * 100 + n2;
}

#define START 10
int main() {
	int num[6];
	for (num[0]=START;num[0]<100;num[0]++)
	for (num[1]=START;num[1]<100;num[1]++) {
		if (!is_octogonal(concat(num[0], num[1]))) continue;
	for (num[2]=START;num[2]<100;num[2]++) {
		if (!is_hexagonal(concat(num[1], num[2]))) continue;
	for (num[3]=START;num[3]<100;num[3]++) {
		if (!is_pentagonal(concat(num[2], num[3]))) continue;
	for (num[4]=START;num[4]<100;num[4]++) {
		if (!is_triangle(concat(num[3], num[4]))) continue;
	for (num[5]=START;num[5]<100;num[5]++) {
		if (!is_square(concat(num[4], num[5]))) continue;
		if (!is_heptagonal(concat(num[5], num[0]))) continue;
		printf("%d\n", num[0] * 101 + num[1] * 101 + num[2] * 101 + num[3] * 101 + num[4] * 101 + num[5] * 101);
	}
	}
	}
	}
	}
	return 0;
}
