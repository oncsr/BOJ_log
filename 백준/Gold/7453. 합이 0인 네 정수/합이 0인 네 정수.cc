#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	vector<int> A(N), B(N), C(N), D(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}
	vector<int> X, Y;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			X.push_back(A[i] + B[j]);
			Y.push_back(C[i] + D[j]);
		}
	}
	sort(Y.begin(), Y.end());
	ll ans = 0;
	for (int i = 0; i < X.size(); i++) {
		ans += upper_bound(Y.begin(), Y.end(), -X[i]) - lower_bound(Y.begin(), Y.end(), -X[i]);
	}
	cout << ans;

}