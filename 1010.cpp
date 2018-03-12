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


typedef long long ll;

ll Map[256];
ll inf = (1ll << 63) - 1; //longlong的最大值是2^63-1，先将1移位再减一

void init() {
	for (char c = '0'; c <= '9'; c++) {
		Map[c] = c - '0';
	}
	for (char c = 'a'; c <= 'z'; c++) {
		Map[c] = c - 'a' + 10;
	}
}

ll covertNum10(char a[], ll radix, ll t) {
	int len = strlen(a);
	ll ans = 0;
	for (int i = 0; i < len; i++) {
		ans = ans *radix + Map[a[i]];
		if (ans < 0 || ans > t) {
			return -1;
		}
	}
	return ans;
}

int cmp(char N2[], ll radix, ll t) {
	int len = strlen(N2);
	ll num = covertNum10(N2, radix, t);
	if (num < 0) 
		return 1;
	if (num < t)
		return -1;
	else if (t == num)
		return 0;
	else
		return 1;
} 

ll binartSearch(char N2[], ll left, ll right, ll t) {
	ll mid;
	while (left <= right) {
		mid = (left + right) / 2;
		int flag = cmp(N2, mid, t);
		if (flag == 0)
			return mid;
		else if (flag == -1)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}

int findLargestDigit(char N2[]) {
	int ans = -1, len = strlen(N2);
	for (int i = 0; i < len; i++) {
		if (Map[N2[i]] > ans) {
			ans = Map[N2[i]];
		}
	}
	return ans + 1;
}

char N1[20], N2[20], temp[20];
int tag, radix;

int main() {
	init();
	scanf("%s %s %d %d", N1, N2, &tag, &radix);
	if (tag == 2) {
		strcpy(temp, N1);
		strcpy(N1, N2);
		strcpy(N2, temp);
	}
	ll t = covertNum10(N1, radix, inf);
	ll low = findLargestDigit(N2);
	ll high = max(low, t) + 1;
	ll ans = binartSearch(N2, low, high, t);
	if (ans == -1) {
		printf("Impossible\n");
	}
	else {
		printf("%lld\n", ans);
	}
	system("pause");
	return 0;
}