#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using frac = pair<ll, ll>;

ll gcd(ll a, ll b) {
	if (a < b)	swap(a, b);
	return a % b ? gcd(b, a % b) : b;
}

frac ADD(frac a, frac b) {
	frac res = { a.first * b.second + b.first * a.second, a.second * b.second };
	if (res.first == 0)	res.second = 1;
	else {
		ll g = gcd(abs(res.first), abs(res.second));
		res.first /= g, res.second /= g;
	}
	return res;
}

int CMP(frac a, frac b) {
	if (a.first * b.second > b.first * a.second)	return 1;
	if (a.first * b.second < b.first * a.second)	return -1;
	return 0;
}

struct cmp {
	bool operator()(tuple<frac, int, int, int> b, tuple<frac, int, int, int> a) {
		int ca = get<1>(a), cb = get<1>(b);
		if (ca == cb) {
			frac A = get<0>(a), B = get<0>(b);
			return CMP(A, B) < 0;
		}
		return ca < cb;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };

	int T;
	for (cin >> T; T--;) {
		int C[50][50]{}, N, M;
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				char a;
				cin >> a;
				C[i][j] = a - '0';
			}
		}
		pair<int, int> start, end;
		cin >> start.first >> start.second >> end.first >> end.second;
		start.first--, start.second--, end.first--, end.second--;

		priority_queue<tuple<frac, int, int, int>, vector<tuple<frac, int, int, int>>, cmp> Q;
		frac dist1[50][50]{};
		int dist2[50][50]{};
		dist1[start.first][start.second] = { 1, C[start.first][start.second] };
		dist2[start.first][start.second] = 1;
		Q.emplace(dist1[start.first][start.second], 1, start.first, start.second);
		if (C[start.first][start.second] == 1) { cout << "-1\n"; continue; }
		while (!Q.empty()) {
			auto [F, t, x, y] = Q.top();
			Q.pop();
			if (t > dist2[x][y])	continue;
			else if (t == dist2[x][y] && CMP(F, dist1[x][y]) > 0)	continue;
			for (int d = 0; d < 4; d++) {
				int xx = x + dx[d], yy = y + dy[d];
				if (xx >= 0 && xx < N && yy >= 0 && yy < M) {
					if (C[xx][yy] <= 1)	continue;
					frac new_dist1;
					int new_dist2 = t;
					if (CMP(ADD(F, { 1, C[xx][yy] }), { 1,1 }) > 0)	new_dist2++, new_dist1 = ADD({ 1, C[x][y] }, { 1, C[xx][yy] });
					else	new_dist1 = ADD(F, { 1, C[xx][yy] });
					if (!dist2[xx][yy] || dist2[xx][yy] > new_dist2 || (dist2[xx][yy] == new_dist2 && CMP(dist1[xx][yy], new_dist1) > 0)) {
						dist1[xx][yy] = new_dist1;
						dist2[xx][yy] = new_dist2;
						Q.emplace(new_dist1, new_dist2, xx, yy);
					}
				}
			}
		}

		if (!dist2[end.first][end.second])	cout << "-1\n";
		else	cout << dist2[end.first][end.second] << '\n';

	}

}