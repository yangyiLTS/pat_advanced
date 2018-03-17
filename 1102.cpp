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

const int maxn = 10;

struct node {
	int lchild, rchild;
} Node[maxn];

bool notRoot[maxn] = { 0 };

int n, num = 0;
void print(int id) {
	printf("%d", id);
	num++;
	if (num < n) {
		printf(" ");
	}
	else {
		printf("\n");
	}
}

void inorder(int root) {
	if (root == -1) {
		return;
	}
	inorder(Node[root].lchild);
	print(root);
	inorder(Node[root].rchild);
}

void BFS(int root) {
	queue<int> q;
	q.push(root);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		print(now);
		if (Node[now].lchild != -1) {
			q.push(Node[now].lchild);
		}
		if (Node[now].rchild != -1) {
			q.push(Node[now].rchild);
		}
	}
}

void postorder(int root) {
	if (root == -1) {
		return;
	}
	postorder(Node[root].lchild);
	postorder(Node[root].rchild);
	swap(Node[root].lchild, Node[root].rchild);
}

int strToNum(char c) {
	if (c == '-') {
		return -1;
	}
	else {
		notRoot[c - '0'] = true;
		return c - '0';
	}
}

int findRoot() {
	for (int i = 0; i < n; i++) {
		if (notRoot[i] == false) {
			return i;
		}
	}
}

int main() {
	char lchild, rchild;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		//getchar();
		scanf("%*c%c %c", &lchild, &rchild);
		Node[i].lchild = strToNum(lchild);
		Node[i].rchild = strToNum(rchild);
	}

	int root;
	for (int i = 0; i < n; i++) {
		if (notRoot[i] == false) {
			root = i;
			break;
		}
	}
	postorder(root);
	BFS(root);
	num = 0;
	inorder(root);

	system("pause");
	return 0;
}
