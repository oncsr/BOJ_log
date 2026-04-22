#include <iostream>
#include <queue>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	bool block[100001]{};
	int N, M, A, B;
	cin >> N >> M >> A >> B;
	for (; M--;) {
		int l, r;
		cin >> l >> r;
		for (int i = l; i <= r; i++)	block[i] |= 1;
	}
	
	queue<pair<int, int> > Q;
	if (!block[A])	block[A] |= 1, Q.push({ A,1 });
	if (!block[B])	block[B] |= 1, Q.push({ B,1 });
	while (!Q.empty()) {
		int now = Q.front().first;
		int cnt = Q.front().second;
		Q.pop();
		if (now == N) {
			cout << cnt;
			return 0;
		}
		if (now + A <= N && !block[now + A]) {
			Q.push({ now + A, cnt + 1 });
			block[now + A] |= 1;
		}
		if (now + B <= N && !block[now + B]) {
			Q.push({ now + B, cnt + 1 });
			block[now + B] |= 1;
		}
	}
	cout << -1;
}