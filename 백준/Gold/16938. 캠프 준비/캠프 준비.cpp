#include <bits/stdc++.h>
using namespace std;

int arr[15]{}, N, L, R, X, ans = 0;

void bck(int pos, int sum, int mx, int mn) {
	if (pos == N) {
		if (L <= sum && sum <= R && mx - mn >= X)	ans++;
		return;
	}
	bck(pos + 1, sum, mx, mn);
	bck(pos + 1, sum + arr[pos], max(mx, arr[pos]), min(mn, arr[pos]));
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N >> L >> R >> X;
	for (int i = 0; i < N; i++)	cin >> arr[i];
	bck(0, 0, 0, 1e9);
	cout << ans;

}