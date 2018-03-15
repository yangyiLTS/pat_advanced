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
#include <set>
using namespace std;
map<string, set<int> > mpTitle, mpAuthor, mpKey, mpPub, mpYear;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int id;
		cin >> id;
		char c = getchar();
		string title, author, pub, year;
		getline(cin, title);
		mpTitle[title].insert(id);
		getline(cin, author);
		mpAuthor[author].insert(id);
		string key;
		while (cin >> key) {
			mpKey[key].insert(id);
			c = getchar();
			if (c == '\n') {
				break;
			}
		}
		getline(cin, pub);
		mpPub[pub].insert(id);
		getline(cin, year);
		mpYear[year].insert(id);
	}

	int k;
	cin >> k;
	getchar();
	for (int i = 0; i < k; i++) {
		string s;
		getline(cin, s);
		cout << s << endl;
		char c = s[0];
		s.erase(0, 3);
		switch (c) {
		case '1': {
			if (mpTitle.find(s) == mpTitle.end()) {
				cout << "Not Found\n";
			}
			else {
				for (set<int>::iterator it = mpTitle[s].begin(); it != mpTitle[s].end(); it++) {
					printf("%07d\n", *it);
				}
			}
			break;
		}
		case '2': {
			if (mpAuthor.find(s) == mpAuthor.end()) {
				cout << "Not Found\n";
			}
			else {
				for (set<int>::iterator it = mpAuthor[s].begin(); it != mpAuthor[s].end(); it++) {
					printf("%07d\n", *it);
				}
			}
			break;
		}
		case '4': {
			if (mpPub.find(s) == mpPub.end()) {
				cout << "Not Found\n";
			}
			else {
				for (set<int>::iterator it = mpPub[s].begin(); it != mpPub[s].end(); it++) {
					printf("%07d\n", *it);
				}
			}
			break;
		}
		case '5': {
			if (mpYear.find(s) == mpYear.end()) {
				cout << "Not Found\n";
			}
			else {
				for (set<int>::iterator it = mpYear[s].begin(); it != mpYear[s].end(); it++) {
					printf("%07d\n", *it);
				}
			}
			break;
		}
		case '3': {
			if (mpKey.find(s) == mpKey.end()) {
				cout << "Not Found\n";
			}
			else {
				for (set<int>::iterator it = mpKey[s].begin(); it != mpKey[s].end(); it++) {
					printf("%07d\n", *it);
				}
			}
			break;
		}
		}
	}

	system("pause");
	return 0;
}
