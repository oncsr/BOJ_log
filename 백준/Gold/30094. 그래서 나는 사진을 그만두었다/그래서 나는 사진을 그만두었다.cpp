#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pl = pair<ll, ll>;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll mod = 998244353;

	int N, id = 0;
	cin >> N;
	vector<pair<pl, int>> arr(N);
	for (auto& [i, n] : arr)	cin >> i.first >> i.second, n = ++id;
	sort(arr.begin(), arr.end(), [](pair<pl, int> a, pair<pl, int> b) {
		return a.first.second - a.first.first < b.first.second - b.first.first;
	});

	ll s1 = 1, temp = -1e9, cnt = 1, ans1 = 0, ans2 = 0, l = 0;
	for (auto [a, b] : arr) {
		ans1 += a.first * l + a.second * (N - l - 1);
		ans2 += a.first * (N - l - 1) + a.second * l;
		l++;
		if (a.second - a.first == temp)	cnt++;
		else {
			ll g = 1;
			for (ll c = 2; cnt-- > 1; c++) {
				g *= c;
				g %= mod;
			}
			s1 *= g;
			s1 %= mod;
			cnt = 1;
		}
		temp = a.second - a.first;
	}
	ll g = 1;
	for (ll c = 2; cnt-- > 1; c++) {
		g *= c;
		g %= mod;
	}
	s1 *= g;
	s1 %= mod;

	cout << ans1 << ' ' << s1 << '\n';
	for (auto [a, b] : arr)	cout << b << ' ';
	cout << '\n';

	cout << ans2 << ' ' << s1 << '\n';
	for (int i = arr.size() - 1; i >= 0; i--)	cout << arr[i].second << ' ';



}