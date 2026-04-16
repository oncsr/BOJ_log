#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	
	cin.tie(0)->sync_with_stdio(0);

	ll Q;
	bool first = 1;
	vector<ll> arr;
	for (cin >> Q; Q--;) {
		ll x, y;
		cin >> x >> y;
		bool f = 0;
		if (x > y)	f = 1, swap(x, y);
		if (y % x == 0) {
			cout << y - 1 << ' ';
			if (first) {
				for (int i = 1; i < y; i++)	arr.push_back(f ? -1 : 1);
				first = 0;
			}
		}
		else {
			int v1 = (y/x)*x + x-1, v2 = y + (y % x) - 1;
			if(v1 > v2){
				cout<<(y/x)*x + x-1<<' ';
				if(first){
					ll n = (-y/x)/(y-y/x*x) - 1;
					ll m = (1-x)*n + 1;
					for(int i=1;i<=(y/x)*x + x-1;i++){
						ll v = i%x == 0 ? m : n;
						arr.push_back(f ? -v : v);
					}
					first = 0;
				}
			}
			else{
				cout << y + (y % x) - 1 << ' ';
				if (first) {
					ll a = y / x + 1;
					ll m = a / (a * x - y) + 1;
					ll n = (1 - x) * m + 1;
					for (int i = 1; i <= y + (y % x) - 1; i++) {
						ll v = i % x == y % x ? n : m;
						arr.push_back(f ? -v : v);
					}

					first = 0;
				}
			}
		}
	}
	cout << '\n';
	for (ll i : arr)	cout << i << ' ';

}