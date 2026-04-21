#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll x;
	while (cin >> x) {
		x *= 10000000;
		ll arr[1000000]{}, n;
		cin >> n;
		for (int i = 0; i < n; i++)	cin >> arr[i];
		sort(arr, arr + n);
		int s = 0, e = n - 1;
		bool f = 0;
		while (s < e) {
			if (arr[s] + arr[e] > x)	e--;
			else if (arr[s] + arr[e] < x)	s++;
			else {
				f = 1;
				cout << "yes " << arr[s] << ' ' << arr[e] << '\n';
				break;
			}
		}
		if (!f)	cout << "danger\n";
	}


}