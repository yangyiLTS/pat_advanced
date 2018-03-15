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
struct str {
	char name[5];
};
vector<str> course[40010];
bool cmp(str a, str b) {
	return strcmp(a.name, b.name) < 0;
}

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		str name;
		int m;
		scanf("%s %d", name.name, &m);
		for (int j = 0; j < m; j++) {
			int c;
			scanf("%d", &c);
			course[c].push_back(name);
		}
	}
	for (int i = 1; i <= k; i++) {
		printf("%d %d\n", i, course[i].size());
		sort(course[i].begin(), course[i].end(),cmp);
		for (int j = 0; j < course[i].size(); j++) {
			printf("%s\n", course[i][j].name);
		}
	}

	system("pause");
	return 0;
}
