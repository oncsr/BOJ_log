#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll Q, ls = 0, rs = 0, ys = 0;
	priority_queue<ll, vector<ll>, greater<>> high;
	priority_queue<ll, vector<ll>, less<>> low;

	for (cin >> Q; Q--;) {
		ll o, a, b;
		cin >> o;
		ll lsz = low.size(), rsz = high.size();
		if (o == 2) {
			if (low.empty())	cout << "-1000000000 0\n";
			else {
				ll x = low.top();
				cout << x << ' ' << x * (lsz - rsz) + rs - ls + ys << '\n';
			}
		}
		else {
			cin >> a >> b;
			ys += b;
			if (lsz == rsz)	low.push(a), ls += a;
			else	high.push(a), rs += a;

			if (!high.empty() && low.top() > high.top()) {
				ll lt = low.top(), ht = high.top();
				ls = ls - lt + ht;
				rs = rs - ht + lt;
				high.push(lt);
				low.pop();
				low.push(ht);
				high.pop();
			}

		}
	}

}