#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <algorithm>
// #include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <map>

using namespace std;
int Rank[1000000][5];
int now;
struct Student {
	int id;
	int grade[4];
} student[2010];

void getBestrank(const int id) {
	int best = 3;
	if (Rank[id][3] == 0) {
		printf("N/A\n");
	}
	else {
		for (int i = 2; i >= 0; i--) {
			if (Rank[id][i] <= Rank[id][best]) {
				best = i;
			}
		}
		char c[5] = "ACME";
		printf("%d %c\n", Rank[id][best], c[best]);
	}
}

bool cmp(Student a, Student b) {
	return a.grade[now] > b.grade[now];
}


int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &student[i].id, &student[i].grade[1],
			&student[i].grade[2], &student[i].grade[3]);
		for (int j = 1; j < 4; j++) {
			student[i].grade[0] += student[i].grade[j];
		}
	}

	for (now = 0; now < 4; now++) {
		sort(student, student + n, cmp);
		Rank[student[0].id][now] = 1;
		for (int i = 1; i < n; i++) {
			if (student[i].grade[now] == student[i - 1].grade[now]) {
				Rank[student[i].id][now] = Rank[student[i - 1].id][now];
			}
			else {
				Rank[student[i].id][now] = i + 1;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		int query;
		scanf("%d", &query);
		getBestrank(query);
	}

	return 0;
}
