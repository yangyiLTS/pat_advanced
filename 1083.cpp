#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <algorithm>
// #include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <stack>

using namespace std;

struct Student {
	bool flag = 0;
	char name[11];
	char id[11];
} s[101];

//bool cmp(Student a, Student b) {
//	return a.grade > b.grade;
//}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int grade;
		char name[11], id[11];
		scanf("%s%s%d", name, id, &grade);
		s[grade].flag = 1;
		strcpy(s[grade].name, name);
		strcpy(s[grade].id, id);
	}

	int gmin, gmax;
	bool print_flag = 0;
	scanf("%d%d", &gmin, &gmax);
	for (int i = gmax; i >= gmin; i--) {
		if (s[i].flag) {
			print_flag = 1;
			printf("%s %s\n", s[i].name, s[i].id);
		}
	}
	if (!print_flag) {
		printf("NONE");
	}
	system("pause");
	return 0;
}
