#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define SIZE 3205

int main() {
	int i;
	char text[SIZE];
	char str[SIZE];
	FILE* file = fopen("cipher1.txt", "r");
	fgets(str, SIZE+1, file);
	fclose(file);

	char current[4];
	int current_pos = 0, pos = 0;
	for (i=0; i < SIZE+1; ++i) {
		if (str[i] == ',' || i == SIZE) {
			current[current_pos] = '\0';
			text[pos++] = atoi(current);
			current_pos = 0;
		} else {
			current[current_pos++] = str[i];
		}
	}
	text[pos] = '\0';

	int j,k,l;
	int val[3];
	int valid;
	for (j=97;j<=122;j++) {
		val[0] = j;
	for (k=97;k<=122;k++) {
		val[1] = k;
	for (l=97;l<=122;l++) {
		val[2] = l;
		valid = 1;
		for (i=0; i < pos; ++i) {
			int v = text[i] ^ val[i%3];
			if (v == ' ' || (v >= 'a' && v <= 'z') || (v >= 'A' && v <= 'Z') || v == ')' || v == '(' || (v >= '0' && v <= '9') || v == '.' || v == ',' || v == '\'' || v == '!' || v == ';') {
				continue;
			} else {
				valid = 0;
				break;
			}
		}
#ifdef DEBUG
		if (valid == 1) {
			printf("%c%c%c\n", j, k, l);
			for (i=0; i < pos; ++i) {
				int v = text[i] ^ val[i%3];
				printf("%c", v);
			}
		}
#endif
		if (valid == 1) {
			int sum = 0;
			for (i=0; i < pos; ++i) {
				sum += text[i] ^ val[i%3];
			}
			printf("%d\n", sum);
			j=k=l=123;
		}
	}
	}
	}
	return 0;
}
