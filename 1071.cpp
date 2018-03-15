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

bool check(char c) {
	if (c >= 'a'&&c <= 'z')
		return 1;
	if (c >= 'A'&&c <= 'Z')
		return 1;
	if (c >= '0'&&c <= '9')
		return 1;
	return 0;
}

int main() {
	map<string, int> mp;
	string str;
	getline(cin, str);
	int i = 0;
	while (i < str.length()) {
		string word;
		while (i < str.length() && check(str[i])) {
			if (str[i] >= 'A'&&str[i] <= 'Z') {
				str[i] += 32;
			}
			word += str[i];
			i++;
		}
		if (word != "") {
			if (mp.find(word) == mp.end()) {
				mp[word] = 1;
			}
			else {
				mp[word]++;
			}
		}
		while (i < str.length() && !check(str[i])) {
			i++;
		}
	}
	int max = 0;
	string ans;
	for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++) {
		if (it->second > max) {
			ans = it->first;
			max = it->second;
		}
	}
	cout << ans << ' ' << max;

	system("pause");
	return 0;
}
