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
#include <math.h>
#include <map>
#include <stack>

using namespace std;

bool isPrime(int n) {
	if (n <= 1) {
		return false;
	}
	for (int i = 2; i <= (int)sqrt(1.00*n); i++) {
		if (n%i == 0) {
			return false;
		}
	}
	return true;
}

int d[111];

int main() {
	int n, radix;
	while (scanf("%d", &n) != EOF) {
		if (n < 0) {
			break;
		}
		scanf("%d", &radix);
		if (!isPrime(n)) {
			printf("No\n");
		}
		else {
			int len = 0;
			do {
				d[len++] = n%radix;
				n /= radix;
			} while (n != 0);
			for (int i = 0; i < len; i++) {
				n = n*radix + d[i];
			}
			if (isPrime(n)) {
				printf("Yes\n");
			}
			else {
				printf("No\n");
			}
		}
	}

	system("pause");
	return 0;
}