#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
// #include <iomanip>
#include <stdlib.h>
#include <cstring>
#include <map>
using namespace std;
typedef long long ll;

struct Student {
	char name[11];
	char gender;
	char id[11];
	int grade;
};


int main() {
	int N;
	scanf("%d", &N);
	Student maxFemale, minMale;
	maxFemale.grade = 0;
	minMale.grade = 100;
	bool Fflag = 0, Mflag = 0;
	for (int i = 0; i < N; i++) {
		Student a;
		scanf("%s %c %s %d", a.name, &a.gender, a.id, &a.grade);
		if (a.gender == 'M') {
			Mflag = 1;
			if (a.grade <= minMale.grade) {
				minMale = a;
			}
		}
		else if (a.gender == 'F') {
			Fflag = 1;
			if (a.grade >= maxFemale.grade) {
				maxFemale = a;
			}
		}
	}

	if (Fflag) {
		printf("%s %s\n", maxFemale.name, maxFemale.id);
	}
	else {
		printf("Absent\n");
	}

	if (Mflag) {
		printf("%s %s\n", minMale.name, minMale.id);
	}
	else {
		printf("Absent\n");
	}
	if (Fflag && Mflag) {
		printf("%d", maxFemale.grade - minMale.grade);
	}
	else {
		printf("NA");
	}

	system("pause");
	return 0;
}
