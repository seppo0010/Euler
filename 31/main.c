#include <stdio.h>

int currency(int pos) {
	switch (pos) {
		case 0: return 1;
		case 1: return 2;
		case 2: return 5;
		case 3: return 10;
		case 4: return 20;
		case 5: return 50;
		case 6: return 100;
		case 7: return 200;
	}
	return 400;
}

int main() {
	int a,b,c,d,e,f,g,h;
	int a_max,b_max,c_max,d_max,e_max,f_max,g_max,h_max;
	a_max = 200 / currency(0);
	b_max = 200 / currency(1);
	c_max = 200 / currency(2);
	d_max = 200 / currency(3);
	e_max = 200 / currency(4);
	f_max = 200 / currency(5);
	g_max = 200 / currency(6);
	h_max = 200 / currency(7);
	int counter = 0;
	for (a=0;a<=a_max;++a)
	for (b=0;b<=b_max;++b)
	for (c=0;c<=c_max;++c)
	for (d=0;d<=d_max;++d)
	for (e=0;e<=e_max;++e)
	for (f=0;f<=f_max;++f)
	for (g=0;g<=g_max;++g)
	for (h=0;h<=h_max;++h) {
		if (a*currency(0)+b*currency(1)+c*currency(2)+d*currency(3)+e*currency(4)+f*currency(5)+g*currency(6)+h*currency(7) == 200) {
			counter++;
		}
	}
	printf("%d\n", counter);
	return 0;
}

