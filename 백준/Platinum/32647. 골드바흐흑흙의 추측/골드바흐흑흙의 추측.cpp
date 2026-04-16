#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
	cin.tie(0)->sync_with_stdio(0);
 
	int A, B, K;
	cin >> A >> B >> K;
 
	vector<int> S;
	ll sum = 0;
	for (int i = max(2, A); i <= B; i++) {
		bool f = 1;
		for (int j = 2; j * j <= i; j++) {
			if (i % j == 0)	f = 0;
		}
		if (f)	S.push_back(i), sum += i;
	}
    
	if (S.size() < 40) {
		vector<int> R1, R2;
 
		function<void(int, int, int, vector<int>&)> sol = [&](int pos, int sum, int tar, vector<int>& R) -> void {
			if (pos == tar) {
				R.push_back(sum);
				return;
			}
			sol(pos + 1, sum, tar, R);
			sol(pos + 1, sum + S[pos], tar, R);
		};
		sol(0, 0, S.size() / 2, R1);
		sol(S.size() / 2, 0, S.size(), R2);
 
		sort(R2.begin(), R2.end());
		ll ans = 0;
		for (int i : R1) {
			ans += upper_bound(R2.begin(), R2.end(), K - i) - lower_bound(R2.begin(), R2.end(), K - i);
		}
		cout << ans;
	}
	else {
		vector<ll> D(sum + 1);
		for (int i : S) {
			for (int j = sum; j >= i; j--) {
				if (D[j - i])	D[j] += D[j - i];
			}
			D[i]++;
		}
		if (K > sum)	cout << 0;
		else	cout << D[K];
	}
 
}