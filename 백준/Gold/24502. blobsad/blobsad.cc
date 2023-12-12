#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll N, K;
	cin >> N >> K;
	ll arr[1000000]{}, s = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		arr[i] %= K;
		s += arr[i];
	}
	if (s % K) { cout << "blobsad"; return 0; }

	ll ans = 0, pos = 0, S1 = 0, S2 = 0, S3 = 0, cnt = 0;
	for (int i = 0; i < N; i++) {
		S1 += (cnt++) * arr[i];
		S2 += arr[i];
		if (S2 >= K) {
			S1 -= (cnt - 1) * (S2 - K);
			ll mn = S1, id = pos++;
			for (; pos <= i; pos++) {
				S3 += 2 * arr[pos - 1];
				S1 = S1 - K + S3;
				if (S1 < mn)	mn = S1, id = pos;
			}
			ans += mn;
			arr[i] = 0;

			if (S2 % K) {
				arr[i] = S2 % K;
				pos--;
				S2 = arr[i];
				S1 = 0, S3 = 0, cnt = 1;
			}
			else {
				S1 = 0, S2 = 0, S3 = 0, cnt = 0;
			}

		}
	}
	cout << ans;


}