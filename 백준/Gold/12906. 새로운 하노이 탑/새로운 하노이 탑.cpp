#include <iostream>
#include <tuple>
#include <queue>
#include <map>
using namespace std;
using node = tuple<string, string, string>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, A = 0, B = 0, C = 0;
	string ta, tb, tc;
	for (int i = 0; i < 3; i++) {
		string s;
		cin >> n;
		if (!n)	continue;
		cin >> s;
		if (i == 0)	ta = s;
		if (i == 1)	tb = s;
		if (i == 2)	tc = s;
		for (char j : s) {
			A += j == 'A';
			B += j == 'B';
			C += j == 'C';
		}
	}
	node res = { ta, tb, tc };
	string TA = "", TB = "", TC = "";
	for (int i = 0; i < A; i++)	TA += 'A';
	for (int i = 0; i < B; i++)	TB += 'B';
	for (int i = 0; i < C; i++)	TC += 'C';
	node start = { TA, TB, TC };
	
	map<node, bool> visit;
	queue<pair<node, int> > Q;
	Q.push({ start, 0 });
	visit[start] = true;
	while (!Q.empty()) {
		node now = Q.front().first;
		int cnt = Q.front().second;
		Q.pop();
		if (now == res) {
			cout << cnt;
			return 0;
		}
		string a, b, c;
		tie(a, b, c) = now;
		if (a.size()) {
			string temp = a.substr(0, a.size() - 1);
			node next = { temp, b + a.back(), c };
			if (!visit[next]) {
				visit[next] = true;
				Q.push({ next, cnt + 1 });
			}
			next = { temp, b, c + a.back() };
			if (!visit[next]) {
				visit[next] = true;
				Q.push({ next, cnt + 1 });
			}
		}
		if (b.size()) {
			string temp = b.substr(0, b.size() - 1);
			node next = { a + b.back(), temp, c };
			if (!visit[next]) {
				visit[next] = true;
				Q.push({ next, cnt + 1 });
			}
			next = { a, temp, c + b.back() };
			if (!visit[next]) {
				visit[next] = true;
				Q.push({ next, cnt + 1 });
			}
		}
		if (c.size()) {
			string temp = c.substr(0, c.size() - 1);
			node next = { a + c.back(), b, temp };
			if (!visit[next]) {
				visit[next] = true;
				Q.push({ next, cnt + 1 });
			}
			next = { a, b + c.back(),temp };
			if (!visit[next]) {
				visit[next] = true;
				Q.push({ next, cnt + 1 });
			}
		}
	}
}