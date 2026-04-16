#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;

	ll odd = 0, even = 0;
	ll zero = 0, one = 0;
	for (ll i = 0; i < N; i++) {
		ll a;
		cin >> a;
		if (a % 2 == 0) {
			even += (i - zero++);
		}
		else {
			odd += (i - one++);
		}
	}

	cout << min(odd, even);

}