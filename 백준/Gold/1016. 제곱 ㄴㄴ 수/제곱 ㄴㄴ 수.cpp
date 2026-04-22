#include <iostream>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll e[1000001]{};
	ll arr[1000001]{};
	ll mn, mx, s;
	cin >> mn >> mx;
	s = mx - mn + 1;
	for (ll i = 2; i * i <= mx; i++) {
		if (e[i])	continue;
		for (ll j = i * 2; j <= 1000000; j += i)	e[j] = 1;
		ll k = i * i;
		for (ll a = (mn / k * k == mn ? mn : mn / k * k + k); a <= mx; a += k) {
			if (!arr[a - mn])	s--;
			arr[a - mn]++;
		}
	}
	cout << s;

}