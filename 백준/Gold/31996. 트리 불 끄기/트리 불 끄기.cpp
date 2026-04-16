#include <bits/stdc++.h>
using namespace std;

int S[100001]{}, N, R, B[100001]{};
vector<vector<int>> V(100001);
vector<int> ans;

int ex(int n, int p) {
	B[n] = S[n];
	for (int i : V[n]) {
		if (i == p)	continue;
		B[n] += ex(i, n);
	}
	return B[n];
}

void dfs(int n, int p) {
	for (int i : V[n]) {
		if (i == p)	continue;
		if (B[i]) {
			S[n] ^= 1;
			ans.push_back(i);
			dfs(i, n);
		}
	}
	if (S[n]) {
		S[n] ^= 1;
		if (n == R)	ans.push_back(V[n][0]);
		else	ans.push_back(p);
	}
	else {
		if (n == R)	return;
		S[p] ^= 1;
		ans.push_back(p);
		ans.push_back(n);
		ans.push_back(p);
	}
	return;
}


int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> R;
	for (int i = 1; i <= N; i++) {
		char a;
		cin >> a;
		S[i] = a - '0';
	}
	for (int i = 1; i < N; i++) {
		int a, b;
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}

	ex(R, 0);
	dfs(R, 0);
	cout << ans.size() << '\n';
	for (int i : ans)	cout << i << ' ';

}