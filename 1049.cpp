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
	int a = 1;
	int ans = 0;
	scanf("%d", &n);
	int left, now, right;
	while (n / a != 0) {
		left = n / (a * 10);
		now = n / a % 10;
		right = n%a;
		if (now == 0) {
			ans += left*a;
		}
		else if (now == 1) {
			ans += left*a + right + 1;
		}
		else {
			ans += (left + 1)*a;
		}
		a *= 10;
	}
	printf("%d", ans);
	system("pause");
	return 0;
}