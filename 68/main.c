#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
	int n[10];
	int i;
	for (i=0;i<10;i++)
		n[i] = 9-i;

	char str[18];
	while (1) {
		if (n[2] == 0 || n[4] == 0 || n[6] == 0) continue;
		for (i=0;i<18;i++) {
			str[i] = 0;
		}

		int pos = 0;
		for (i=0;i<11;i++) {
			if (i == 10) {
				str[pos] = '0' + n[1];
				break;
			}
			str[pos] = '0' + n[i];
			if (str[pos] == '0') {
				str[pos] = '1';
				++pos;
				str[pos] = '0';
			}
			if (i == 3 || i == 5 || i == 7 || i == 9) {
				++pos;
				str[pos] = '0' + n[i-1];
				if (str[pos] == '0') {
					str[pos] = '1';
					++pos;
					str[pos] = '0';
				}
			}
			++pos;
		}
		break;
	}

	printf("%s\n", str);
	return 0;
}
