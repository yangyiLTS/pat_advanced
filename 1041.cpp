#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <algorithm>
// #include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <stack>

using namespace std;

struct Node {
	int rank = -1;
	int number;
	int unique = 0;
}number[10001];

bool cmp(Node a, Node b) {
	return a.rank < b.rank;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		number[a].number = a;
		number[a].unique++;
		number[a].rank = i;
	}
	sort(number, number + 10001, cmp);
	bool pflag = 0;
	for (int i = 0; i < 10001; i++) {
		if (number[i].unique == 1) {
			printf("%d", number[i].number);
			pflag = 1;
			break;
		}
	}
	if (!pflag) {
		printf("None");
	}


	system("pause");
	return 0;
}

