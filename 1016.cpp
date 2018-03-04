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
int toll[24];
struct Record {
	char name[21];
	int month, dd, hh, mm;
	bool status;
} r[1010];

bool cmp_name(Record a, Record b) {
	return strcmp(a.name, b.name) < 0;
}

bool cmp_time(Record a, Record b) {
	int atime, btime;
	atime = a.month * 1000000 + a.dd * 10000 + a.hh * 100 + a.mm;
	btime = b.month * 1000000 + b.dd * 10000 + b.hh * 100 + b.mm;
	return atime < btime;
}

void get_bill(int a, int b) {
	bool flag = 1, pairflag = 0;
	// stack<Record> s;
	int now = a;
	double total = 0;
	for (int i = a + 1; i < b; i++) {
		if (!r[now].status || (r[now].status && r[i].status)) {
			now = i;
		}
		else if(r[now].status && !r[i].status){
			if (flag) {
				printf("%s %02d\n", r[i].name, r[i].month);
				flag = 0;
			}
			pairflag = 1;
			int d1, h1, m1, d2, h2, m2;
			d1 = r[now].dd;
			h1 = r[now].hh;
			m1 = r[now].mm;
			d2 = r[i].dd;
			h2 = r[i].hh;
			m2 = r[i].mm;
			printf("%02d:%02d:%02d %02d:%02d:%02d ", r[now].dd, r[now].hh, r[now].mm, r[i].dd, r[i].hh, r[i].mm);
			int charge = 0, mcount =0;
			while (d1 < d2 || h1 < h2 || m1 < m2) {
				m1++;
				mcount++;
				charge += toll[h1];
				if (m1 == 60) {
					m1 = 0;
					h1++;
				}
				if (h1 == 24) {
					h1 = 0;
					d1++;
				}
			}
			printf("%d $%.2f\n", mcount, (double)charge / 100.00);
			total += (double)charge / 100.00;
			now = i;
		}
	}
	if (pairflag) {
		printf("Total amount: $%.2f\n", total);
	}
}
int main() {
	int n;
	for (int i = 0; i < 24; i++) {
		scanf("%d", &toll[i]);
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char temp[10];
		scanf("%s %d:%d:%d:%d %s", r[i].name, &r[i].month, &r[i].dd, &r[i].hh, &r[i].mm, temp);
		if (temp[1] == 'n') {
			r[i].status = 1;
		}
		else {
			r[i].status = 0;
		}
	}

	sort(r, r + n, cmp_name);

	int begin = 0;
	for (int i = 1; i < n; i++) {
		if (strcmp(r[begin].name, r[i].name) < 0) {
			sort(r + begin, r + i, cmp_time);
			get_bill(begin, i);
			begin = i;
		}
	}
	sort(r + begin, r + n, cmp_time);
	get_bill(begin, n);

	return 0;
}


/*
10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
5
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 on-line
aaa 01:02:00:02 off-line
*/