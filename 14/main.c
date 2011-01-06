#include <stdio.h>

#define CACHE_SIZE 1000000


unsigned long long next_in_sequence(unsigned long long v) {
	if ((v & 1) == 0) return v/2;
	return 3*v+1;
}

unsigned long long sequence_size(unsigned long long v, unsigned long long* cache) {
	if (v == 1) return 1;
	if (v < CACHE_SIZE && cache[v] > 0) return cache[v];
	unsigned long long size = sequence_size(next_in_sequence(v), cache);
	if (v < CACHE_SIZE) cache[v] = size;
	return size+1;
}

int main() {
	unsigned long long cache[CACHE_SIZE];
	unsigned long long i;
	for (i = 0; i < CACHE_SIZE; ++i) cache[i] = 0;

	unsigned long long max = 0;
	unsigned long long max_count = 0;
	for (i = 1; i < 1000000; ++i) {
		unsigned long long count = sequence_size(i, cache);
		if (count > max_count) {
			max_count = count;
			max = i;
		}
	}
	printf("%llu\n", max);
	return 0;
}
