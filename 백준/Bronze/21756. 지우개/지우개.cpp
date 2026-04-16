#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n;
	cin >> n;
	queue<int> q;
	for (int i = 1; i <= n; i++)	q.push(i);
	while (q.size() > 1) {
		queue<int> nq;
		int x = 0;
		while (!q.empty()) {
			if (x)	nq.push(q.front());
			q.pop();
			x ^= 1;
		}
		q = nq;
	}
	cout << q.front();

}