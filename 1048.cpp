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
	int n, m;
	int coin[1001] = { 0 };
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		coin[a]++;
	}
	bool pflag = 0;
	for (int i = 1; i < m; i++) {
		if (i != m-i?(coin[i] > 0&&coin[m-i]>0):(coin[i] >= 2)) {
			printf("%d %d", i, m - i);
			pflag = 1;
			break;
		}
	}
	if(!pflag){
		printf("No Solution");
	}
	system("pause");
	return 0;
}

