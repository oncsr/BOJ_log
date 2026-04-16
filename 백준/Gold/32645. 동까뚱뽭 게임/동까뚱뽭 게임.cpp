#include <bits/stdc++.h>
using namespace std;
 
vector<vector<int>> V(100001);
bitset<100001> ans;
 
bool dfs(int n, int p) {
	bool s = 0;
	for (int i : V[n]) {
		if (i == p)	continue;
		s |= dfs(i, n);
	}
	return ans[n] = s^1;
}
 
int main() {
	cin.tie(0)->sync_with_stdio(0);
 
	int N;
	cin >> N;
	for (int i = 1; i < N; i++) {
		int a, b;
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
 
	dfs(1, 0);
 
	for (int i = 1; i <= N; i++)	cout << (ans[i] ? "uppercut\n" : "donggggas\n");
 
}