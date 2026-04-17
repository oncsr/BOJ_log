#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	cin >> N >> M;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> Q1, Q2;
	int cur[200001]{};
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		cur[i] = a;
		Q1.emplace(a, i);
	}
	for (int i = N + 1; i <= N + M; i++) {
		int a;
		cin >> a;
		cur[i] = a;
		Q2.emplace(a, i);
	}

	int K;
	for (cin >> K; K--;) {
		char o;
		cin >> o;
		int a, b;
		if (o == 'L') {
			while (Q1.top().first != cur[Q1.top().second])	Q1.pop();
			a = Q1.top().second;
			while (Q2.top().first != cur[Q2.top().second])	Q2.pop();
			b = Q2.top().second;
			cout << a << ' ' << b << '\n';
		}
		else {
			cin >> a >> b;
			cur[a] = b;
			if (a <= N)	Q1.emplace(b, a);
			else	Q2.emplace(b, a);
		}
	}

}