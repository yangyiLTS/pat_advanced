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
	int c[3];
	scanf("%d %d %d", &c[0], &c[1], &c[2]);
	char res[8];
	res[0] = '#', res[7] = '\0';
	char num[14] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C' };
	for (int i = 0; i < 3; i++) {
		res[2 * i + 1] = num[c[i] / 13];
		res[2 * (i + 1)] = num[c[i] % 13];
	}
	printf("%s", res);
	system("pause");
	return 0;
}
