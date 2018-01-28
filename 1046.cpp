#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
// #include <iomanip>
#include <stdlib.h>
#include <string>
#include <map>
using namespace std;

int main() {
	int N, D[100010];
	int total, cw[100010];
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> D[i];
	}
	cw[0] = 0;
	for (int i = 1; i < N; i++) {
		cw[i] = D[i - 1] + cw[i - 1];
	}
	total = D[N - 1] + cw[N - 1];

	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int a, b, ans;
		cin >> a >> b;
		ans = abs(cw[a - 1] - cw[b - 1]);
		cout << ((ans < total - ans) ? ans : total - ans) << endl;
	}

	system("pause");
	return 0;
}
