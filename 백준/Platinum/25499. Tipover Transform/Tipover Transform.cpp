#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	vector<int> H = { 1 }, P = { 0 };
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		if (a)	H.push_back(a), P.push_back(i);
	}
	if (H.size() == 1) { cout << N; return 0; }

	vector<tuple<int, int, int>> dp(H.size());
	dp[0] = { 1e9, 0, 1e9 };
	for (int i = 1; i < H.size(); i++) {
		auto& [x, y, z] = dp[i];
		auto& [px, py, pz] = dp[i - 1];
		int L = P[i] - H[i], M = P[i], R = P[i] + 1;
		int PL = P[i - 1] - 1, PM = P[i - 1], PR = P[i - 1] + H[i - 1];
		
		x = 1e9;
		if (L > PL)	x = min(x, px + L - PL - 1);
		if (L > PM)	x = min(x, py + L - PM - 1);
		if (L > PR)	x = min(x, pz + L - PR - 1);
		y = 1e9;
		if (M > PL)	y = min(y, px + M - PL - 1);
		if (M > PM)	y = min(y, py + M - PM - 1);
		if (M > PR)	y = min(y, pz + M - PR - 1);
		z = 1e9;
		if (P[i] + H[i] <= N) {
			if (R > PL)	z = min(z, px + R - PL - 1);
			if (R > PM)	z = min(z, py + R - PM - 1);
			if (R > PR)	z = min(z, pz + R - PR - 1);
		}
		if (i == H.size() - 1) {
			cout << min({ x + (N - P[i] + 1), y + (N - P[i]), z + (N - P[i] - H[i]) });
		}
	}

}