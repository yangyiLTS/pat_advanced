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
	string a;
	cin >> a;
	int len = a.length();
	int n, n2;
	n2 = len / 3 + 1;
	while ((len - n2) % 2 == 1 || n2 < 3) {
		n2++;
	}
	n = (len - n2) / 2;

	for (int i = 0; len - 2 * i > n2; i++) {
		cout << a[i];
		for (int i = 0; i < n2 - 2; i++) {
			cout << ' ';
		}
		cout << a[len - 1 - i] << endl;
	}

	for (int i = 0; i < n2; i++) {
		cout << a[(len - n2) / 2 + i];
	}

	system("pause");
	return 0;
}
