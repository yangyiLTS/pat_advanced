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

struct node {
	int data;
	node *lchild;
	node *rchild;
};


const int maxn = 1010;

int CBT[maxn];
int origin[maxn];
int index = 0;
int n;

void inOrder(int root) {
	if (root > n) {
		return;
	}
	inOrder(root * 2);
	CBT[root] = origin[index++];
	inOrder(root * 2 + 1);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &origin[i]);
	}

	sort(origin, origin + n);
	inOrder(1);
	for (int i = 1; i <= n; i++) {
		if (i != 1) {
			printf(" ");
		}
		printf("%d", CBT[i]);
	}

	system("pause");
	return 0;
}
