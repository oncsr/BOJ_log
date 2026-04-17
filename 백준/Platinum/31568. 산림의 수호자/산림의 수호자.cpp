#include <bits/stdc++.h>
using namespace std;

int N, A, B, R, G, mx = 0;
vector<vector<int>> V(100001);
int passed[100001]{}, fire[100001]{};

void bfs() {
	int vis[100001]{};
	int par[100001]{};
	queue<int> Q;
	Q.push(B);
	vis[B]++;
	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();
		for (int i : V[now]) {
			if (vis[i])	continue;
			vis[i] = vis[now] + 1;
			par[i] = now;
			Q.push(i);
		}
	}
	G = vis[A] / 2;
	while (A) {
		if (vis[A] == G)	R = A;
		if (vis[A] <= G)	passed[A]++;
		else	fire[A]++;
		A = par[A];
	}
}

void dfs(int n, int p, int s) {
	mx = max(mx, s);
	for (int i : V[n]) {
		if (i == p || fire[i])	continue;
		dfs(i, n, s + (passed[i] ? 0 : 1));
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N;
	for (int i = 1; i < N; i++) {
		int a, b;
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	cin >> A >> B;

	bfs();
	dfs(R, 0, G);
	cout << mx;
	
}