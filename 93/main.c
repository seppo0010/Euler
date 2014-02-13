#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_N 100000

double do_op(double v1, double v2, int op, int* success) {
	if ((op == 3 && v2 == 0)) {
		*success = 0;
		return 0;
	}
	switch (op) {
		case 0: return v1 + v2;
		case 1: return v1 - v2;
		case 2: return v1 * v2;
		case 3: return v1 / v2;
	}
	return 0;
}

int is_int(double num) {
	int n = (int)floor(num);
	return (n-num)*(n-num) < 0.000000001;
}

static int ops[6][3] = {
	{0, 1, 2},
	{0, 2, 1},
	{1, 2, 0},
	{1, 0, 2},
	{2, 1, 0},
	{2, 0, 1}
};

static int vs[24][4] = {
	{0, 1, 2, 3},
	{0, 1, 3, 2},
	{0, 2, 1, 3},
	{0, 2, 3, 1},
	{0, 3, 1, 2},
	{0, 3, 2, 1},
	{1, 0, 2, 3},
	{1, 0, 3, 2},
	{1, 2, 0, 3},
	{1, 2, 3, 0},
	{1, 3, 0, 2},
	{1, 3, 2, 0},
	{2, 0, 1, 3},
	{2, 0, 3, 1},
	{2, 1, 0, 3},
	{2, 1, 3, 0},
	{2, 3, 0, 1},
	{2, 3, 1, 0},
	{3, 0, 1, 2},
	{3, 0, 2, 1},
	{3, 1, 0, 2},
	{3, 1, 2, 0},
	{3, 2, 0, 1},
	{3, 2, 1, 0},
};

int main() {
	// possible_operations = [+ - * /]
	// possible_order = [[12 123 1234], [12 34 1234], [23 123 1234], [23 234 1234], [34 234 1234]]
	int results[MAX_N];
	int order_op, order_v, i, success, max_n = 0;
	double tmp_v;
	char result[5];
	int v[4];
	int op[3];

	for (v[0] = 0; v[0]< 10; v[0]++)
	for (v[1] = v[0]+ 1; v[1]< 10; v[1]++)
	for (v[2] = v[1]+ 1; v[2]< 10; v[2]++)
	for (v[3] = v[2]+ 1; v[3]< 10; v[3]++) {
		for (i = 0; i < MAX_N; i++) {
			results[i] = 0;
		}
		for (op[0] = 0; op[0]< 4; op[0]++)
		for (op[1] = 0; op[1]< 4; op[1]++)
		for (op[2] = 0; op[2]< 4; op[2]++) {
			for (order_v = 0; order_v < 24; order_v++)
			for (order_op = 0; order_op < 6; order_op++) {
				success = 1;
				tmp_v = do_op(do_op(do_op(v[vs[order_v][0]], v[vs[order_v][1]], op[ops[order_op][0]], &success), v[vs[order_v][2]], op[ops[order_op][1]], &success), v[vs[order_v][3]], op[ops[order_op][2]], &success);
				if (success && tmp_v >= 0 && is_int(tmp_v)) {
					results[(int)tmp_v] += 1;
				}

				success = 1;
				tmp_v = do_op(do_op(v[vs[order_v][0]], v[vs[order_v][1]], op[ops[order_op][0]], &success), do_op(v[vs[order_v][2]], v[vs[order_v][3]], op[ops[order_op][2]], &success), op[ops[order_op][2]], &success);
				if (success && tmp_v >= 0 && is_int(tmp_v)) {
					results[(int)tmp_v] += 1;
				}

				success = 1;
				tmp_v = do_op(do_op(v[vs[order_v][0]], do_op(v[vs[order_v][1]], v[vs[order_v][2]], op[ops[order_op][1]], &success), op[ops[order_op][0]], &success), v[vs[order_v][3]], op[ops[order_op][2]], &success);
				if (success && tmp_v >= 0 && is_int(tmp_v)) {
					results[(int)tmp_v] += 1;
				}

				success = 1;
				tmp_v = do_op(v[vs[order_v][0]], do_op(do_op(v[vs[order_v][1]], v[vs[order_v][2]], op[ops[order_op][1]], &success), v[vs[order_v][3]], op[ops[order_op][2]], &success), op[ops[order_op][0]], &success);
				if (success && tmp_v >= 0 && is_int(tmp_v)) {
					results[(int)tmp_v] += 1;
				}

				success = 1;
				tmp_v = do_op(v[vs[order_v][0]], do_op(v[vs[order_v][1]], do_op(v[vs[order_v][2]], v[vs[order_v][3]], op[ops[order_op][2]], &success), op[ops[order_op][1]], &success), op[ops[order_op][0]], &success);
				if (success && tmp_v >= 0 && is_int(tmp_v)) {
					results[(int)tmp_v] += 1;
				}
			}
		}
		for (i = 1; i < MAX_N; i++) {
			if (results[i] == 0) {
				break;
			}
			if (i > max_n) {
				sprintf(result, "%d%d%d%d", v[0], v[1], v[2], v[3]);
				max_n = i;
			}
		}
	}
	printf("%s\n", result);
	return 0;
}
