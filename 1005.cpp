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
	char n[110];
	char num[10][6] = { "zero", "one", "two", "three","four","five","six","seven","eight","nine" };
	cin >> n;
	int sum = 0;
	for (int i = 0; n[i] != '\0'&&i < 110; i++) {
		sum += n[i] - '0';
	}

	bool flag = 0;
	int m = 100,res[3];
	for (int i = 0; i < 3; i++) {
		res[i] = sum / m;
		sum = sum % m;
		m = m / 10;	
	}

	for (int i = 0; i < 3; i++) {
		if (res[i] != 0) {
			flag = 1;
		}

		if (flag == 1) {
			cout << num[res[i]];
			if (i != 2) {
				cout << ' ';
			}
		}
	}
	if (flag == 0) {
		cout << num[0];
	}
	system("pause");
	return 0;
}
