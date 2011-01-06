#define POWER 5

int main() {
	int sum = 0;
	int a, b, c, d, e, f;
	for (a=0;a<10;++a)
	for (b=0;b<10;++b)
	for (c=0;c<10;++c)
	for (d=0;d<10;++d)
	for (e=0;e<10;++e)
	for (f=0;f<10;++f)
	{
		if (f == 1 && a+b+c+d+e == 0) continue;
		int v = a * 100000 + b * 10000 + c * 1000 + d * 100 + e * 10 + f * 1;
		if (pow(a, POWER) + pow(b, POWER) + pow(c, POWER) + pow(d, POWER) + pow(e, POWER) + pow(f, POWER) == v) {
			sum += v;
		}
	}
	printf("%d\n", sum);
	return 0;
}
