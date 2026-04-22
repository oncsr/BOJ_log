#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct edge {
	ll cost;
	int u, v;
};

bool cmp(edge a, edge b) {
	return a.cost > b.cost;
}

int root[100001]{};
ll cnt[100001]{};

pair<int, ll> find(int x) {
	if (root[x] == x)	return { x, cnt[x] };
	pair<int, ll> p = find(root[x]);
	root[x] = p.first, cnt[x] = p.second;
	return p;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	vector<edge> V;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		V.push_back({ c,a,b });
	}
	sort(V.begin(), V.end(), cmp);

	// DS initialization
	for (int i = 1; i <= N; i++)	root[i] = i;

	ll mx = 0, mn = 1000000001;

	for (edge i : V) {

		pair<int, ll> fir = find(i.u);
		pair<int, ll> sec = find(i.v);
		int x = fir.first, y = sec.first;
		ll c1 = fir.second, c2 = sec.second;
		ll G = c1 + c2 + 1;
		cnt[x] = cnt[y] = G;
		root[x] = y;

		mn = min(mn, i.cost);
		mx = max(mx, mn * G);

	}
	cout << mx;


}