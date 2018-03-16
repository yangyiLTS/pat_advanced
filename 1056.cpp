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

using namespace std;

struct Mouse {
	int weight;
	int rank;
} mouse[1010];

int main() {
	int np, ng;
	scanf("%d%d", &np, &ng);
	for (int i = 0; i < np; i++) {
		int w;
		scanf("%d", &w);
		mouse[i].weight = w;
	}
	queue<int> q;
	for (int i = 0; i < np; i++) {
		int order;
		scanf("%d", &order);
		q.push(order);
	}
	int temp = np, group;
	while (q.size() != 1) {
		group = temp%ng == 0 ? temp / ng : temp / ng + 1;
		for (int i = 0; i < group; i++) {
			int k = q.front();
			for (int j = 0; j < ng; j++) {
				if (i*ng + j >= temp) {
					break;
				}
				int front = q.front();
				if (mouse[front].weight > mouse[k].weight) {
					k = front;
				}
				mouse[front].rank = group + 1;
				q.pop();
			}
			q.push(k);
		}
		temp = group;
	}
	mouse[q.front()].rank = 1;
	for (int i = 0; i < np; i++) {
		if (i) {
			printf(" ");
		}
		printf("%d", mouse[i].rank);
	}

	system("pause");
	return 0;
}
