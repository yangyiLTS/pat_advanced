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

struct Station {
	double distance;
	double price;
} s[501];

bool cmp(Station a, Station b) {
	return a.distance < b.distance;
}

int main() {
	double cmax, d, davg;
	int n;
	scanf("%lf%lf%lf%d", &cmax, &d, &davg, &n);
	for (int i = 0; i < n; i++) {
		scanf("%lf%lf", &s[i].price, &s[i].distance);
	}
	s[n].price = 0.00;
	s[n].distance = d;
	sort(s, s + n, cmp);
	if (s[0].distance != 0) {
		printf("The maximum travel distance = 0.00\n");
		return 0;
	}
	double now_gas = 0.00;
	double MAX = cmax * davg;
	double max_dis = now_gas * davg;
	double ans = 0;
	int now = 0;
	while (now < n) {
		int k = -1;
		double min_price = 10000000000;
		for (int i = now + 1; i <= n&&s[i].distance - s[now].distance <= MAX; i++) {
			if (s[i].price < min_price) {
				min_price = s[i].price;
				k = i;
				if (min_price < s[now].price) {
					break;
				}
			}
		}
		if (k == -1) {
			break;
		}
		double need = (s[k].distance - s[now].distance) / davg;
		if (min_price < s[now].price) {
			ans += (need - now_gas) * s[now].price;
			now_gas = 0;
		}
		else {
			ans += (cmax - now_gas) * s[now].price;
			now_gas = cmax - need;
		}
		now = k;
	}

	if (now == n) {
		printf("%.2f", ans);
	}
	else {
		printf("The maximum travel distance = %.2f", s[now].distance + MAX);
	}

	system("pause");
	return 0;
}

