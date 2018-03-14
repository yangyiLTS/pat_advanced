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


int main() {
	int n;
	scanf("%d", &n);
	int begin = n, alen = 0;
	for (int i = 2; i <= (int)sqrt(1.0*n); i++) {
		int len = 1, a = i;
		int temp = n;
		if (temp%a == 0) {
			temp = temp / a;
			a++;
			while (temp % a == 0) {
				len++;
				temp /= a;
				a++;
			}
			if (len > alen) {
				alen = len;
				begin = i;
			}
		}
	}
	if (alen == 0) {
		printf("1\n%d", n);
	}
	else {
		printf("%d\n", alen);
		for (int i = 0; i < alen; i++) {
			printf("%d", begin);
			begin++;
			if (i != alen - 1) {
				printf("*");
			}
		}
	}
	system("pause");
	return 0;
}

