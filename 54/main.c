#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 31

typedef struct {
	char num;
	char suite;
} card;

typedef struct {
	card cards[5];
} hand;

int num_value(char num) {
	switch (num) {
		case '2': return 1;
		case '3': return 2;
		case '4': return 3;
		case '5': return 4;
		case '6': return 5;
		case '7': return 6;
		case '8': return 7;
		case '9': return 8;
		case 'T': return 9;
		case 'J': return 10;
		case 'Q': return 11;
		case 'K': return 12;
		case 'A': return 13;
		default: break;
	}
	printf("Unknown num: %c\n", num);
	exit(0);
}

int num_prime_value(char num) {
	switch (num) {
		case '2': return 2;
		case '3': return 3;
		case '4': return 5;
		case '5': return 7;
		case '6': return 11;
		case '7': return 13;
		case '8': return 17;
		case '9': return 19;
		case 'T': return 23;
		case 'J': return 29;
		case 'Q': return 31;
		case 'K': return 37;
		case 'A': return 41;
		default: break;
	}
	printf("Unknown num: %c\n", num);
	exit(0);
}

int is_pair(hand _hand) {
	int i, num, prod = 1;
	for (i=0;i<5;++i) {
		num = num_prime_value(_hand.cards[i].num);
		if (prod % num == 0) return 1;
		prod *= num;
	}
	return 0;
}

int is_two_pairs(hand _hand) {
	int i, num, c = 0, prod = 1;
	for (i=0;i<5;++i) {
		num = num_prime_value(_hand.cards[i].num);
		if (prod % num == 0) ++c;
		else prod *= num;
	}
	return c == 2;
}

int is_three_of_a_kind(hand _hand) {
	int i;
	char num[3];
	num[0] = 0; num[1] = 0; num[2] = 0;
	int num_count[3];
	num_count[0] = 1; num_count[1] = 1; num_count[3] = 1;
	for (i=0;i<5;++i) {
		if (num[0] == _hand.cards[i].num) ++num_count[0];
		else if (num[1] == _hand.cards[i].num) ++num_count[1];
		else if (num[2] == _hand.cards[i].num) ++num_count[2];
		else if (num[0] == 0) num[0] = _hand.cards[i].num;
		else if (num[1] == 0) num[1] = _hand.cards[i].num;
		else if (num[2] == 0) num[2] = _hand.cards[i].num;
		else return 0;
	}
	return (num_count[0] * num_count[1] * num_count[2] % 3) == 0;
}

int is_straight(hand _hand) {
	int max = 0;
	int min = 14;
	int i, num, prod = 1;
	for (i=0;i<5;++i) {
		num = num_prime_value(_hand.cards[i].num);
		if (prod % num == 0) return 0;
		prod *= num;

		num = num_value(_hand.cards[i].num);
		if (num < min) min = num;
		if (num > max) max = num;
	}
	return max - min == 4;
}

int is_flush(hand _hand) {
	char suite = _hand.cards[0].suite;
	int i;
	for (i=1;i<5;++i) {
		if (_hand.cards[i].suite != suite) return 0;
	}
	return 1;
}

int is_full_house(hand _hand) {
	int i;
	char num[2];
	num[0] = 0; num[1] = 0;
	int num_count[2];
	num_count[0] = 1; num_count[1] = 1;
	for (i=0;i<5;++i) {
		if (num[0] == _hand.cards[i].num) ++num_count[0];
		else if (num[1] == _hand.cards[i].num) ++num_count[1];
		else if (num[0] == 0) num[0] = _hand.cards[i].num;
		else if (num[1] == 0) num[1] = _hand.cards[i].num;
		else return 0;
	}
	return num_count[0] * num_count[1] == 6;
}

int is_four_of_a_kind(hand _hand) {
	int i;
	char num[2];
	num[0] = 0; num[1] = 0;
	int num_count[2];
	num_count[0] = 1; num_count[1] = 1;
	for (i=0;i<5;++i) {
		if (num[0] == _hand.cards[i].num) ++num_count[0];
		else if (num[1] == _hand.cards[i].num) ++num_count[1];
		else if (num[0] == 0) num[0] = _hand.cards[i].num;
		else if (num[1] == 0) num[1] = _hand.cards[i].num;
		else return 0;
	}
	return num_count[0] * num_count[1] == 4;
}

int is_straight_flush(hand _hand) {
	return is_flush(_hand) && !is_straight(_hand);
}

int is_royal_flush(hand _hand) {
	if (!is_straight_flush(_hand)) return 0;
	int i;
	for (i=0;i<5;++i)
		if (_hand.cards[i].num == 'A') return 1;
	return 0;
}

double hand_value(hand _hand) {
	double ret;
	if (is_royal_flush(_hand)) ret = 10.0;
	else if (is_straight_flush(_hand)) ret = 9.0 + straight_flush_value(_hand);
	else if (is_four_of_a_kind(_hand)) ret = 8.0 + four_of_a_kind_value(_hand);
	else if (is_full_house(_hand)) ret = 7.0 + full_house_value(_hand);
	else if (is_flush(_hand)) ret = 6.0 + flush_value(_hand);
	else if (is_straight(_hand)) ret = 5.0 + straight_value(_hand);
	else if (is_three_of_a_kind(_hand)) ret = 4.0 + three_of_a_kind_value(_hand);
	else if (is_two_pairs(_hand)) ret = 3.0 + two_pairs_value(_hand);
	else if (is_pair(_hand)) ret = 2.0 + pair_value(_hand);
	else ret = 1.0 + high_card_value(_hand);
	return ret;
}

int compare_hands(hand hand1, hand hand2) {
#ifdef DEBUG
	printf("Hand 1: %f\n", hand_value(hand1));
	printf("Hand 2: %f\n", hand_value(hand2));
#endif
	return hand_value(hand1) > hand_value(hand2) ? 1 : -1; // no ties
}

int main() {
	char str[SIZE];
	FILE* file = fopen("poker.txt", "r");
	

	int c = 0;
	hand hands[2];

	while (fgets(str, SIZE+1, file) != NULL) {
		hands[0].cards[0].num = str[0];
		hands[0].cards[1].num = str[3];
		hands[0].cards[2].num = str[6];
		hands[0].cards[3].num = str[9];
		hands[0].cards[4].num = str[12];
		hands[1].cards[0].num = str[15];
		hands[1].cards[1].num = str[18];
		hands[1].cards[2].num = str[21];
		hands[1].cards[3].num = str[24];
		hands[1].cards[4].num = str[27];
		hands[0].cards[0].suite = str[1];
		hands[0].cards[1].suite = str[4];
		hands[0].cards[2].suite = str[7];
		hands[0].cards[3].suite = str[10];
		hands[0].cards[4].suite = str[13];
		hands[1].cards[0].suite = str[16];
		hands[1].cards[1].suite = str[19];
		hands[1].cards[2].suite = str[22];
		hands[1].cards[3].suite = str[25];
		hands[1].cards[4].suite = str[28];

#ifdef DEBUG
		int w = compare_hands(hands[0], hands[1]);
		printf("Winner %d\n", w);
		if (w > 0) ++c;
#else
		if (compare_hands(hands[0], hands[1]) > 0) ++c;
#endif
	}

	fclose(file);
	printf("%d\n", c);
	return 0;
}
