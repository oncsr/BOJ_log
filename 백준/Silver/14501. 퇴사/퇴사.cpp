#include <iostream>
using namespace std;

int T[16], P[16]{}, N, mx = 0;

void D(int now, int end, int val) {
	if (now > N) {
		mx = max(mx, val);
		return;
	}
	if (now > end && now + T[now] - 1 <= N)	D(now + 1, now + T[now] - 1, val + P[now]);
	D(now + 1, end, val);
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)	cin >> T[i] >> P[i];
	D(1, 0, 0);
	cout << mx;
}