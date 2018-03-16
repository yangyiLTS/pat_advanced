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

using namespace std;

int seq[1010];

void init() {
	for (int i = 0; i < 1010; i++) {
		seq[i] = i + 1;
	}
}

int main() {
	init();
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < k; i++) {
		queue<int> qu;
		stack<int> st;
		int a;
		for (int j = 0; j < m; j++) {
			scanf("%d", &a);
			qu.push(a);
		}
		int p = 0;
		while (p < m) {
			if (p < m&&st.empty()) {
				st.push(seq[p]);
				p++;
			}
			if (p < m&&st.top() != qu.front()) {
				st.push(seq[p]);
				p++;
				if (st.size() > n) {
					break;
				}
			}
			while(!st.empty() && !qu.empty() && st.top() == qu.front()){
				st.pop();
				qu.pop();
			}
		}
		if (st.empty() && qu.empty()) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}

	system("pause");
	return 0;
}
