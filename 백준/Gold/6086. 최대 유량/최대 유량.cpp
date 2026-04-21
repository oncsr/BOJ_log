#include <bits/stdc++.h>
using namespace std;

int N;
int capacity[52][52]{}, flow[52][52]{};

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		char a, b;
		int c;
		cin >> a >> b >> c;
		int A = (a <= 90 ? a - 'A' + 26 : a - 'a');
		int B = (b <= 90 ? b - 'A' + 26 : b - 'a');
		capacity[A][B] += c;
		capacity[B][A] += c;
	}
	int ans = 0;

	while (1) {
		// 증가 경로 찾기
		vector<int> par(52, -1);
		queue<int> Q;
		Q.push(26);
		while (!Q.empty()) {
			int now = Q.front();
			Q.pop();
			if (now == 51)	break;
			for (int next = 0; next < 52; next++) {
				if (next == 26)	continue;
				if (par[next] != -1)	continue;
				int F = flow[now][next], C = capacity[now][next];
				if (C - F > 0) {
					Q.push(next);
					par[next] = now;
				}
			}
		}
		if (par[51] == -1)	break;	// 더 이상 증가 경로가 없는 경우

		// 보낼 유량 계산하기
		int c = 1e9;
		for (int now = 51; par[now] != -1; now = par[now])
			c = min(c, capacity[par[now]][now] - flow[par[now]][now]);

		// 유량 흘리기
		for (int now = 51; par[now] != -1; now = par[now]) {
			flow[par[now]][now] += c;
			flow[now][par[now]] -= c;
		}
		ans += c;
	}
	cout << ans;
}