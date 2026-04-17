#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, L, P;
	cin >> N;
	vector<pair<int, int>> V(N + 1);
	for (int i = 1; i <= N; i++)	cin >> V[i].first >> V[i].second;
	sort(V.begin() + 1, V.end());

	cin >> L >> P;
	int idx = 1, lim = P, ans = 0;
	priority_queue<int> Q;
	while (lim < L) {
		int mx = -1e9, next = 0;
		for (; idx <= N && V[idx].first <= lim; idx++)	Q.emplace(V[idx].second);
		if (Q.empty())	break;
		lim += Q.top();
		Q.pop();
		ans++;
	}
	if (lim < L)	cout << -1;
	else	cout << ans;

}