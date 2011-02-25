#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
	int n[10];
	int i;
	for (i=0;i<10;i++)
		n[i] = 9-i;

	char str[18];
	int v[4];
	int found = 0;
	while (1) {
		for (n[0]=9;n[0]>=0;n[0]--) {
			for (n[1]=9;n[1]>=0;n[1]--) {
				if (n[0] == n[1]) continue;
				for (n[2]=9;n[2]>=0;n[2]--) {
					if (n[0] == n[2]) continue;
					if (n[1] == n[2]) continue;
					v[0] = n[0] + n[1] + n[2];
					if (n[0] == 0 || n[1] == 0 || n[2] == 0) v[0] += 10;
					for (n[3]=9;n[3]>=0;n[3]--) {
						if (n[0] == n[3]) continue;
						if (n[1] == n[3]) continue;
						if (n[2] == n[3]) continue;
						for (n[4]=9;n[4]>=0;n[4]--) {
							if (n[0] == n[4]) continue;
							if (n[1] == n[4]) continue;
							if (n[2] == n[4]) continue;
							if (n[3] == n[4]) continue;
							v[1] = n[3] + n[2] + n[4];
							if (n[3] == 0 || n[2] == 0 || n[4] == 0) v[1] += 10;
							if (v[0] != v[1]) continue;
							for (n[5]=9;n[5]>=0;n[5]--) {
								if (n[0] == n[5]) continue;
								if (n[1] == n[5]) continue;
								if (n[2] == n[5]) continue;
								if (n[3] == n[5]) continue;
								if (n[4] == n[5]) continue;
								for (n[6]=9;n[6]>=0;n[6]--) {
									if (n[0] == n[6]) continue;
									if (n[1] == n[6]) continue;
									if (n[2] == n[6]) continue;
									if (n[3] == n[6]) continue;
									if (n[4] == n[6]) continue;
									if (n[5] == n[6]) continue;
									v[2] = n[5] + n[4] + n[6];
									if (n[5] == 0 || n[4] == 0 || n[6] == 0) v[2] += 10;
									if (v[0] != v[2]) continue;
									for (n[7]=9;n[7]>=0;n[7]--) {
										if (n[0] == n[7]) continue;
										if (n[1] == n[7]) continue;
										if (n[2] == n[7]) continue;
										if (n[3] == n[7]) continue;
										if (n[4] == n[7]) continue;
										if (n[5] == n[7]) continue;
										if (n[6] == n[7]) continue;
										for (n[8]=9;n[8]>=0;n[8]--) {
											if (n[0] == n[8]) continue;
											if (n[1] == n[8]) continue;
											if (n[2] == n[8]) continue;
											if (n[3] == n[8]) continue;
											if (n[4] == n[8]) continue;
											if (n[5] == n[8]) continue;
											if (n[6] == n[8]) continue;
											if (n[7] == n[8]) continue;
											v[3] = n[7] + n[6] + n[8];
											if (n[7] == 0 || n[6] == 0 || n[8] == 0) v[3] += 10;
											if (v[0] != v[3]) continue;
											for (n[9]=9;n[9]>=0;n[9]--) {
												if (n[0] == n[9]) continue;
												if (n[1] == n[9]) continue;
												if (n[2] == n[9]) continue;
												if (n[3] == n[9]) continue;
												if (n[4] == n[9]) continue;
												if (n[5] == n[9]) continue;
												if (n[6] == n[9]) continue;
												if (n[7] == n[9]) continue;
												if (n[8] == n[9]) continue;
												v[4] = n[9] + n[8] + n[1];
												if (n[9] == 0 || n[8] == 0 || n[1] == 0) v[4] += 10;
												if (v[0] != v[4]) continue;

		if (n[2] == 0 || n[4] == 0 || n[6] == 0) continue;
		for (i=0;i<18;i++) {
			str[i] = 0;
		}

		int pos = 0;
		for (i=0;i<11;i++) {
			if (i == 10) {
				str[pos] = '0' + n[1];
				break;
			}
			str[pos] = '0' + n[i];
			if (str[pos] == '0') {
				str[pos] = '1';
				++pos;
				str[pos] = '0';
			}
			if (i == 3 || i == 5 || i == 7 || i == 9) {
				++pos;
				str[pos] = '0' + n[i-1];
				if (str[pos] == '0') {
					str[pos] = '1';
					++pos;
					str[pos] = '0';
				}
			}
			++pos;
		}
		found = 1;
		break;
											}
											if (found) break;
										}
										if (found) break;
									}
									if (found) break;
								}
								if (found) break;
							}
							if (found) break;
						}
						if (found) break;
					}
					if (found) break;
				}
				if (found) break;
			}
			if (found) break;
		}
		if (found) break;
	}

	printf("%s\n", str);
	return 0;
}
