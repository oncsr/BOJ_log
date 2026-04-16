#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	for (cin >> T; T--;) {
		ll N;
		cin >> N;
		cout << max(max(lcm(N, lcm(N - 1, N - 2)), lcm(N, lcm(N - 1, N - 3))), max(lcm(N - 1, lcm(N - 2, N - 3)), lcm(N, lcm(N - 2, N - 3)))) << '\n';
	}
	
}