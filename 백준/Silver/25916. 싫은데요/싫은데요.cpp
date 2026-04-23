#include <iostream>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll n, m, arr[500000]{}, s = 0, V = 0, mx = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (i == 0) {
			s = 0, V += arr[i];
			if (V > m)	s++, V = 0;
			else	mx = V;
		}
		else {
			V += arr[i];
			if (V > m) {
				while (V > m)
					V -= arr[s++];
			}
			mx = max(V, mx);
		}
	}
	cout << mx;
}