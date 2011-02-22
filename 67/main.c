#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX(a,b) (a>b?a:b)

int main() {
	FILE* file = fopen("triangle.txt", "r");
	char str[4];
	str[3] = 0;
	int i, j, n;
	int *a = malloc(sizeof(int) * 100);
	int *b = malloc(sizeof(int) * 100);
	int **current = &b;
	int **next = &a;

	for (j=0;j<100;j++) a[j] = 0;
	for (j=0;j<100;j++) b[j] = 0;
	for (i=0;i<100;++i) {
		for (j=0;j<=i;j++) {
			fgets(str, 4, file);
			n = atoi(str);
			if (j == 0) (*next)[j] = (*current)[j] + n;
			else (*next)[j] = MAX(MAX((*next)[j], (*current)[j] + n), (*current)[j-1] + n);
		}

		fgets(str, 1, file);
		fgets(str, 4, file);
		if (i % 2 == 0) {
			current = &a;
			next = &b;
		} else {
			current = &b;
			next = &a;
		}
		for (j=0;j<=i;j++) (*next)[j] = 0;

#ifdef DEBUG
		for (j=0;j<=i;j++) printf("%d ", (*current)[j]);
		printf("\n");
#endif
	}

	int max = 0;
	for (i=0;i<100;++i) max = MAX((*current)[i], max);
	printf("%d\n", max);

	free(a);
	free(b);
	fclose(file);
	return 0;
}
