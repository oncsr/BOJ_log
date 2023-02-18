#include <bits/stdc++.h>
using namespace std;
using vv = vector<vector<int> >;
using ll = long long;
int N;
vv arr;

vv R(ll n) {
	if (n == 1)	return arr;
	vv part = R(n / 2);
	vv conq(N);
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			int s = 0;
			for (int i = 0; i < N; i++)
				s += part[x][i] * part[i][y];
			conq[x].push_back(s % 1000);
		}
	}
	if (n % 2) {
		part = conq;
		conq = vv(N);
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				int s = 0;
				for (int i = 0; i < N; i++)
					s += part[x][i] * arr[i][y];
				conq[x].push_back(s % 1000);
			}
		}
	}
	return conq;
}

int main() {
	ll B;
	int a;
	cin >> N >> B;
	arr = vv(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a;
			arr[i].push_back(a % 1000);
		}
	}
	vv ans = R(B);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)	cout << ans[i][j] << ' ';
		cout << '\n';
	}
}