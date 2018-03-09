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
#include <map>
#include <stack>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int left = n - 1;
	int pos[100010];
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		pos[a] = i;
		if (a != 0 && a == i) {
			left--;
		}
	}
	int k = 1,res = 0;
	for (int i = 0; i < left; i++) {
		if (pos[0] == 0) {
			for (int j = k; j < n; j++) {
				if (pos[j] != j) {
					k = j;
					swap(pos[0], pos[j]);
					res++;
					break;
				}
			}
		}
		if (pos[0] != 0) {
			swap(pos[pos[0]], pos[0]);
			res++;
		}
	}
	printf("%d", res);
	system("pause");
	return 0;
}

//10 3 5 7 2 6 4 9 0 8 1
//5 0 1 2 3 4
//5 1 2 3 4 0
//9 0 2 1 4 3 6 5 8 7