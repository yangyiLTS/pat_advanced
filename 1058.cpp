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
	int a[3], b[3],res[3];
	scanf("%d.%d.%d %d.%d.%d", &a[0], &a[1], &a[2], &b[0], &b[1], &b[2]);
	for (int i = 0; i < 3; i++) {
		res[i] = a[i] + b[i];
	}
	
	int ca;
	ca = res[2] / 29;
	res[1] += ca;
	res[2] = res[2] % 29;
	
	ca = res[1] / 17;
	res[0] += ca;
	res[1] = res[1] % 17;

	printf("%d.%d.%d", res[0], res[1], res[2]);

	system("pause");
	return 0;
}
