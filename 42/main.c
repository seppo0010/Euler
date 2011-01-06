#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 16345

int main() {
	char str[SIZE];
	FILE* file = fopen("words.txt", "r");
	fgets(str, SIZE+1, file);
	fclose(file);

	int c = 0;
	int i, v = 0;
	double tmp;
	for (i=0; i < SIZE+1; ++i) {
		if (str[i] == '"') {
			continue;
		} else if (str[i] == ',' || str[i] == 0) {
			tmp = sqrt(0.25+(double)v*2)+0.5;
			tmp = tmp - round(tmp);
			if (tmp*tmp < 0.000000001) {
				c++;
			}
			v = 0;
		} else {
			v += str[i] - 64;
		}
	}

	printf("%d\n", c);
	return 0;
}
