#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pl = pair<ll, ll>;

void sol() {

	int TC = 1;
	//cin >> TC;
	for (; TC--;) {

		int D[15][1 << 15]{}, N, c[15][15]{};
		memset(D, -1, sizeof(D));
		cin >> N;
		D[0][1] = 0;
		for (int i = 0; i < N; i++)	for (int j = 0; j < N; j++) {
			char a;
			cin >> a;
			c[i][j] = a - '0';
		}

		int ans = 0;
		for (int i = 2; i < (1 << N); i++) {
			int cnt = 0;
			for (int k = 0; k < N; k++)	if (i & (1 << k))	cnt++;
			for (int j = 0; j < N; j++) {
				if (!(i & (1 << j)))	continue;
				int& v = D[j][i], x = i ^ (1 << j);
				for (int k = 0; k < N; k++) {
					if (!(x & (1 << k)))	continue;
					if (D[k][x] == -1 || D[k][x] > c[k][j])	continue;
					if (v == -1)	v = 10;
					v = min(v, c[k][j]);
				}
				if (v != -1)	ans = max(ans, cnt);
			}
		}
		cout << ans;

	}

}

int main() {

	sol();

}