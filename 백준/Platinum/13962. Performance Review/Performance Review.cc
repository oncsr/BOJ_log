#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ii = pair<int, int>;
using ll = long long;

pair<pair<ll, ll>, int> a[100001]{};	// first = 등급, second = 시간
vector<vector<int> > V(100001);
ii euler[100001]{};	// 오일러경로 저장
ll seg[262145]{};
ll ans[100001]{};
int cnt = 0;

void dfs(int node) {
	euler[node].first = ++cnt;
	for (int next : V[node])	dfs(next);
	euler[node].second = cnt;
}

ll find(int s, int e, int l, int r, int n) {
	if (l > e || r < s)	return 0;
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) / 2;
	return find(s, m, l, r, n * 2) + find(m + 1, e, l, r, n * 2 + 1);
}

void upt(int s, int e, int id, ll val, int n) {
	if (s == e) {
		seg[n] = val;
		return;
	}
	int m = (s + e) / 2;
	if (id <= m)	upt(s, m, id, val, n * 2);
	else	upt(m + 1, e, id, val, n * 2 + 1);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int E, m, r, t, root;
	cin >> E;
	for (int i = 1; i <= E; i++) {
		cin >> m >> r >> t;
		a[i] = { { r,t },i };
		if (m == -1) {
			root = i;
			continue;
		}
		V[m].push_back(i);
	}
	sort(a + 1, a + E + 1);
	dfs(root);
	int idx = 0;
	pair<ll, ll> arr[100001]{};
	int temp = a[1].first.first;
	for (int i = 1; i <= E; i++) {		
		int start = euler[a[i].second].first;
		int end = euler[a[i].second].second;
		if (a[i].first.first == temp) {
			arr[idx++] = { start,a[i].first.second };
		}
		else {
			for (int k = 0; k < idx; k++) {
				upt(1, E, arr[k].first, arr[k].second, 1);
			}
			idx = 0;
			arr[idx++] = { start,a[i].first.second };
			temp = a[i].first.first;
		}
		ans[a[i].second] = find(1, E, start, end, 1);
	}
	for (int i = 1; i <= E; i++)	cout << ans[i] << '\n';
}