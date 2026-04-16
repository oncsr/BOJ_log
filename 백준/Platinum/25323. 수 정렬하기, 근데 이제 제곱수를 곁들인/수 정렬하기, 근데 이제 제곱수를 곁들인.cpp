#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	vector<ll> V(N);
	for (ll& i : V)	cin >> i;
	vector<ll> T = V;
	sort(T.begin(), T.end());

	vector<vector<ll>> B;
	vector<int> vis(N);
	vector<int> pos(N);
	iota(pos.begin(), pos.end(), 0);
	
	for (int i = 0; i < N; i++) {
		if (vis[i])	continue;
		if (V[i] != T[i]) {
			vector<ll> temp;
			vis[i]++;
			if (i != N - 1 && T[i] == T[i + 1])	pos[i]++;
			temp.push_back(T[i]);
			int x = lower_bound(T.begin(), T.end(), V[i]) - T.begin();
			x = pos[x];
			while (!vis[x]) {
				vis[x]++;
				if (x != N - 1 && T[x] == T[x + 1])	pos[x]++;
				temp.push_back(T[x]);
				x = lower_bound(T.begin(), T.end(), V[x]) - T.begin();
				x = pos[x];
			}
			B.push_back(temp);
		}
	}

	for (auto A : B) {
		ll a = A[0];
		for (int i = 1; i < A.size(); i++) {
			ll b = A[i];
			__int128 g = __int128(a) * __int128(b);
			__int128 q = sqrtl(g);
			if (q * q != g)	return cout << "NO", 0;
		}
	}
	cout << "YES";

}