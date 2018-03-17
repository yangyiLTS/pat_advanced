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
#include <vector>

using namespace std;

const int maxn = 100010;

struct node {
	int data;
	vector<int> child;
}Node[maxn];

double p, r, ans = 0;

int n, num = 0;

void DFS(int index, int depth) {
	if (Node[index].child.size() == 0) {
		ans += Node[index].data*p*pow(1 + r, depth);
		return;
	}
	for (int i = 0; i < Node[index].child.size(); i++) {
		DFS(Node[index].child[i], depth + 1);
	}
}


int main() {
	scanf("%d%lf%lf", &n, &p, &r);
	r /= 100;
	int k, child;
	for (int i = 0; i < n; i++) {
		scanf("%d", &k);
		if (k == 0) {
			scanf("%d", &child);
			Node[i].data = child;
		}
		else {
			for (int j = 0; j < k; j++) {
				scanf("%d", &child);
				Node[i].child.push_back(child);
			}
		}
	}

	DFS(0, 0);

	printf("%.1lf", ans);

	system("pause");
	return 0;
}
