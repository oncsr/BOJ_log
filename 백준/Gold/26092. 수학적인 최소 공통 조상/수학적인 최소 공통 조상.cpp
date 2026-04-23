#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

vector<ll> p(ll n) {
	vector<ll> g;
	ll i = 2;
	while (i * i <= n) {
		if (n % i == 0) {
			while (n % i == 0) {
				n /= i;
				g.push_back(i);
			}
		}
		else	i++;
	}
	if (n != 1)	g.push_back(n);
	return g;
}

int main() {
	ll a, b;
	cin >> a >> b;
	vector<ll> va = p(a);
	int ida = 0;
	vector<ll> vb = p(b);
	int idb = 0;
	while (a != b) {
		if (a > b)	a /= va[ida++];
		else	b /= vb[idb++];
	}
	cout << a;
}