#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
// #include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <map>

using namespace std;
typedef long long ll;

void Reverse(char s[], int n) {
	for (int i = 0, j = n - 1; i < j; i++, j--) {
		char temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}

int main() {
	int N;
	cin >> N;
	cin.get();
	char subStr[257];
	for (int i = 0; i < N; i++) {
		char temp[257];
		cin.getline(temp, 257);
		Reverse(temp, strlen(temp));
		if (i == 0) {
			strcpy(subStr, temp);
		}
		else {
			for (int j = 0; j < 257 && subStr[j] != '\0'; j++) {
				if (temp[j] != subStr[j]) {
					subStr[j] = '\0';
					break;
				}
			}
		}
	}
	Reverse(subStr,strlen(subStr));
	if (subStr[0] == '\0') {
		printf("nai");
	}
	else {
		printf("%s", subStr);
	}
	system("pause");
	return 0;
}
