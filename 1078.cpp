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

bool hashTable[10010] = { 0 };

int main() {
	int n, tsize;
	scanf("%d%d", &tsize, &n);
	while (!isPrime(tsize)) {
		tsize++;
	}
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		int m = a % tsize;
		if (i) {
			printf(" ");
		}
		if (!hashTable[m]) {
			hashTable[m] = true;
			printf("%d", m);
		}
		else {
			int step = 0;
			while (step < tsize) {
				int m2 = (m + step*step) % tsize;
				if (hashTable[m2]) {
					step++;
				}
				else {
					hashTable[m2] = true;
					printf("%d", m2);
					break;
				}
			}
			if (step >= tsize) {
				printf("-");
			}
		}
	}
	system("pause");
	return 0;
}

