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

bool cmp(int a, int b) {
	if (a >= 0 && b >= 0) {
		return a > b;
	}
	else if (a < 0 && b < 0) {
		return a < b;
	}
	else {
		return a > b;
	}

}

int main() {
	int nc, np;
	int c[100010], p[100010];
	scanf("%d", &nc);
	for (int i = 0; i < nc; i++) {
		scanf("%d", &c[i]);
	}
	scanf("%d", &np);
	for (int i = 0; i < np; i++) {
		scanf("%d", &p[i]);
	}
	sort(c, c + nc, cmp);
	sort(p, p + np, cmp);

	int cp[100010], cn[100010];
	int pp[100010], pn[100010];
	int ca = 0, cb = 0;
	for (int i = 0; i < nc; i++) {
		if (c[i] > 0) {
			cp[ca++] = c[i];
		}
		else if (c[i] < 0) {
			cn[cb++] = c[i];
		}
	}

	int pa = 0, pb = 0;
	for (int i = 0; i < nc; i++) {
		if (p[i] > 0) {
			pp[pa++] = p[i];
		}
		else if (p[i] < 0) {
			pn[pb++] = p[i];
		}
	}
	int res = 0;
	for (int i = 0; i < ca&&i < pa; i++) {
		res += cp[i] * pp[i];
	}
	for (int i = 0; i < cb&&i < pb; i++) {
		res += cn[i] * pn[i];
	}

	printf("%d", res);

	system("pause");
	return 0;
}

