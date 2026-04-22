#include <iostream>
#include <queue>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll t, n, a, b, s;
	for (cin >> t; t--;) {
		s = 0;
		priority_queue<ll, vector<ll>, greater<>>Q;
		for (cin >> n; n--;) {
			cin >> a;
			Q.push(a);
		}
		while (Q.size() > 1) {
			a = Q.top(); Q.pop();
			b = Q.top(); Q.pop();
			Q.push(a + b);
			s += a + b;
		}
		cout << s << '\n';
	}
}