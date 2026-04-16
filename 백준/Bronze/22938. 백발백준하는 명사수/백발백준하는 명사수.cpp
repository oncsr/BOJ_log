#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	if ((a - d) * (a - d) + (b - e) * (b - e) >= (c + f) * (c + f))	cout << "NO";
	else	cout << "YES";
	
}