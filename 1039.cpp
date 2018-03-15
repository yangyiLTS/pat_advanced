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
#include <vector>
using namespace std;
const int N = 40010;
const int M = 26 * 26 * 26 * 10 + 1;
vector<int> selectCourse[M];


int getID(char name[]) {
	int id = 0;
	for (int i = 0; i < 3; i++) {
		id = id * 26 + (name[i] - 'A');
	}
	id = id * 10 + (name[3] - '0');
	return id;
}

int main() {
	int n, k;
	char name[5];
	scanf("%d%d", &n, &k);
	for (int i = 0; i < k; i++) {
		int course, x;
		scanf("%d%d", &course, &x);
		for (int j = 0; j < x; j++) {
			scanf("%s", name);
			int id = getID(name);
			selectCourse[id].push_back(course);
		}
	}

	for (int i = 0; i < n; i++) {
		scanf("%s", name);
		int id = getID(name);
		sort(selectCourse[id].begin(), selectCourse[id].end());
		printf("%s %d", name, selectCourse[id].size());
		for (int j = 0; j < selectCourse[id].size(); j++) {
			printf(" %d", selectCourse[id][j]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}
