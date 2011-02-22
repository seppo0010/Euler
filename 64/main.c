#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define SIZE 100

int main() {
	//11, 13
	int i=23, a=1,b,c,d,e,f=1;
	int den, starte, startf;
	int count = 0;
	int hhhh;
	for (i=2;i<10001;i++)
	{
		e = a = sqrt(i);
		den = c = i - a;
		f = 1;
		if ((int)sqrt(i) * (int)sqrt(i) == i) continue;
		hhhh = 0;
		starte = e;
		startf = f;
		do {
			a = f;
			b = e;
			c = i - e*e;
			d = floor((double)f / (sqrt(i) - b));
			f = c / a;
			e = f * d - b;
			//printf("e %d\n", e);
			//printf("%d/%d/%d = %d\n", b,c,a,d);
			//printf("%d*(sqrt(i)+%d)/%d=%d+(sqrt(i)-%d)/%d\n", a,b,c,d,e,f);
			if (e == starte && f == startf) break;
		} while (++hhhh < 1000);
		//printf("%d %d\n", i, 1+hhhh);
		if (1+hhhh % 2 == 1) ++count;
	}
	printf("%d\n", count);
	return 0;
}
