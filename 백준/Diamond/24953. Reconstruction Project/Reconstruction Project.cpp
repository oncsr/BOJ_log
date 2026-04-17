#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N, M;
	cin >> N >> M;
	vector<tuple<ll, int, int>> E(M);
	for (auto& [c, a, b] : E)	cin >> a >> b >> c;
	sort(E.begin(), E.end());

	vector<int> root(N + 1);
	iota(root.begin(), root.end(), 0);
	function<int(int)> F = [&](int x) -> int {
		if (x == root[x])	return x;
		return root[x] = F(root[x]);
	};

	vector<tuple<int, ll, int, int, ll>> R;
	vector<vector<pair<int, ll>>> V(N + 1);
	priority_queue<ll, vector<ll>, greater<>> upper;
	ll usum = 0, usz = 0;
	for (auto& [c, a, b] : E) {
		int x = F(a), y = F(b);
		if (x == y) {
			R.emplace_back(0, c, a, b, 0);
			continue;
		}
		root[x] = y;
		upper.push(c);
		usum += c;
		usz++;
		V[a].emplace_back(b, c);
		V[b].emplace_back(a, c);
	}

	vector<int> par(N + 1);
	// val[i] = i에서 올라가는 간선의 가중치
	vector<ll> val(N + 1);
	function<void(int, int)> dfs = [&](int n, int p) -> void {
		par[n] = p;
		for (auto& [i, c] : V[n]) {
			if (i == p)	continue;
			dfs(i, n);
			val[i] = c;
		}
	};

	for (auto& [x, c, a, b, r] : R) {
		// a~b 경로에서 가장 작은 간선 구하기
		par = vector<int>(N + 1);
		val = vector<ll>(N + 1);
		dfs(a, 0);
		int t = b;
		ll mn = 1e18;
		int p, q;
		while (par[t]) {
			if (val[t] < mn)	mn = val[t], p = t, q = par[t];
			t = par[t];
		}
		x = (mn + c + 1) >> 1;
		r = mn;
		
		// V[p]에서 q 지우기, V[q]에서 p 지우기
		vector<pair<int, ll>>::iterator iter1 = V[p].begin();
		vector<pair<int, ll>>::iterator iter2 = V[q].begin();
		while (*iter1 != make_pair(q, mn))	iter1++;
		while (*iter2 != make_pair(p, mn))	iter2++;
		V[p].erase(iter1);
		V[q].erase(iter2);
		V[a].emplace_back(b, c);
		V[b].emplace_back(a, c);
	}
	sort(R.begin(), R.end());

	int Q, id = 0;
	ll lsum = 0, lsz = 0;
	for (cin >> Q; Q--;) {
		ll X;
		cin >> X;
		while (!upper.empty() && upper.top() <= X) {
			ll g = upper.top();
			usum -= g;
			lsum += g;
			usz--;
			lsz++;
			upper.pop();
		}
		while (id < R.size() && get<0>(R[id]) <= X) {
			auto& [x, c, a, b, r] = R[id++];
			// r이 빠지고, c가 들어감
			lsum -= r, lsz--;
			if (c <= X)	lsum += c, lsz++;
			else	upper.push(c), usum += c, usz++;
		}
		ll res = usum - X * usz + X * lsz - lsum;
		cout << res << '\n';
	}

}