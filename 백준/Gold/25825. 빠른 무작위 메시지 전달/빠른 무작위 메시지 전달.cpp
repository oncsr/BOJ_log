#include <bits/stdc++.h>
using namespace std;

int arr[12][12]{};
int ans = 1e9;

void sol(int now, int rem, int state, int cost) {
	int next;
	if (rem) {
		next = ((now & 1) ? now - 1 : now + 1);
		sol(next, 0, state, cost + arr[now][next]);
	}
	else {
		state |= (1 << (now >> 1));
		if (state == 63) {
			ans = min(ans, cost);
			return;
		}
		for (int i = 0; i < 6; i++) {
			if (state & (1 << i))	continue;
			next = i << 1;
			sol(next, 1, state, cost + arr[now][next]);
			sol(next + 1, 1, state, cost + arr[now][next + 1]);
		}
	}

}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	for (int i = 0; i < 12; i++)	for (int j = 0; j < 12; j++)	cin >> arr[i][j];
	for (int i = 0; i < 12; i++)	sol(i, 1, 0, 0);

	cout << ans;

}