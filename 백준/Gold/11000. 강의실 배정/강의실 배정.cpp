#include <bits/stdc++.h>
using namespace std;

struct cmp { bool operator()(int b, int a) { return abs(a) < abs(b); } };

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, mx = 0, s = 0;
	priority_queue<int, vector<int>, cmp> Q;
	for (cin >> N; N--;) {
		int a, b;
		cin >> a >> b;
		Q.push(a);	Q.push(-b);
	}
	while (!Q.empty()) {
		int now = abs(Q.top());
		for (; !Q.empty() && now == abs(Q.top()); Q.pop())	s += (Q.top() >= 0 ? 1 : -1);
		mx = max(mx, s);
	}
	cout << mx;

}