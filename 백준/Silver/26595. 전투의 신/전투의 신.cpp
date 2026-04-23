#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <cassert>
#include <map>
#include<set>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using pll = pair <ll, ll>;

int main() {
	ll n, a, pa, b, pb;
	cin >> n >> a >> pa >> b >> pb;
	ll cb = n / pb, ca = (n - cb * pb) / pa;
	ll total = ca * pa + cb * pb;
	ll mx = cb * b + ca * a, cur = mx;
	ll ansa = ca, ansb = cb;
	while (cb > 0) {
		cb--, total -= pb, cur -= b;
		while (total + pa <= n)	ca++, total += pa, cur += a;
		if (cur > mx) {
			mx = cur;
			ansa = ca, ansb = cb;
		}
	}
	ca = n / pa, cb = (n - ca * pa) / pb;
	if (ca * a + cb * b > mx)	ansa = ca, ansb = cb;
	cout << ansa << ' ' << ansb;
}