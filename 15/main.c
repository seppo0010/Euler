#include <stdio.h>

#define GRID_SIZE 21

int main () {
/*
1
1 2
1 3 6
1 4 10 20
1 5 15 35 70
1 6 21 56 126 252*/
	unsigned long long data[GRID_SIZE][GRID_SIZE];
	unsigned long long i, j;
	for (i=0; i < GRID_SIZE;++i)
		for (j=0; j < GRID_SIZE;++j)
			data[i][j] = 0;

	data[0][0] = 1;

	for (i=1;i<GRID_SIZE;++i) {
		for (j=0;j<i+1;++j) {
			if (j == i) data[i][i] = 2 * data[i][i-1];
			else data[i][j] = data[i][j-1] + data[i-1][j];
		}
	}

	printf("%llu\n", data[GRID_SIZE-1][GRID_SIZE-1]);
	return 0;
}
