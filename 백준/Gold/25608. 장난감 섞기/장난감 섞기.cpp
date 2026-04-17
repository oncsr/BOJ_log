#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> L(10), R(10), S(10), pre(10);

vector<int> order;

tuple<int, int, int, int> SUM(int s, int e) {
	if (s == e) {
		return { L[order[s]], R[order[s]], pre[order[s]], S[order[s]] };
	}
	int m = (s + e) >> 1;
	auto [l1, r1, s1, t1] = SUM(s, m);
	auto [l2, r2, s2, t2] = SUM(m + 1, e);
	int l3, r3, s3, t3;
	l3 = max(l1, s1 + l2);
	r3 = max(r2, s2 + r1);
	s3 = s1 + s2;
	t3 = max({ t1, t2, r1 + l2 });
	return { l3, r3, s3, t3 };
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> arr(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)	cin >> arr[i][j];
		int l = 0;
		for (int j = 0; j < M; j++) {
			l += arr[i][j];
			L[i] = max(L[i], l);
		}
		pre[i] = l;
		int r = 0;
		for (int j = M - 1; j >= 0; j--) {
			r += arr[i][j];
			R[i] = max(R[i], r);
		}

		int sum = 0;
		for (int j = 0; j < M; j++) {
			sum = (sum < 0 ? arr[i][j] : sum + arr[i][j]);
			S[i] = max(S[i], sum);
		}
	}

	order = vector<int>(N);
	iota(order.begin(), order.end(), 0);

	int ans = 0;
	do {
		auto [a, b, c, t] = SUM(0, N - 1);
		ans = max(ans, t);
	} while (next_permutation(order.begin(), order.end()));
	cout << ans;
	
}