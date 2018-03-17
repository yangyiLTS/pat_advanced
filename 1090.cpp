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

vector<int> child[maxn];
double p, r;

int n, num = 0, maxDepth = 0;
void DFS(int index, int depth) {
	if (child[index].size() == 0) {
		if (depth > maxDepth) {
			num = 1;
			maxDepth = depth;
		}
		else if (depth == maxDepth) {
			num++;
		}
		return;
	}
	for (int i = 0; i < child[index].size(); i++) {
		DFS(child[index][i], depth + 1);
	}
}

int main() {
	int father, root;
	scanf("%d%lf%lf", &n, &p, &r);
	r /= 100;
	for (int i = 0; i < n; i++) {
		scanf("%d", &father);
		if (father == -1) {
			root = i;
		}
		else {
			child[father].push_back(i);
		}
	}
	DFS(root, 0);
	printf("%.2f %d\n", p*pow(1 + r, maxDepth), num);
	system("pause");
	return 0;
}
