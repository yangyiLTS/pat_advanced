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

struct Applicant {
	bool flag = 0;
	int id;
	int ge, gi, total, rank;
	int school[5];
} a[40000];

struct School {
	int last_rank = -1;
	int quota;
	int acount = 0;
	int applicant[40000];
	School() {
		memset(applicant, -1, sizeof(applicant));
	}
} sch[100];

int getTotal(Applicant a) {
	return (a.ge + a.gi);
}

bool cmp(Applicant a, Applicant b) {
	if (a.total != b.total) {
		return a.total > b.total;
	}
	else {
		return a.ge > b.ge;
	}
}

bool cmp_id(int a,int b) {
	return a < b;
}

int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);

	for (int i = 0; i < m; i++) {
		scanf("%d", &sch[i].quota);
	}

	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i].ge, &a[i].gi);
		a[i].id = i;
		a[i].total = getTotal(a[i]);
		for (int j = 0; j < k; j++) {
			scanf("%d", &a[i].school[j]);
		}
	}

	sort(a, a + n, cmp);
	a[0].rank = 0;
	for (int i = 1; i < n; i++) {
		if (a[i].total == a[i - 1].total && a[i].ge == a[i - 1].ge) {
			a[i].rank = a[i - 1].rank;
		}
		else {
			a[i].rank = i;
		}
	}

	for (int q = 0; q < n; q++) {
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < m; j++) {
				if (a[q].flag == 0 && a[q].school[i] == j && (sch[j].quota > 0 || sch[j].last_rank == a[q].rank)) {
					sch[j].applicant[sch[j].acount++] = a[q].id;
					sch[j].quota--;
					sch[j].last_rank = a[q].rank;
					a[q].flag = 1;
				}
			}
		}
	}

	for (int i = 0; i < m; i++) {
		sort(sch[i].applicant, sch[i].applicant + sch[i].acount, cmp_id);
		for (int j = 0; j < sch[i].acount; j++) {
			if (j != 0) {
				printf(" ");
			}
			printf("%d", sch[i].applicant[j]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}

/*
5 5 3
0 0 0 5 5
100 100 0 1 2
100 99 1 2 0
99 100 2 1 0
99 99 1 0 2
99 98 2 0 1
*/