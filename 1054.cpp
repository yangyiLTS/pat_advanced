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
#include <vector>
using namespace std;

map <int, int> mp;

int main() {
	int m, n;
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int c;
			scanf("%d", &c);
			mp[c]++;
		}
	}

	int dcolor, maxnum = 0;
	for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
		if (it->second > maxnum) {
			dcolor = it->first;
			maxnum = it->second;
		}
	}
	printf("%d", dcolor);

	system("pause");
	return 0;
}
