#include <iostream>
#include <vector>
using namespace std;
using ii = pair<int, int>;

int T, N, Q, a, b, cnt = 0;
vector<vector<int> > V;
vector<int> lazy;
vector<int> in;
vector<ii> init;
vector<ii> seg;
char o;

void dfs(int node) {
	init[node].first = ++cnt;
	for (int next : V[node])	dfs(next);
	init[node].second = cnt;
}

void prop(int start, int end, int node) {
	if (lazy[node]) {
		seg[node].first += lazy[node];
		seg[node].second += lazy[node];
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void up(int start, int end, int node) {
	if (start == end) {
		seg[node] = { in[start],in[start] };
		return;
	}
	int mid = (start + end) / 2;
	up(start, mid, node * 2);
	up(mid + 1, end, node * 2 + 1);
	seg[node] = { min(seg[node * 2].first,seg[node * 2 + 1].first),max(seg[node * 2].second,seg[node * 2 + 1].second) };
}

void update(int start, int end, int left, int right, int val, int node) {
	prop(start, end, node);
	if (left > end || right < start)	return;
	if (left <= start && end <= right) {
		seg[node].first += val;
		seg[node].second += val;
		if (start != end) {
			lazy[node * 2] += val;
			lazy[node * 2 + 1] += val;
		}
		return;
	}
	int mid = (start + end) / 2;
	update(start, mid, left, right, val, node * 2);
	update(mid + 1, end, left, right, val, node * 2 + 1);
	seg[node] = { min(seg[node * 2].first,seg[node * 2 + 1].first),max(seg[node * 2].second,seg[node * 2 + 1].second) };
}

ii find(int start, int end, int left, int right, int node) {
	prop(start, end, node);
	if (left > end || right < start)	return { 1000000000,0 };
	if (left <= start && end <= right)	return seg[node];
	int mid = (start + end) / 2;
	ii a = find(start, mid, left, right, node * 2);
	ii b = find(mid + 1, end, left, right, node * 2 + 1);
	return { min(a.first,b.first),max(a.second,b.second) };
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin >> T;
	for (; T--;) {
		V = vector<vector<int> >(1000001);
		lazy = vector<int>(2097153);
		seg = vector<ii>(2097153);
		init = vector<ii>(1000001);
		in = vector<int>(1000001);
		cnt = 0;
		cin >> N;
		for (int i = 2; i <= N; i++) {
			cin >> a;
			V[a].push_back(i);
		}
		dfs(1);
		for (int i = 1; i <= N; i++) {
			cin >> a;
			in[init[i].first] = a;
		}
		up(1, N, 1);
		cin >> Q;
		for (; Q--;) {
			cin >> o >> a;
			if (o == 'R') {
				cin >> b;
				update(1, N, init[a].first, init[a].second, b, 1);
			}
			else {
				ii ans = find(1, N, init[a].first, init[a].second, 1);
				cout << ans.second - ans.first << '\n';
			}
		}
	}
}