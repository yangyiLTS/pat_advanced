#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
// #include <iomanip>
#include <stdlib.h>
#include <cstring>
#include <map>
using namespace std;
typedef long long ll;

bool isPalindromic(const int z[], int n) {
	for (int i = 0; i <= n / 2; i++) {
		if (z[i] != z[n - 1 - i]) {
			return false;
		}
	}
	return true;
}

int main() {
	int N, b;
	cin >> N >> b;
	int z[40];
	int y = N, count = 0;
	do {
		z[count++] = y % b;
		y = y / b;
	} while (y != 0);

	if (isPalindromic(z, count)) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	for (int i = count - 1; i >=  0; i--) {
		if (i != count - 1) {
			cout << ' ';
		}
		cout << z[i];
	}

	system("pause");
	return 0;
}
