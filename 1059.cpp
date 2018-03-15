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

const int N = 100010;
int pcnt = 0;
struct Factor {
	int prime;
	int cnt = 0;
} factors[N];



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

void findPrime() {
	int num[N];
	for (int i = 2; i < N; i++) {
		num[i] = i;
	}
	int j = 2;
	//int count = 0;
	for (int i = 2; i < N; i++) {
		if (num[i] == 0) {
			continue;
		}
		factors[pcnt++].prime = i;
		int j = i + i;
		while (j < N) {
			num[j] = 0;
			j += i;
		}
	}

}

int main() {
	findPrime();
	int n;
	scanf("%d", &n);
	int temp = n;
	for (int i = 0; i < pcnt;) {
		if (n == 1) {
			break;
		}
		if (n%factors[i].prime == 0) {
			factors[i].cnt++;
			n /= factors[i].prime;
		}
		else {
			i++;
		}
	}
	printf("%d=", temp);
	int pflag = 0;
	for (int i = 0; i < pcnt; i++) {
		if (factors[i].cnt > 0) {
			if (pflag) {
				printf("*");
			}
			printf("%d", factors[i].prime);
			if (factors[i].cnt > 1) {
				printf("^%d", factors[i].cnt);
			}
			pflag = 1;
		}
	}
	if (n != 1 || temp == 1) {
		if (pflag) {
			printf("*");
		}
		printf("%d", n);
	}
	system("pause");
	return 0;
}

