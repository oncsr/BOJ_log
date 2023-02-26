#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct sinho {
	ll x, t, s;
};

bool cmp(sinho a, sinho b) { return a.x < b.x; }

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll n, k;
	cin >> n >> k;
	vector<sinho> V;
	for (; k--;) {
		ll a, b, c;
		cin >> a >> b >> c;
		V.push_back({ a,b,c });
	}
	sort(V.begin(), V.end(), cmp);
	ll ans = 0, pos = 0;
	for (sinho now : V) {
		ans += (now.x - pos);
		pos = now.x;
		if (ans < now.s)	ans = now.s;
		else if (((ans - now.s) / now.t) % 2)
			ans = now.s + (((ans - now.s) / now.t) + 1) * now.t;
	}
	ans += (n - pos);
	cout << ans;
}