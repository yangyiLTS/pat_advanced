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
	int a, b;
	cin >> a >> b;
	int res = a + b;
	if (res < 0) {
		cout << '-';
		res *= -1;
	}
	int n = 1000000,flag = 0;
	for (int i = 0; i < 7; i++) {
		int m = res / n;
		if (flag == 0 && m != 0) {
			flag = 1;
		}
		if (flag) {
			cout << m;
			if (i == 0 || i == 3) {
				cout << ',';
			}
		}
		res = res % n;
		n = n / 10;
	}
	if (flag == 0) {
		cout << 0;
	}
	system("pause");
	return 0;
}
