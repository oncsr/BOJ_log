#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, P;
	cin >> N;
	P = 2 * N;

	int vis[2985984]{};
	int start = 0, g = 1, dest = 0;
	for (int i = 0; i < N; i++) {
		int a;
		char b;
		cin >> a >> b;
		int r = a - 1;
		if (b == '-')	r += N;
		start += r * g;
		dest += i * g;
		g *= P;
	}
	queue<pair<int, int>> Q;
	Q.emplace(start, 0);
	vis[start]++;
	while (!Q.empty()) {
		auto [now, t] = Q.front();
		Q.pop();
		if (now == dest) { cout << t; return 0; }
		int L = g / P, temp = now;
		int arr[6]{};
		for (int i = N - 1; i >= 0; i--) {
			arr[i] = (temp / L);
			temp -= L * arr[i];
			L /= P;
		}

		for (int i = 0; i < N; i++) {
			int next = 0, q = 1;
			for (int j = 0; j < N; j++) {
				int r = 0;
				if (j <= i) {
					r = arr[i - j];
					if (r >= N)	r -= N;
					else	r += N;
				}
				else	r = arr[j];
				next += r * q;
				q *= P;
			}
			if (!vis[next]) {
				Q.emplace(next, t + 1);
				vis[next]++;
			}
		}
	}

}