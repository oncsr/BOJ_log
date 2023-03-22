#include <iostream>
#include <queue>
using namespace std;
using ii = pair<int, int>;

int main() {
	int N, K, L, map[100][100]{}, a, b, s = 0, dir = 1;
	for (cin >> N >> K; K--;) {
		cin >> a >> b;
		map[a - 1][b - 1] = 1;
	}
	char d;
	
	queue<ii> Q;
	Q.push({ 0,0 });
	for (cin >> L; L--;) {
		cin >> a >> d;
		while (s < a) {
			ii now = Q.back();
			if (dir == 1)	now.second++;
			else if (dir == 2)	now.first++;
			else if (dir == 3)	now.second--;
			else	now.first--;
			s++;
			if (now.first >= N || now.first < 0 || now.second >= N || now.second < 0) {
				cout << s;
				return 0;
			}
			if (map[now.first][now.second] == 2) {
				cout << s;
				return 0;
			}
			Q.push(now);
			if (map[now.first][now.second] != 1) {
				ii tail = Q.front();
				map[tail.first][tail.second] = 0;
				Q.pop();
			}
			map[now.first][now.second] = 2;
		}
		if (d == 'D')	dir++;
		else	dir--;
		if (dir > 4)	dir = 1;
		else if (dir < 1)	dir = 4;
	}
	while (s) {
		ii now = Q.back();
		if (dir == 1)	now.second++;
		else if (dir == 2)	now.first++;
		else if (dir == 3)	now.second--;
		else	now.first--;
		s++;
		if (now.first >= N || now.first < 0 || now.second >= N || now.second < 0) {
			cout << s;
			return 0;
		}
		if (map[now.first][now.second] == 2) {
			cout << s;
			return 0;
		}
		Q.push(now);
		if (map[now.first][now.second] != 1) {
			ii tail = Q.front();
			map[tail.first][tail.second] = 0;
			Q.pop();
		}
		map[now.first][now.second] = 2;
	}
	

	cout << s;
}