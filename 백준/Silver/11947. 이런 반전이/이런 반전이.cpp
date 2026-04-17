#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	for (cin >> T; T--;) {
		ll n;
		cin >> n;
		string g = to_string(n);
		g[0] = '4';
		for (int i = 1; i < g.size(); i++)	g[i] = '9';
		if (n >= stoll(g))	n = stoll(g);
		g = to_string(n);
		for (char& i : g)	i = '0' + ('9' - i);
		cout << n * stoll(g) << '\n';
	}

}