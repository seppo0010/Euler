#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <sys/stat.h>

#define SIZE 80
#define MIN(a,b) (a<b?a:b)

int main() {
	char *token, *string, *row;
	struct stat st;
	stat("matrix.txt", &st);
	FILE* file = fopen("matrix.txt", "r");
	string = malloc(sizeof(char) * st.st_size);
	int values[SIZE][SIZE];
	int i = 0, j, c;
	while ((row = fgets(string, st.st_size+1, file)) != NULL) {
		j = 0;
		while ((token = strsep(&row, ",")) != NULL) {
			values[i][j] = atoi(token);
			j++;
		}
		i++;
	}
	int cost[SIZE][SIZE];
	cost[0][0] = values[0][0];
	int run = SIZE;
	for (i = 1; i <= run + run - 2; i++) {
		for (j = 0; j < run; j++) {
			if (j > i) break;
			c = 99999999;
			if (j > 0) {
				c = cost[j - 1][i - j];
			}
			if (i - j > 0 && cost[j][i - j - 1] < c) {
				c = cost[j][i - j - 1];
			}
			c += values[j][i - j];
			cost[j][i - j] = c;
		}
	}
	printf("%d\n", cost[run - 1][run - 1]);
	return 0;
}
