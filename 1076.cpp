#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int maxv = 1010;
struct Node {
	int id;
	int layer;
};

vector<Node> Adj[maxv];
bool inq[maxv] = { 0 };

int BFS(int s, int L) {
	int numForward = 0;
	queue<Node> q;
	Node start;
	start.id = s;
	start.layer = 0;
	q.push(start);
	inq[start.id] = true;
	while (!q.empty()) {
		Node top = q.front();
		q.pop();
		int u = top.id;
		for (int i = 0; i < Adj[u].size(); i++) {
			Node next = Adj[u][i];
			next.layer = top.layer + 1;
			if(inq[next.id] == false && next.layer <= L) {
				q.push(next);
				inq[next.id] = true;
				numForward++;
			}
		}
	}
	return numForward;
}

int main() {
	Node user;
	int n, L;
	scanf("%d%d", &n, &L);
	int numFollow, idFollow;
	for (int i = 1; i <= n; i++) {
		user.id = i;
		scanf("%d", &numFollow);
		for (int j = 0; j < numFollow; j++) {
			scanf("%d", &idFollow);
			Adj[idFollow].push_back(user);
		}
	}

	int k, s;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		memset(inq, false, sizeof(inq));
		scanf("%d", &s);
		int numFoward = BFS(s, L);
		printf("%d\n", numFoward);
	}

	return 0;
}