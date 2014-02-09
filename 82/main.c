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
	int i = 0, j, new_c, c;
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
	int changed = 1;
	for (i = 0; i < SIZE; i++) {
		cost[i][0] = values[i][0];
	}

	while (changed) {
		changed = 0;
		for (i = 0; i < SIZE; i++) {
			for (j = 1; j < SIZE; j++) {
				new_c = 999999999;
				if (i > 0) {
					new_c = cost[i - 1][j] + values[i][j];
				}
				if (i + 1 < SIZE) {
					new_c = MIN(new_c, cost[i + 1][j] + values[i][j]);
				}
				new_c = MIN(new_c, cost[i][j - 1] + values[i][j]);
				if (new_c != cost[i][j]) {
					changed = 1;
					cost[i][j] = new_c;
				}
			}
		}
	}
	c = 999999999;
	for (i = 0; i < SIZE; i++) {
		c = MIN(c, cost[i][SIZE - 1]);
	}
	printf("%d\n", c);
	return 0;
}
