#include <stdio.h>

int factorial(int n) {
	if (n < 2) return 1;
	return n * factorial(n-1);
}

int main() {
	char number[11] = "0123456789";
	int i, j, k;
	int combinations = 0;
	for (i=0;i<10;++i) {
		int posibilities = factorial(9 - i);
		for (j=0;j<10-i;++j) {
			if (combinations + posibilities >= 1000000) {
				char current_char = number[j+i];
				for (k=j+i;k>=i;--k) {
					number[k] = number[k-1];
				}
				number[i] = current_char;
				break;
			}
			combinations += posibilities;
		}
	}
	printf("%s\n", number);
}
