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
	float A[1010] = { 0 };
	float B[1010] = { 0 };
	float ans[2010] = { 0 };
	int count = 0;
	for (int i = 0; i < 2; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int e;
			float a;
			cin >> e >> a;
			if (i == 0) {
				A[e] = a;
			}
			else {
				B[e] = a;
			}
		}
	}

	for (int i = 0; i < 1001; i++) {
		if (A[i] != 0) {
			for (int j = 0; j < 1001; j++) {
				if (B[j] != 0) {
					if (ans[i + j] == 0) {
						count++;
					}
					ans[i + j] += A[i] * B[j];
					if (ans[i + j] == 0) {
						count--;
					}
				}
			}
		}
	}

	cout << count;
	for (int i = 2001; i >= 0 && count > 0; i--) {
		if (ans[i] != 0) {
			printf(" %d %0.1f", i, ans[i]);
			count--;
		}
	}
	system("pause");
	return 0;
}
