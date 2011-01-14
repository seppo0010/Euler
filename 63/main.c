#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
	int i, j, v, c=1;
	for (i=2;i<=9;++i) {
		for (j=1;;++j) {
			v = (int)log10(pow(i,j))+1;
			if (v==j) ++c;
			else if (v < j) break;
		}
	}
	printf("%d\n", c);
	return 0;
}
