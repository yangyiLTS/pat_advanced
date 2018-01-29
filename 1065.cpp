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
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		ll res = a + b;
		bool ans;
		if (a > 0 && b > 0 && res < 0) {
			ans = 1;
		}
		else if (a < 0 && b < 0 && res >= 0) {
			ans = 0;
		}
		else if (res > c) {
			ans = 1;
		}
		else {
			ans = 0;
		}
		if (ans) {
			cout << "Case #" << i << ": true\n";
		}
		else {
			cout << "Case #" << i << ": false\n";
		}
	}

	system("pause");
	return 0;
}
