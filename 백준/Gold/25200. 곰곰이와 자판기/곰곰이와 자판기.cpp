#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	cin >> N >> M;
	vector<set<int>> S(N + 1);
	for (int i = 1; i <= N; i++)	S[i].insert(i);

	for (; M--;) {
		int a, b;
		cin >> a >> b;
		if (S[a].size() > S[b].size())	swap(S[a], S[b]);
		for (int i : S[a])	S[b].insert(i);
		S[a] = set<int>();
	}

	vector<int> ans(N + 1);
	for (int i = 1; i <= N; i++)	for (int j : S[i])	ans[j] = i;
	for (int i = 1; i <= N; i++)	cout << ans[i] << ' ';

}