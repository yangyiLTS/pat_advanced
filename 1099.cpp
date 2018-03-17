#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <stdio.h>
#include <algorithm>
// #include <iomanip>
#include <stdlib.h>
//#include <string.h>
#include <string>
#include <math.h>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <vector>

using namespace std;

const int maxn = 101;

struct node {
	int data;
	int lchild;
	int rchild;
} tree[maxn];
int n;

int number[maxn];

int index = 0, num = 0;

void inOrder(int root) {
	if (root == -1) {
		return;
	}
	inOrder(tree[root].lchild);
	tree[root].data = number[index++];
	inOrder(tree[root].rchild);
}

void BFS(int root) {
	queue<int> q;
	q.push(root);
	while (!q.empty()) {
		int index = q.front();
		q.pop();
		printf("%d", tree[index].data);
		num++;
		if (num < n) {
			printf(" ");
		}
		if (tree[index].lchild != -1) {
			q.push(tree[index].lchild);
		}
		if (tree[index].rchild != -1) {
			q.push(tree[index].rchild);
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int left, right;
		scanf("%d%d", &left, &right);
		tree[i].lchild = left;
		tree[i].rchild = right;
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &number[i]);
	}
	sort(number, number + n);
	inOrder(0);
	BFS(0);

	system("pause");
	return 0;
}
