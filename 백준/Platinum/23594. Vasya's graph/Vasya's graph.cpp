#include <iostream>
#include <set>
#include <functional>
using namespace std;

set<int> S[100001]{};
vector<int> V[100001]{};
int r[100001]{};

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, K, M;
	cin >> N >> K >> M;
	for (int i = 1; i <= N; i++) V[i].push_back(i), r[i] = i;
	function<int(int)> f = [&](int x) -> int { return x == r[x] ? x : r[x] = f(r[x]); };

	for (int a,b; K--;) {
		cin >> a >> b;
		S[a].insert(b);
		S[b].insert(a);
	}

	vector<int> ans;
	for (int a, b, i = 1; M--; i++) {
		cin >> a >> b;
		int x = f(a), y = f(b);
		if (x == y) {
			ans.push_back(i);
			continue;
		}
		bool flag = 1;
		int small = V[x].size() < V[y].size() ? x : y;
		int big = small == x ? y : x;
		for (int k : V[small]) {
			if (S[big].count(k)) { flag = 0; break; }
		}
		if (!flag) continue;

		ans.push_back(i);
		if (V[x].size() > V[y].size()) swap(V[x], V[y]);
		for (int k : V[x]) V[y].push_back(k);
		V[x] = vector<int>();
		if (S[x].size() > S[y].size()) swap(S[x], S[y]);
		for (int k : S[x]) S[y].insert(k);
		S[x] = set<int>();
		r[x] = y;

	}
	cout << ans.size() << '\n';
	for (int i : ans) cout << i << ' ';

}