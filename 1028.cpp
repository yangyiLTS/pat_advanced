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
	char name[9];
	int id;
	int grade;
} s[100010];

bool cmp_id(Student a, Student b) {
	return a.id < b.id;
}

bool cmp_grade(Student a, Student b) {
	if (a.grade != b.grade) {
		return a.grade < b.grade;

	}
	else {
		return a.id < b.id;
	}
}

bool cmp_name(Student a, Student b) {
	if (strcmp(a.name, b.name) == 0) {
		return a.id < b.id;
	}
	else {
		return strcmp(a.name, b.name) < 0;
	}
}

int main() {
	int n, c;
	scanf("%d %d", &n, &c);
	for (int i = 0; i < n; i++) {
		scanf("%d %s %d", &s[i].id, s[i].name, &s[i].grade);
	}

	if (c == 1) {
		sort(s, s + n, cmp_id);
	}
	else if (c == 2) {
		sort(s, s + n, cmp_name);
	}
	else {
		sort(s, s + n, cmp_grade);
	}

	for (int i = 0; i < n; i++) {
		printf("%06d %s %d\n", s[i].id, s[i].name, s[i].grade);
	}

	system("pause");
	return 0;
}

