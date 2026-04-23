#include <iostream>
#include <map>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	map<ll, ll>	M;
	ll mx = 0;
	int n;
	ll a, b, c;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		M[b - a] += c;
		mx = max(mx, M[b - a]);
	}
	cout << mx;
}