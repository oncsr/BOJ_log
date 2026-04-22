#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

void filling(vector<vector<int>>& V, vector<int>& R, int pos, int n, int k) {
	if (pos == n) {
		R.push_back(k);
		return;
	}
	for (int i = 0; i < V[pos].size(); i++)	filling(V, R, pos + 1, n, k * V[pos][i]);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	/////////
	int e[1000001]{};
	for (int i = 2; i * i <= 1000000; i++)
		if (!e[i])
			for (int j = i * i; j <= 1000000; j += i)
				if (!e[j])	e[j] = i;
	vector<int> sosu;
	for (int i = 2; i <= 1000000; i++)
		if (!e[i])	sosu.push_back(i);
	///////// 
	int T;
	for (cin >> T; T--;) {
		int N;
		cin >> N;
		vector<vector<int>> V(N);
		vector<vector<ll>> D(N);
		for (int i = 0; i < N; i++) {
			int H;
			cin >> H;
			int id = 0;
			vector<vector<int>> sis;
			for (int j : sosu) {
				if (j > H)	break;
				if (H % j)	continue;
				sis.push_back({ 1 });
				int G = 1;
				while (H % j == 0) {
					H /= j;
					G *= j;
					sis[id].push_back(G);
				}
				id++;
			}
			filling(sis, V[i], 0, id, 1);
			sort(V[i].begin(), V[i].end());
			D[i] = vector<ll>(V[i].size());
			if (i == 0) {
				for (int j = 0; j < V[i].size(); j++)	D[i][j] = 1;
				continue;
			}
			int pos = 0;
			ll g = 0;
			for (int j = 0; j < V[i].size(); j++) {
				while (pos < V[i - 1].size() && V[i - 1][pos] <= V[i][j])
					g = (g + D[i - 1][pos++]) % mod;
				D[i][j] = g;
			}
		}
		ll ans = 0;
		for (int j = 0; j < V[N - 1].size(); j++)
			ans = (ans + D[N - 1][j]) % mod;
		cout << ans << '\n';
	}
}