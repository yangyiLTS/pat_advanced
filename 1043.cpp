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

struct node {
	int data;
	node *lchild;
	node *rchild;
};

void insert(node* &root, int data) {
	if (root == NULL) {
		root = new node;
		root->data = data;
		root->lchild = NULL;
		root->rchild = NULL;
		return;
	}
	if (data < root->data) {
		insert(root->lchild, data);
	}
	else {
		insert(root->rchild, data);
	}
}

void preOrder(node* root, vector<int>& vi) {
	if (root == NULL) {
		return;
	}
	vi.push_back(root->data);
	preOrder(root->lchild, vi);
	preOrder(root->rchild, vi);
}

void preOrderMirror(node* root, vector<int>& vi) {
	if (root == NULL) {
		return;
	}
	vi.push_back(root->data);
	preOrderMirror(root->rchild, vi);
	preOrderMirror(root->lchild, vi);
}

void postOrder(node* root, vector<int>& vi) {
	if (root == NULL) {
		return;
	}
	postOrder(root->lchild, vi);
	postOrder(root->rchild, vi);
	vi.push_back(root->data);
}


void postOrderMirror(node* root, vector<int>& vi) {
	if (root == NULL) {
		return;
	}
	postOrderMirror(root->rchild, vi);
	postOrderMirror(root->lchild, vi);
	vi.push_back(root->data);
}

vector<int> origin, pre, preM, post, postM;

int main() {
	int n;
	node* root = NULL;
	scanf("%d", &n);
	int data;
	for (int i = 0; i < n; i++) {
		scanf("%d", &data);
		origin.push_back(data);
		insert(root, data);
	}
	preOrder(root, pre);
	preOrderMirror(root, preM);
	postOrder(root, post);
	postOrderMirror(root, postM);
	if (origin == pre) {
		printf("YES\n");
		for (int i = 0; i < post.size(); i++) {
			if (i != 0) {
				printf(" ");
			}
			printf("%d", post[i]);
		}
	}
	else if (origin == preM) {
		printf("YES\n");
		for (int i = 0; i < postM.size(); i++) {
			if (i != 0) {
				printf(" ");
			}
			printf("%d", postM[i]);
		}
	}
	else {
		printf("NO");
	}
	system("pause");
	return 0;
}
