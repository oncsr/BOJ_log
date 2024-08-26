#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M, arr[100001]{};
	for (cin >> N >> M; M--;) {
		int o, i, x;
		cin >> o >> i;
		if (o >= 3) {
			if (o == 3)	arr[i] = (arr[i] << 1) % (1 << 20);
			else	arr[i] >>= 1;
		}
		else {
			cin >> x;
			x--;
			if (o == 1)	arr[i] |= (1 << x);
			else	arr[i] = (arr[i] | (1 << x)) ^ (1 << x);
		}
	}
	int cnt[1 << 20]{}, ans = 0;
	for (int i = 1; i <= N; i++) {
		if (cnt[arr[i]])	continue;
		ans++;
		cnt[arr[i]]++;
	}
	cout << ans;

}