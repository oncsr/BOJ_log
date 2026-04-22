#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pp = pair<ll, ll>;

bool cmp(ll a, ll b) {
	if (abs(a) == abs(b))	return a > b;
	return abs(a) < abs(b);
}

int main() {
	int T, tst = 1;
	for (cin >> T; T--;) {
		ll n, c;
		cin >> n >> c;
		vector<ll> arr;
		for (int i = 0; i < n; i++) {
			ll a, b;
			cin >> a >> b;
			a++, b--;
			if (a <= b) {
				arr.push_back(a);
				arr.push_back(-b);
			}
		}
		sort(arr.begin(), arr.end(), cmp);
		priority_queue<pp, vector<pp>, less<>> Q;	// {점수,개수}
		ll cnt = 1;
		for (int i = 1; i < arr.size(); i++) {
			ll prev = abs(arr[i - 1]);
			if (arr[i - 1] < 0)	prev++;
			ll len = abs(arr[i]) - prev;
			if (arr[i] < 0)	len++;
			Q.push({ cnt, len });
			if (arr[i] > 0)	cnt++;
			else	cnt--;
		}
		
		ll ans = 0;
		while (!Q.empty() && c > 0) {
			if (Q.top().second < 0) {
				Q.pop();
				continue;
			}
			ll g = min(Q.top().second, c);
			ans += Q.top().first * g;
			c -= g;
			Q.pop();
		}
		cout << "Case #" << tst++ << ": " << ans + n << '\n';
	}
}