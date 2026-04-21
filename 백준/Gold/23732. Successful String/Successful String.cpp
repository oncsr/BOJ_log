#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	ll n, ans = 0, t = -1;
	char temp, a;
	cin >> n >> temp;
	for (int i = 1; i < n; i++) {
		cin >> a;
		if (a == temp) {
			if (t == -1)	t = i;
			else {
				ans += t * (i - t);
				t = i;
			}
		}
		temp = a;
	}
	if (t != -1)	ans += t * (n - t);
	cout << ans;

}