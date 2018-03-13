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
	int lastFloor = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);
		if (a > lastFloor) {
			ans += (a - lastFloor) * 6;
		}
		else {
			ans += (lastFloor - a) * 4;
		}
		lastFloor = a;
		ans += 5;
	}
	printf("%d", ans);


	system("pause");
	return 0;
}



