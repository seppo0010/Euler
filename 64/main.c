#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define SIZE 100

int main() {
	//11, 13
	int i=23, a=1,b,c,d,e,f=1;
	int den, starte, startf;
	//for (i=2;i<14;i++)
	{
		e = a = sqrt(i);
		int min = a;
		den = c = i - min;
		f = 1;
		//if (sqrt(i) * sqrt(i) == i) continue;
		int hhhh = 0;
		starte = e;
		startf = f;
		do {
			a = f;
			b = e;
			c = i - e*e;
			//d = (int)ceil((double)a*b / den);
			f = c / a;
			d = (int)ceil((double)b/(c/a));
			e = f * d - b;
			printf("e %d\n", e);
			while (e < min-1) {
				d+=1;
				e = f * d - b;
				printf("%d %d %d %d\n", f,d,b,e);
				printf("%d\n", min);
			}
			printf("%d/%d/%d = %d\n", b,c,a,d);
			//if (c / a * d - b == 0) d = (int)ceil((double)a*b*2 / den);
			printf("%d*(sqrt(i)+%d)/%d=%d+(sqrt(i)-%d)/%d\n", a,b,c,d,e,f);
			if (e == starte && f == startf) break;
		} while (++hhhh < 1000);
		printf("%d\n", 1+hhhh);
	}
	return 0;
}
