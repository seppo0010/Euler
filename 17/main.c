#include <stdio.h>

int letters_in_number(int num) { //1<=num<=1000
	if (num == 0) return 0;
	if (num == 1) return 3;
	if (num == 2) return 3;
	if (num == 3) return 5;
	if (num == 4) return 4;
	if (num == 5) return 4;
	if (num == 6) return 3;
	if (num == 7) return 5;
	if (num == 8) return 5;
	if (num == 9) return 4;
	if (num == 10) return 3;
	if (num == 11) return 6;
	if (num == 12) return 6;
	if (num == 13) return 8;
	if (num == 14) return 8;
	if (num == 15) return 7;
	if (num == 16) return 7;
	if (num == 17) return 9;
	if (num == 18) return 8;
	if (num == 19) return 8;
	if (num == 20) return 6;
	if (num == 30) return 6;
	if (num == 40) return 5;
	if (num == 50) return 5;
	if (num == 60) return 5;
	if (num == 70) return 7;
	if (num == 80) return 7;
	if (num == 90) return 6;
	if (num == 1000) return 11;

	int size = 0;
	if (num > 99) {
		size += 7 + letters_in_number(num / 100);
		if (num % 100 != 0) size += 3;
	}
	// > 19
	if (num % 100 < 20) {
		size += letters_in_number(num % 100);
	} else {
		size += letters_in_number(((num / 10) % 10) * 10);
		size += letters_in_number(num % 10);
	}
	return size;
}

int main() {
	unsigned long long total = 0;
	int i;
	for (i=1;i<=1000;++i) total += letters_in_number(i);
	printf("%llu\n", total);
}
