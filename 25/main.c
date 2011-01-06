#include <stdio.h>

#define SIZE 1001

void add(int* val, int* add_val) {
	int i;
	int extra = 0;
	for (i = SIZE-1; i >= 0;--i) {
		val[i] += add_val[i];
		val[i] += extra;
		if (val[i] >= 10) {
			int new_value = val[i] % 10;
			extra = val[i] / 10;
			val[i] = new_value;
		} else {
			extra = 0;
		}
	}
}

int main() {
	int i;
	int* number1 = malloc(sizeof(int) * SIZE);
	for (i=0;i<SIZE;++i) number1[i] = 0;
	int* number2 = malloc(sizeof(int) * SIZE);
	for (i=0;i<SIZE;++i) number2[i] = 0;

	number1[SIZE-1] = 1;
	number2[SIZE-1] = 2;

	unsigned long long c;
	for (c=4;;c++) {
		add(number1, number2);
		int* tmp = number2;
		number2 = number1;
		number1 = tmp;
		int should_break = 0;
		for (i=0;i<SIZE-999;++i) {
			if (number2[i] > 0) {
				should_break = 1;
				break;
			}
		}
		if (should_break) break;
	}
	//for (i=0;i<SIZE;++i) printf("%d",number2[i]);
	//printf("\n");

	printf("%llu\n",c);
}
