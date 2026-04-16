#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	priority_queue<int, vector<int>, greater<>> H;
	priority_queue<int> L;
	ll hs = 0, ls = 0, xs = 0, lsz = 0, hsz = 0;
	for (cin >> N; N--;) {
		ll x, y;
		cin >> x >> y;
		xs += abs(x);
		if (lsz == hsz)	L.push(y), ls += y, lsz++;
		else	H.push(y), hs += y, hsz++;

		if (!H.empty()) {
			ll lt = L.top(), ht = H.top();
			if (lt > ht) {
				ls += ht - lt;
				hs += lt - ht;
				H.push(lt);
				L.push(ht);
				H.pop();
				L.pop();
			}
		}
		ll m = L.top();
		cout << m << ' ' << m * (lsz - hsz) + hs - ls + xs << '\n';
	}

}