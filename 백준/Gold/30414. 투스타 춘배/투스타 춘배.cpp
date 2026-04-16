#include <bits/stdc++.h>
using namespace std;

int ans = 0, N, P;
vector<vector<int>> V(100001);
int A[100001]{}, B[100001]{};

int dfs(int n, int p) {
	int res = 0;
	for (int i : V[n]) {
		if (i == p)	continue;
		res += dfs(i, n);
	}
	return max(0, res + B[n] - A[n]);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> P;
	for (int i = 1; i <= N; i++)	cin >> A[i];
	for (int i = 1; i <= N; i++)	cin >> B[i];
	for (int i = 1; i < N; i++) {
		int a, b;
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}

	cout << dfs(P, 0);

}