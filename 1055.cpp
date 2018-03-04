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
	if (a.age != b.age) {
		return a.age < b.age;
	}
	else {
		return  a.worth > b.worth;
	}
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

struct Age {
	int head = -1;
	int end = -1;
} age_list[202];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%s %d %d", p[i].name, &p[i].age, &p[i].worth);
	}
	sort(p, p + n, cmp_age);
	int age_temp = p[0].age, count = 1;
	for (int i = 1; i < n; i++) {
		if (p[i].age == age_temp) {
			count++;
			if (count > 101) {
				p[i].age == 300;
			}
		}
		else {
			count = 0;
			age_temp = p[i].age;
		}
	}

	sort(p, p + n, cmp_age);
	for (int i = 0; i < n; i++) {
		if (p[i].age > 200) {
			n = i;
			break;
		}
	}
	sort(p , p + n, cmp);
	/*People p2[100010];
	int now_age = 0;
	for (int i = 0; i < n; i++) {
		if (p[i].age > now_age) {
			age_list[p[i].age].head = i;
			age_list[p[i].age].end = i;
			now_age = p[i].age;
		}
		else if (p[i].age = now_age) {
			age_list[p[i].age].end = i;
		}
	}

	age_list[0].head = 0;
	age_list[0].end = 0;
	age_list[201].head = n - 1;
	age_list[201].end = n - 1;
	int pre_age = 0, next_age = 201;
	for (int i = 1; i <= 200; i++) {
		if (age_list[i].end >= 0) {
			pre_age = i;
			continue;
		}
		else if (age_list[i].end == -1) {
			age_list[i].end = age_list[pre_age].end;
		}
	}

	for (int i = 200; i > 0; i--) {
		if (age_list[i].head >= 0) {
			next_age = i;
			continue;
		}
		else if (age_list[i].head == -1) {
			age_list[i].head = age_list[next_age].head;
		}
	}
	*/
	for (int i = 0; i < k; i++) {
		int m, amin, amax;
		bool flag = 0;
		scanf("%d %d %d", &m, &amin, &amax);
		printf("Case #%d:\n", i + 1);
		//int head = n - 1, end = 0;
		/*for (int j = 0; j < n; j++) {
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
		}*/

		/*head = binary_find1(0, n-1, amin);
		end = binary_find2(head, n-1, amax);
		if (p[end].age > amax) {
			end--;
		}*/

		//head = age_list[amin].head;
		/*while (head == -1 && amin <= 200) {
			amin++;
			head = age_list[amin].head;
		}*/
		//end = age_list[amax].end;
		/*while (end == -1 && amax > 1) {
			amax--;
			end = age_list[amax].end;
		}*/

		/*int temp = head;
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
		}*/
		int pcount = 0;
		for (int i = 0; i < n&&pcount < m; i++) {
			if (p[i].age >= amin && p[i].age <= amax) {
				printf("%s %d %d\n", p[i].name, p[i].age, p[i].worth);
				pcount++;
			}
		}
		if (pcount == 0) {
			printf("None\n");
		}
	}

	system("pause");
	return 0;
}

