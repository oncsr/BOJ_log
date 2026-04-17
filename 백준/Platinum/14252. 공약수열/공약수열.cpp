#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N;
	cin >> N;
	vector<int> S(N);
	for (int& i : S)	cin >> i;
	int ans = 0;
	sort(S.begin(), S.end());
	for (int i = 1; i < S.size(); i++) {
		int a = S[i - 1], b = S[i];
		if (gcd(a, b) == 1)	continue;
		bool F = 0;
		for (int k = a + 1; k < b; k++) {
			if (gcd(a, k) == 1 && gcd(k, b) == 1) {
				ans++;
				F = 1;
				break;
			}
		}
		if (F)	continue;
		ans += 2;
	}
	cout << ans;

}