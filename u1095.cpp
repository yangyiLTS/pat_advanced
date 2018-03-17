#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <algorithm>
// #include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <stack>

using namespace std;

struct Time {
	int h;
	int m;
	int s;
	int timestamp = h * 3600 + m * 60 + s;
};

Time inputTime() {
	Time a;
	scanf("%d:%d:%d", &a.h, &a.m, &a.s);
}

struct Car {
	int flag;
	char plate[8];
	Time in, out;
	int parktime = 0;
};

bool cmp_time(Time a, Time b) {
	return a.timestamp < b.timestamp;
}

int main() {
	int n, k;
	scanf("%d%d", &n, &k);


	system("pause");
	return 0;
}

