#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int sign(p1x, p1y, p2x, p2y, p3x, p3y) {
	return ((p1x - p3x) * (p2y - p3y) - (p2x - p3x) * (p1y - p3y)) < 0;
}

int pointintriangle(v1x, v1y, v2x, v2y, v3x, v3y) {
	int b1, b2, b3;
	b1 = sign(0, 0, v1x, v1y, v2x, v2y);
	b2 = sign(0, 0, v2x, v2y, v3x, v3y);
	b3 = sign(0, 0, v3x, v3y, v1x, v1y);

	return b1 == b2 && b2 == b3;
}

int main() {
	FILE* file = fopen("triangles.txt", "r");
	int ax, ay, bx, by, cx, cy, c = 0;
	while (fscanf(file, "%d,%d,%d,%d,%d,%d\n", &ax, &ay, &bx, &by, &cx, &cy) == 6) {
		c += pointintriangle(ax, ay, bx, by, cx, cy);
	}
	printf("%d\n", c);
	return 0;
}
