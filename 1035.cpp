#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
// #include <iomanip>
#include <stdlib.h>
#include <cstring>
#include <map>
using namespace std;
typedef long long ll;

struct Account {
	char un[11];
	char pw[11];
};

int main() {
	int N;
	scanf("%d", &N);
	int count = 0;
	Account res[1010];
	for (int i = 0; i < N; i++) {
		char un[11], pw[11];
		bool flag = 0;
		scanf("%s %s", un, pw);
		for (int j = 0; j < 11 && pw[j] != '\0'; j++) {
			switch (pw[j]) {
			case '1':pw[j] = '@'; flag = 1; break;
			case '0':pw[j] = '%'; flag = 1; break;
			case 'l':pw[j] = 'L'; flag = 1; break;
			case 'O':pw[j] = 'o'; flag = 1; break;
			}
		}
		if (flag) {
			strcpy(res[count].un, un);
			strcpy(res[count].pw, pw);
			count++;
		}
	}
	if (count > 0) {
		printf("%d\n", count);
		for (int i = 0; i < count; i++) {
			printf("%s %s\n", res[i].un, res[i].pw);
		}
	}
	else if (N == 1) {
		printf("There is 1 account and no account is modified");
	}
	else if (N > 1) {
		printf("There are %d accounts and no account is modified", N);
	}

	system("pause");
	return 0;
}
