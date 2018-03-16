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
#include <stack>
#include <queue>
#include <set>

using namespace std;

struct Node {
	char c;
	int next;
}linkList[100010];

int main() {
	int a1, a2, n;
	scanf("%d%d%d", &a1, &a2, &n);
	for (int i = 0; i < n; i++) {
		int a,next;
		char c;
		scanf("%d %c %d", &a, &c, &next);
		linkList[a].c = c;
		linkList[a].next = next;
	}
	set<int> st;
	//st.insert(a1);
	while (a1 != -1 && a2 != -1) {
		if (st.find(a2) != st.end()) {
			printf("%05d", a2);
			break;
		}
		else if (a2 != -1) {
			st.insert(a2);
			a2 = linkList[a2].next;
		}
		if (st.find(a1) != st.end()) {
			printf("%05d", a1);
			break;
		}
		else if (a1 != -1) {
			st.insert(a1);
			a1 = linkList[a1].next;
		}
	}
	if (a1 == -1 && a2 == -1) {
		printf("-1");
	}

	system("pause");
	return 0;
}
