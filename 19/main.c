#include <stdio.h>

int main() {
	int day = 7;
	int month = 1;
	int year = 1900;

	unsigned long long count = 0;
	do {
		day += 7;
		int dim = days_in_month(month, year);
		while (dim < day) {
			day -= dim;
			month++;
		}

		if (day == 1 && year > 1900) {
			++count;
		}

		while (month > 12) {
			month -= 12;
			year += 1;
		}
	} while (year < 2001);

	printf("%llu\n", count);
}

int days_in_month(int month, int year) {
	if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
	if (month == 2) {
		if (year % 100 != 0 && year % 4 == 0) return 29;
		if (year % 400 == 0) return 29;
		return 28;
	}
	return 31;
}
