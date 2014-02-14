#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
	FILE* file = fopen("base_exp.txt", "r");
	int base, exp;
	int line = 1, max_line = -1;
	double value, max_value;
	while (fscanf(file, "%d,%d\n", &base, &exp) == 2) {
		value = exp * log(base);
		if (max_line == -1 || value > max_value) {
			max_value = value;
			max_line = line;
		}
		line++;
	}
	printf("%d\n", max_line);
	return 0;
}
