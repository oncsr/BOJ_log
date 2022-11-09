#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define A(p,q,s)	p.begin(), p.end(), q.begin(), q.end(), s.begin()
vector<vector<int> > seg(524289);
int N, Q, r[200001]{}, a, b, e = 0, f = 0;
pair<int, int> E[200001]{};
vector<vector<int> > V(200001);
int index[200001]{};

void d(int n, int p)
{ E[n].first=++e;index[e]=n;for(int i:V[n])if(i!=p)d(i,n);E[n].second=e; }

void I(int s, int e, int n) {
	if (s == e) {
		seg[n].push_back(r[index[s]]);
		return;
	}
	int m = (s + e) / 2;
	I(s, m, n * 2);	I(m + 1, e, n * 2 + 1);
	seg[n].resize(seg[n * 2].size() + seg[n * 2 + 1].size());
	merge(A(seg[n * 2], seg[n * 2 + 1], seg[n]));
}

int find(int s, int e, int l, int r, int n) {
	if (l > e || r < s)	return 0;
	if (l <= s && e <= r)	return upper_bound(seg[n].begin(), seg[n].end(), b) - seg[n].begin();
	int m = (s + e) / 2;
	return find(s, m, l, r, n * 2) + find(m + 1, e, l, r, n * 2 + 1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> Q >> a;
	for (int i = 1; i <= N; i++)	cin >> r[i];
	for (int i = 1; i < N; i++) {
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	d(1, 0); I(1, N, 1);
	for (; Q--;) {
		cin >> a >> b;
		f += find(1, N, E[a].first, E[a].second, 1);
		f %= 1000000007;
	}
	cout << f;
}