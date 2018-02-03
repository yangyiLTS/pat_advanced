#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
// #include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <map>

using namespace std;
char num[10][5] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };
char wei[5][5] = { "Shi","Bai","Qian","Wan","Yi" };

int main() {
	char str[15];
	scanf("%s",str);
	int len = strlen(str);
	int left = 0, right = len - 1;
	if (str[0] == '-') {
		printf("Fu");
		left++;
	}
	while (left + 4 <= right) {
		right -= 4;
	}
	while (left < len) {
		bool flag = 0;
		bool isPrint = 0;
		while (left <= right) {
			if (left > 0 && str[left] == '0') {
				flag = 1;
			}
			else {
				if (flag) {
					printf(" ling");
					flag = 0;
				}
				if (left > 0) {
					printf(" ");
				}
				printf("%s", num[str[left] - '0']);
				isPrint = 1;
				if (left != right) {
					printf(" %s", wei[right - left - 1]);
				}
			}
			left++;
		}
		if (isPrint && right != len - 1) {
			printf(" %s", wei[(len - 1 - right) / 4 + 2]);
		}
		right += 4;
	}
	system("pause");
	return 0;
}
