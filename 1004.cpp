#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include<cstdio>
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

const int maxn = 100;

struct node {
	int data;
	vector<int> child;
}Node[maxn];

vector<int> child[maxn];

bool nonLeaf[maxn] = { 0 };
int n, m = 0;
int num = 0;

void BFS(int root) {
	queue<int> q;
	q.push(root);
	while (!q.empty()) {
		int leaves = 0;
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int now = q.front();
			q.pop();
			if (child[now].empty()) {
				leaves++;
			}
			else {
				for (int j = 0; j < child[now].size(); j++) {
					q.push(child[now][j]);
				}
			}
		}
		printf("%d", leaves);
		if (!q.empty()) {
			printf(" ");
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	int father, k, id;
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &father, &k);
		nonLeaf[k] = 1;
		for (int j = 0; j < k; j++) {
			scanf("%d", &id);
			child[father].push_back(id);
		}
	}
	BFS(1);
	system("pause");
	return 0;
}
