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

using namespace std;

struct Node {
	int adress;
	int data;
	int next;
	int flag = 0;
} linkList[100010];

bool cmp(Node a, Node b) {
	if (a.flag != b.flag) {
		return a.flag > b.flag;
	}
	else {
		return a.data < b.data;
	}
}

int main() {
	int n, begin;
	scanf("%d %d", &n, &begin);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		scanf("%d%d", &linkList[a].data, &linkList[a].next);
		linkList[a].adress = a;
	}
	int p = begin;
	int count = 0;
	for (int i = 0; i < n&&p != -1; i++) {
		linkList[p].flag = 1;
		p = linkList[p].next;
		count++;
	}

	sort(linkList, linkList + 100010, cmp);
	if (count == 0) {
		printf("0 -1");
	}
	else {
		printf("%d %05d\n", count, linkList[0].adress);
		for (int i = 0; i < count; i++) {
			printf("%05d %d ", linkList[i].adress, linkList[i].data);
			if (i == count - 1) {
				printf("-1\n");
			}
			else {
				printf("%05d\n", linkList[i + 1].adress);
			}
		}
	}
	system("pause");
	return 0;
}

/*
6 00001
11111 100 -1
00001 0 22222
33333 100000 11111
12345 -1 33333
22222 1000 12345
23452 93 34151
*/