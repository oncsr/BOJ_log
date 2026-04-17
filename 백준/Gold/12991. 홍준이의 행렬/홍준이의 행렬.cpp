#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	ll N, K;
	cin >> N >> K;
	vector<ll> A(N), B(N);
	for (ll& i : A)	cin >> i;
	for (ll& i : B)	cin >> i;

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	ll s = 1, e = 1e18, m = (s + e) >> 1;
	while (s < e) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			cnt += upper_bound(B.begin(), B.end(), m / A[i]) - B.begin();
		}
		if (cnt < K)	s = m + 1;
		else	e = m;
		
		m = (s + e) >> 1;
	}
	cout << m;

}