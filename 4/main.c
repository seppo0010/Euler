#include <stdio.h>

int main() {
	int num1;
	int result = 0;
	for (num1 = 999; result < num1 * 999; num1--) {
		int num2 = 999;

		do {
			int tmp_result = num1 * num2;
			if (tmp_result < result) break;
			if (is_palindromic(tmp_result)) {
				result = tmp_result;
				break;
			}
			num2--;
		} while (1);
	}
	printf("Largest is %d\n", result);
}

int is_palindromic(int num) {
	if (num % 11 != 0) return 0;
	char string[7];
	int chars = sprintf(string, "%d", num);
	int i;
	for (i = 0; i < chars/2; i++) {
		if (string[i] != string[chars-1-i]) return 0;
	}
	return 1;
}
