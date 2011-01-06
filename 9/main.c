#include <stdio.h>

int main() {
	int x, y, z;
	for (x = 0; x < 500; ++x) {
		for (y = x; y < 500; ++y) {
			for (z = y; z < 500; ++z) {
				if (x+y+z==1000 && x*x+y*y==z*z) {
					printf("%d\n", x*y*z);
					return 0;
				}
			}
		}
	}
}
