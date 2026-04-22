#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using eg = pair<int, ll>;

struct Tree {
	vector<vector<eg>> V;
	vector<pair<ll, int>> D;	// 결과값, 인덱스
	vector<ll> sub;
};

Tree E, W;
ll N, M;

void init(Tree& A) {
	A.V.resize(100001);
	A.D.resize(100001);
	A.sub.resize(100001);
	for (int i = 1; i <= 100000; i++)	A.D[i].second = i;
}

// 서브트리 크기, 서브트리의 모든 경로 가중치 합
ll dfs(int n, int p, Tree &A) {
	A.sub[n] = 1;
	for (eg i : A.V[n]) {
		if (i.first == p)	continue;
		ll info = dfs(i.first, n, A);
		A.sub[n] += A.sub[i.first]; 
		A.D[n].first += info + i.second * A.sub[i.first];
	}
	return A.D[n].first;
}

void dfs2(int n, int p, Tree &A, ll C) {
	for (eg i : A.V[n]) {
		if (i.first == p)	continue;
		ll child = A.D[i.first].first + i.second * A.sub[i.first];
		A.D[i.first].first += ((A.D[n].first - child) + i.second * (C - A.sub[i.first]));
		dfs2(i.first, n, A, C);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	init(E);	init(W);
	for (int i = 1; i < N; i++) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		E.V[a].push_back({ b,c });
		E.V[b].push_back({ a,c });
	}
	cin >> M;
	for (int i = 1; i < M; i++) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		W.V[a].push_back({ b,c });
		W.V[b].push_back({ a,c });
	}
	dfs(1, 0, E);
	dfs2(1, 0, E, N);
	dfs(1, 0, W);
	dfs2(1, 0, W, M);
	sort(E.D.begin() + 1, E.D.begin() + N + 1);
	sort(W.D.begin() + 1, W.D.begin() + M + 1);
	cout << E.D[1].second << ' ' << W.D[1].second << '\n';
	ll s = N * M + E.D[1].first * M + W.D[1].first * N;
	cout << s;
}