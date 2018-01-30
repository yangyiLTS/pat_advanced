#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
// #include <iomanip>
#include <stdlib.h>
#include <string>
#include <map>
using namespace std;
typedef long long ll;

int main() {
	float ans = 1;
	char bestBet[3];
	for (int i = 0; i < 3; i++) {
		float odd = 0;
		for (int j = 0; j < 3; j++) {
			float temp;
			cin >> temp;
			if (temp > odd) {
				switch (j)
				{
				case 0:bestBet[i] = 'W'; break;
				case 1:bestBet[i] = 'T'; break;
				case 2:bestBet[i] = 'L'; break;
				default:
					break;
				}
				odd = temp;
			}
		}
		ans *= odd;
	}

	float res = (ans*0.65 - 1.0) * 2.0;
	printf("%c %c %c %0.2f", bestBet[0], bestBet[1], bestBet[2], res);
	system("pause");
	return 0;
}
