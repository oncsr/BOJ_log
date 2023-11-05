#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return (a.first * b.second) < (a.second * b.first);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	

	int d[5001][5001]{};
	int n, k;
	cin >> n >> k;
	pair<int, int> V[10000000]{};
	int pos = 0;
	V[pos++] = make_pair(0, 1);
	V[pos++] = make_pair(1, 1);
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (d[j][i])	continue;
			V[pos++] = make_pair(j, i);
			for (int s = 2; i * s <= n; s++)	d[j * s][i * s] = 1;
		}
	}
	nth_element(V, V + k - 1, V + pos, cmp);
	cout << V[k - 1].first << ' ' << V[k - 1].second;

}