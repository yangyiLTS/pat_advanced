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
#include <map>
#include <stack>

using namespace std;

const int N = 1000010;
const int INF = 0x7fffffff;
int S1[N], S2[N];

int main() {
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &S1[i]);
	}

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &S2[i]);
	}

	S1[n] = INF;
	S2[m] = INF;

	int i = 0, j = 0;
	int mid = (n + m - 1) / 2;
	while (i + j < mid) {
		if (S1[i] < S2[j]) {
			i++;
		}
		else {
			j++;
		}
	}

	if (S1[i] < S2[j]) {
		printf("%d", S1[i]);
	}
	else {
		printf("%d", S2[j]);
	}

	system("pause");
	return 0;
}



