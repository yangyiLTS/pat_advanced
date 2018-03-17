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



int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &number[i]);
	}

	sort(number, number + n);
	int mid = n / 2 + n % 2 - 1;
	printf("%d",number[mid]);
	system("pause");
	return 0;
}
