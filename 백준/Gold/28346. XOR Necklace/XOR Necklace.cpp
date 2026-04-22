#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	for (cin >> T; T--;) {
		int n;
		cin >> n;
		ll arr[500]{};
		for (int i = 0; i < n; i++)	cin >> arr[i];
		ll s = 0;
		for (int i = 0; i < n; i++)	s += arr[i] ^ arr[(i + 1) % n];
		cout << s << '\n';
	}
}