#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
//#include<cstdio>
#include <stdio.h>
#include <algorithm>
// #include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <math.h>
#include <set>
#include <vector>
using namespace std;

const int N = 51;

set<int> sets[N];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int k;
		scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			int num;
			scanf("%d", &num);
			sets[i].insert(num);
		}
	}
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		int totalNum = sets[b].size();
		int sameNum = 0;
		for (set<int>::iterator it = sets[a].begin(); it != sets[a].end(); it++) {
			if (sets[b].find(*it) != sets[b].end()) {
				sameNum++;
			}
			else {
				totalNum++;
			}
		}
		printf("%.1f%%\n", sameNum*100.0 / totalNum);
	}

	system("pause");
	return 0;
}
