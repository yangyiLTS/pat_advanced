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

struct Time {
	int h, m, s;
};

bool timeCompare(Time a, Time b) {
	for (int i = 0; i < 3; i++) {
		int j, k;
		switch (i)
		{
		case 0: j = a.h, k = b.h; break;
		case 1: j = a.m, k = b.m; break;
		case 2: j = a.s, k = b.s; break;
		default:
			break;
		}
		if (j > k) {
			return 1;
		}
		else if (j < k) {
			return 0;
		}
	}
}

int main() {
	int N;
	scanf("%d", &N);
	char unlockedID[16], lockedID[16];
	Time first, last;
	first = { 23,59,59 };
	last = { 0,0,0 };
	for (int i = 0; i < N; i++) {
		Time a, b;
		char id[16];
		scanf("%s %d:%d:%d %d:%d:%d", id, &a.h, &a.m, &a.s, &b.h, &b.m, &b.s);
		if (timeCompare(first, a)) {
			first = a;
			strcpy(unlockedID, id);
		}
		if (timeCompare(b, last)) {
			last = b;
			strcpy(lockedID, id);
		}
	}

	printf("%s %s", unlockedID, lockedID);
	system("pause");
	return 0;
}
