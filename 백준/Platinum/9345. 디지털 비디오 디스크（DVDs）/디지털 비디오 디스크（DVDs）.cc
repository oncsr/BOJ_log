#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> ii;

int tree[100001];
ii segtree[262145];

ii pairset(ii a, ii b) {
	int c, d, e, f;
	c = a.first;
	d = a.second;
	e = b.first;
	f = b.second;
	vector<int> V;
	if (c >= 0)
		V.push_back(c);
	if (d >= 0)
		V.push_back(d);
	if (e >= 0)
		V.push_back(e);
	if (f >= 0)
		V.push_back(f);
	if(!V.empty())
		sort(V.begin(), V.end());
	return { V[0],V[V.size() - 1] };
}
void init(int start, int end, int node) {
	if (start == end) {
		segtree[node] = { start,start };
		tree[start] = start;
		return;
	}
	int mid = (start + end) / 2;
	init(start, mid, node * 2 + 1);
	init(mid + 1, end, node * 2 + 2);
	segtree[node] = pairset(segtree[node * 2 + 1], segtree[node * 2 + 2]);
}

void change(int start, int end, int a, int b, int aa, int bb, int node) {
	if (a > end || b < start)	return;
	if (a < start && end < b)	return;
	if (start == end && start == a) {
		segtree[node] = { bb,bb };
		tree[start] = bb;
		return;
	}
	if (start == end && start == b) {
		segtree[node] = { aa,aa };
		tree[start] = aa;
		return;
	}
	int mid = (start + end) / 2;
	change(start, mid, a, b, aa, bb, node * 2 + 1);
	change(mid + 1, end, a, b, aa, bb, node * 2 + 2);
	segtree[node] = pairset(segtree[node * 2 + 1], segtree[node * 2 + 2]);
}

ii find(int start, int end, int a, int b, int node) {
	if (a > end || b < start)	return { -1,-1 };
	if (a <= start && end <= b)	return segtree[node];
	else {
		int mid = (start + end) / 2;
		ii g1 = find(start, mid, a, b, node * 2 + 1);
		ii g2 = find(mid + 1, end, a, b, node * 2 + 2);
		ii ch = { -1,-1 };
		if (g1 == ch && g2 == ch)
			return { -1,-1 };
		else
			return pairset(g1, g2);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int N, K;
		cin >> N >> K;
		init(0, N - 1, 0);
		while (K--) {
			int a, b, c;
			cin >> a >> b >> c;
			if (a) {
				ii ans = find(0, N - 1, b, c, 0);
				if (ans.first == b && ans.second == c)
					cout << "YES\n";
				else
					cout << "NO\n";
			}
			else
				change(0, N - 1, b, c, tree[b], tree[c], 0);
		}
	}
}