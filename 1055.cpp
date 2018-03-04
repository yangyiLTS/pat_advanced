// 运行超时
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

struct People {
	char name[9];
	int age;
	int worth;
}p[100010];

bool cmp_age(People a, People b) {
	return a.age < b.age;
}

bool cmp(People a, People b) {
	if (a.worth != b.worth) {
		return a.worth > b.worth;
	}
	else if (a.age != b.age) {
		return a.age < b.age;
	}
	else {
		return strcmp(a.name, b.name) <= 0;
	}
}

int binary_find1(const int a, const int b, const int val) {
	int c = (a + b) / 2;
	if (b - a == 1) {
		return a;
	}
	/*if (p[c].age == val) {
		return c;
	}*/
	if (p[c].age >= val) {
		binary_find1(a, c, val);
	}
	else if (p[c].age < val) {
		binary_find1(c, b, val);
	}
}

int binary_find2(const int a, const int b, const int val) {
	int c = (a + b) / 2;
	if (b - a == 1) {
		return b;
	}
	/*if (p[c].age == val) {
	return c;
	}*/
	if (p[c].age > val) {
		binary_find2(a, c, val);
	}
	else if (p[c].age <= val) {
		binary_find2(c, b, val);
	}
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%s %d %d", p[i].name, &p[i].age, &p[i].worth);
	}
	sort(p, p + n, cmp_age);
	People p2[100010];
	for (int i = 0; i < k; i++) {
		//scanf("%d %d %d", &query[i][0], &query[i][1], &query[i][2]);
		int m, amin, amax;
		bool flag = 0;
		scanf("%d %d %d", &m, &amin, &amax);
		printf("Case #%d:\n", i + 1);
		int head = n - 1, end = 0;
		for (int j = 0; j < n; j++) {
			if (m == 0) {
				break;
			}
			if (p[j].age < amin) {
				continue;
			}
			else if (p[j].age >= amin && p[j].age <= amax) {
				if (j <= head) {
					head = j;
					break;
				}
			}
		}
		for (int j = n - 1; j >= 0; j--) {
			if (m == 0) {
				break;
			}
			if (p[j].age > amax) {
				continue;
			}
			else if (p[j].age <= amax) {
				if (j >= end) {
					end = j;
					break;
				}
			}
		}

		/*head = binary_find1(0, n-1, amin);
		end = binary_find2(head, n-1, amax);
		if (p[end].age > amax) {
			end--;
		}*/
		int temp = head;
		if (head >= end) {
			printf("None\n");
			continue;
		}
		for (int i = head; i < end + 1; i++) {
			p2[i] = p[i];
		}
		sort(p2 + head, p2 + end + 1, cmp);
		for (; head <= end && m; head++) {
			flag = 1;
			printf("%s %d %d\n", p2[head].name, p2[head].age, p2[head].worth);
			m--;
		}
		if (!flag) {
			printf("None\n");
		}
	}

	system("pause");
	return 0;
}



