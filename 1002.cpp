#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
// #include <iomanip>
#include <stdlib.h>
#include <string>
#include <map>
using namespace std;
typedef long long ll;

int main() {
	float p[1010] = { 0 };
	int count = 0;
	for (int i = 0; i < 2; i++) {
		int k;
		cin >> k;
		for (int i = 0; i < k; i++) {
			int e;
			float a;
			cin >> e >> a;
			if (p[e] == 0) {
				count++;
			}
			p[e] += a;
			if (p[e] == 0) {
				count--;
			}
		}
	}
	cout << count;
	for (int i = 1001; i >= 0 && count > 0; i--) {
		if (p[i] != 0) {
			printf(" %d %0.1f", i, p[i]);
			count--;
		}
	}

	system("pause");
	return 0;
}
