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

string num[10010];

bool cmp(string a, string b) {
	return a + b < b + a;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	sort(num, num + n, cmp);
	string res;
	for (int i = 0; i < n; i++) {
		res += num[i];
	}
	while (res.size() != 0 && res[0] == '0') {
		res.erase(res.begin());
	}
	if (res.size() == 0) {
		cout << 0;
	}
	else {
		cout << res;
	}

	system("pause");
	return 0;
}

