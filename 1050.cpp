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

int main() {
	char s1[10001],s2[10001];
	//gets(s1);
	cin.getline(s1,10001);
	cin.getline(s2,10001);
	//getchar();
	//gets(s2);
	//getchar();
	int c[128];
	memset(c, 0, sizeof(c));
	for (int i = 0; s2[i] != '\0'; i++) {
		c[s2[i]]++;
	}
	for (int i = 0; s1[i] != '\0';i++) {
		if (c[s1[i]] == 0) {
			printf("%c", s1[i]);
		}
	}
	system("pause");
	return 0;
}

