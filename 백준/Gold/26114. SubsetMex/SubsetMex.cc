#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	for (cin >> T; T--;) {
		int n;
		cin >> n;
		ll cnt[50]{};
		for (int i = 0; i < n; i++)	cin >> cnt[i], cnt[i]--;
		
		ll ans = 1;
		while (1) {
			int tar = n;
			for (int i = n - 1; i >= 0; i--) {
				if (cnt[i] < 0) {
					tar = i;
					break;
				}
			}
			if (tar == n)	break;
			for (int i = 0; i < tar; i++)	cnt[i] += cnt[tar];
			ans -= cnt[tar];
			cnt[tar] = 0;
		}
		cout << ans << '\n';

	}


}