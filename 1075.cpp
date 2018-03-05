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

struct User {
	int id;
	int problem_score[5] = { -1,-1,-1,-1,-1 };
	int total_score = 0;
	int perfect = 0;
	bool flag = 0;
} user[10010];

bool cmp(User a, User b) {
	if (!(a.flag && b.flag)) {
		return a.flag > b.flag;
	}
	else if (a.total_score != b.total_score) {
		return a.total_score > b.total_score;
	}
	else if (a.perfect != b.perfect) {
		return a.perfect > b.perfect;
	}
	else {
		return a.id < b.id;
	}
}

int main() {
	int n, k, m;
	scanf("%d%d%d", &n, &k, &m);
	n += 1;
	int p[5];
	for (int i = 0; i < k; i++) {
		scanf("%d", &p[i]);
	}
	for (int i = 0; i < m; i++) {
		int user_id, problem_id, score;
		scanf("%d%d%d", &user_id, &problem_id, &score);
		problem_id -= 1;
		user[user_id].id = user_id;
		if (score >= 0) {
			user[user_id].flag = 1;
		}
		if (user[user_id].problem_score[problem_id] == -1) {
			if (score == -1) {
				score = 0;
			}
			user[user_id].problem_score[problem_id] += score + 1;
		}
		else {
			if (score > user[user_id].problem_score[problem_id]) {
				user[user_id].problem_score[problem_id] = score;
			}
		}
		if (score > 0) {
			user[user_id].flag = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		if (user[i].flag) {
			for (int j = 0; j < k; j++) {
				if (user[i].problem_score[j] > -1) {
					user[i].total_score += user[i].problem_score[j];
					if (user[i].problem_score[j] == p[j]) {
						user[i].perfect++;
					}
				}
			}
		}
	}
	sort(user, user + n, cmp);
	int pre_rank = 1;
	for (int i = 0; i < n; i++) {
		if (!user[i].flag) {
			continue;
		}
		if (i == 0) {
			printf("1 ");
		}
		else {
			if (user[i].total_score != user[i - 1].total_score) {
				pre_rank = i + 1;
			}
			printf("%d ", pre_rank);
		}
		printf("%05d %d", user[i].id, user[i].total_score);
		for (int j = 0; j < k; j++) {
			if (user[i].problem_score[j] == -1) {
				printf(" -");
			}
			else {
				printf(" %d", user[i].problem_score[j]);
			}
		}
		printf("\n");
	}

	system("pause");
	return 0;
}

/*
4 3 8
20 30 40
00001 1 15
00001 3 20
00002 2 0
00002 3 0
00003 1 20
00003 2 15
00004 1 -1
00004 3 -1
*/