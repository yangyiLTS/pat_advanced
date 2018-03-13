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

struct Fraction {
	int up;
	int down;
};

Fraction add(Fraction a, Fraction b) {
	Fraction ans;
	ans.up = a.up*b.down + a.down*b.up;
	ans.down = a.down*b.down;
	return ans;
}

//Fraction minus(Fraction a, Fraction b) {
//	Fraction ans;
//	ans.up = a.up*b.down - a.down*b.up;
//	ans.down = a.down*b.down;
//	return ans;
//}

int gcd(int a, int b) {
	return !b ? a : gcd(b, a%b);
}

Fraction simplify(Fraction a) {
	int g;
	g = gcd(a.up, a.down);
	a.up /= g;
	a.down /= g;
	return a;
}

int main() {
	int n;
	scanf("%d", &n);
	Fraction ans = { 0,1 };
	for (int i = 0; i < n; i++) {
		Fraction a;
		scanf("%d/%d", &a.up, &a.down);
		ans = simplify(add(ans, a));
	}
	if (ans.up < 0) {
		printf("-");
		ans.up *= -1;
	}

	if (ans.up == 0) {
		printf("0");
	}
	else if (ans.up < ans.down) {
		printf("%d/%d", ans.up, ans.down);
	}
	else {
		if (ans.up%ans.down) {
			printf("%d %d/%d", ans.up / ans.down, ans.up%ans.down, ans.down);
		}
		else {
			printf("%d", ans.up / ans.down);
		}
	}

	system("pause");
	return 0;
}