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

struct node {
	int data;
	node* lchild;
	node* rchild;
};

const int maxn = 50;
int n;
int pre[maxn], in[maxn], post[maxn];

node* creat(int preL, int preR, int inL, int inR) {
	if (preL > preR) {
		return NULL;
	}
	node* root = new node;
	root->data = pre[preL];
	int k;
	for (k = inL; k < inR; k++) {
		if (in[k] == pre[preL]) {
			break;
		}
	}
	int numLeft = k - inL;
	root->lchild = creat(preL + 1, preL + numLeft, inL, k - 1);
	root->rchild = creat(preL + numLeft + 1, preR, k + 1, inR);
	return root;
}

int num = 0;
void postorder(node* root) {
	if (root == NULL) {
		return;
	}
	postorder(root->lchild);
	postorder(root->rchild);
	printf("%d", root->data);
	num++;
	if (num < n) {
		printf(" ");
	}
}

int main() {
	scanf("%d", &n);
	char str[5];
	stack<int> st;
	int x, preIndex = 0, inIndex = 0;
	for (int i = 0; i < 2 * n; i++) {
		scanf("%s", str);
		if (strcmp(str, "Push") == 0) {
			scanf("%d", &x);
			pre[preIndex++] = x;
			st.push(x);
		}
		else {
			in[inIndex++] = st.top();
			st.pop();
		}
	}
	node* root = creat(0, n - 1, 0, n - 1);
	postorder(root);

	system("pause");
	return 0;
}
