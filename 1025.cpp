#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <algorithm>
// #include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <map>

using namespace std;

struct Testee {
	char id[15];
	int score;
	int location;
	int localrank;
} testees[30010];

bool cmp(Testee a, Testee b) {
	if (a.score != b.score) {
		return a.score > b.score;
	}
	else {
		return strcmp(a.id, b.id) < 0;
	}
}

int main() {
	int N;
	scanf("%d", &N);
	int count = 0;
	for (int i = 0; i < N; i++) {
		int K;
		scanf("%d", &K);
		for (int j = 0; j < K; j++) {
			scanf("%s %d", &testees[count].id, &testees[count].score);
			testees[count].location = i + 1;
			count++;
		}
		sort(testees + count - K, testees + count, cmp);
		for (int j = 0; j < K; j++) {
			if (j != 0 && testees[count - K + j].score == testees[count - K + j - 1].score) {
				testees[count - K + j].localrank = testees[count - K + j - 1].localrank;
			}
			else {
				testees[count - K + j].localrank = j + 1;
			}
		}
	}

	sort(testees, testees + count, cmp);
	printf("%d\n", count);
	int rank = 1;
	for (int i = 0; i < count; i++) {
		if (i > 0 && testees[i].score != testees[i - 1].score){
			rank = i + 1;
		}
		printf("%s %d %d %d\n", testees[i].id, rank, testees[i].location, testees[i].localrank);
	}
	system("pause");
	return 0;
}
