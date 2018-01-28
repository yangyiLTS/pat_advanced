#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
// #include <iomanip>
#include <stdlib.h>
#include <string>
#include <map>
using namespace std;

void shuffling(int card[], const int p[]) {
	int ans[54];
	for (int i = 0; i < 54; i++) {
		ans[p[i] - 1] = card[i];
	}
	for (int i = 0; i < 54; i++) {
		card[i] = ans[i];
	}
}

void print(int a) {
	int n, c;
	n = a % 13 + 1;
	c = a / 13 + 1;
	switch (c){
	case 1: printf("S%d", n); break;
	case 2: printf("H%d", n); break;
	case 3: printf("C%d", n); break;
	case 4: printf("D%d", n); break;
	case 5: printf("J%d", n); break;
	default: break;
	}
}

int main() {
	int k;
	cin >> k;
	int card[54], pos[54];
	for (int i = 0; i < 54; i++) {
		card[i] = i;
		cin >> pos[i];
	}
	for (int i = 0; i < k; i++) {
		shuffling(card, pos);
	}
	for (int i = 0; i < 54; i++) {
		if (i) {
			cout << ' ';
		}
		print(card[i]);
	}
	system("pause");
	return 0;
}
