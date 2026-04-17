#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	int mn = 1e9, mx = 0;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		mn = min(mn, a);
		mx = max(mx, a - mn);
		cout << mx << ' ';
	}

}