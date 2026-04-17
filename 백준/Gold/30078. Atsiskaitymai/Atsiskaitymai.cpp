#include <bits/stdc++.h>
using namespace std;

struct cmp {
	bool operator()(int b, int a) {
		return abs(a) < abs(b);
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N, s = 0, mx = 0;
	cin >> N;
	priority_queue<int, vector<int>, cmp> Q;
	for (; N--;) {
		int a, b;
		cin >> a >> b;
		Q.push(a), Q.push(-b);
	}
	while (!Q.empty()) {
		int now = abs(Q.top());
		while (!Q.empty() && abs(Q.top()) == now) {
			s += Q.top() > 0 ? 1 : -1;
			Q.pop();
		}
		mx = max(mx, s);
	}
	cout << mx;

}