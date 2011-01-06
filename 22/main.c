#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 46447

void swap(char* *a, char* *b)
{
  char *t=*a; *a=*b; *b=t;
}

void sort(char* arr[], int beg, int end)
{
  if (end > beg + 1)
  {
    char* piv = arr[beg];
    int l = beg + 1, r = end;
    while (l < r)
    {
      if (strcmp(arr[l],piv) <= 0)
        l++;
      else
        swap(&arr[l], &arr[--r]);
    }
    swap(&arr[--l], &arr[beg]);
    sort(arr, beg, l);
    sort(arr, r, end);
  }
}

unsigned long long alphabetical_value(char* name) {
	unsigned long long total = 0;
	int i, c = strlen(name);
	for (i=0;i<c;++i) {
		total += name[i] - 64;
	}
	return total;
}

int main() {
	char str[SIZE];
	FILE* file = fopen("names.txt", "r");
	fgets(str, SIZE+1, file);
	fclose(file);

	char **names = malloc(sizeof(char*) * 200);
	int c = 0;
	int i;
	char *name = malloc(sizeof(char) * 40);
	int name_length = 0;
	for (i=0; i < SIZE+1; ++i) {
		if (str[i] == '"') {
			continue;
		} else if (str[i] == ',' || str[i] == 0) {
			names[c] = malloc(sizeof(char) * name_length + 1);
			memcpy(names[c], name, name_length);
			names[c][name_length] = '\0';
			name_length = 0;
			++c;
		} else {
			name[name_length++] = str[i];
		}
	}
	free(name);

	sort(names, 0, c);
	long long unsigned total = 0;
	for (i=0; i < c;++i) {
		total += (i+1) * alphabetical_value(names[i]);
	}
	printf("%llu\n", total);
}
