#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N, mx = 0, a, b, d[10001]{}, val[10001]{}, r[10001]{};
	vector<vector<int> > V(10001);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> val[i];
		for (cin >> a; a--;) {
			cin >> b;
			d[i]++;
			V[b].push_back(i);
		}
	}
	queue<int> Q;
	for (int i = 1; i <= N; i++) {
		if (!d[i])	Q.push(i);
		r[i] = val[i];
		mx = max(r[i], mx);
	}
	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();
		for (int i : V[now]) {
			r[i] = max(r[i], r[now] + val[i]);
			mx = max(r[i], mx);
			if (!(--d[i]))	Q.push(i);
		}
	}
	cout << mx;
}