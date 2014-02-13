#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 0->0
// 1->1
// 2->2
// 3->3
// 4->2
// 5->1
// 6->2
// 7->3
// 8->4
// 9->2

int num_roman(int value) {
	char str[5];
	sprintf(str, "%d", value % 1000);
	int i, v = value / 1000;
	for (i = 0;;i++) {
		if (str[i] == '\0') break;
		if (str[i] == '1' || str[i] == '5') v += 1;
		else if (str[i] == '2' || str[i] == '4' || str[i] == '6' || str[i] == '9') v += 2;
		else if (str[i] == '3' || str[i] == '7') v += 3;
		else if (str[i] == '8') v += 4;
	}
	return v;
}

int get_value(char c) {
	int v = 0;
	switch(c) {
		case 'M':
			v = 1000;
			break;
		case 'D':
			v = 500;
			break;
		case 'C':
			v = 100;
			break;
		case 'L':
			v = 50;
			break;
		case 'X':
			v = 10;
			break;
		case 'V':
			v = 5;
			break;
		case 'I':
			v = 1;
			break;
	}
	return v;
}

int get_number(char* string) {
	int j, v, i, c = strlen(string);
	int buffer = 0;
	for (i = 0; i < c; i++) {
		v = get_value(string[i]);
		int add = 1;
		for (j = i + 1; j < c; j++) {
			if (v < get_value(string[j])) {
				add = 0;
				break;
			}
		}
		if (add) {
			buffer += v;
		} else {
			buffer -= v;
		}
	}
	return buffer;
}

int main() {
	FILE* file = fopen("roman.txt", "r");
	char string[20];
	char *row;
	int i, c, v;
	int total = 0;
	while ((row = fgets(string, 20, file)) != NULL) {
		c = 0;
		for (i = 0; i < strlen(string); i++) {
			if (string[i] >= 'A' && string[i] <= 'Z') c++;
			else break;
		}
		v = get_number(row);
		total += c - num_roman(v);
	};
	printf("%d\n", total);
	return 0;
}
