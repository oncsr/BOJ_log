#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
	if (a < b)	swap(a, b);
	return a % b ? gcd(b, a % b) : b;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	priority_queue<pair<int, ll>, vector<pair<int, ll>>, greater<>> Q;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		int cnt = 0, temp = a;
		while (!(temp & 1)) {
			temp >>= 1;
			cnt++;
		}
		Q.emplace(cnt, a);
	}
	while (Q.size() > 1) {
		auto [_, a] = Q.top();	Q.pop();
		auto [__, b] = Q.top();	Q.pop();
		ll n = 2 * gcd(a, b), temp = n, cnt = 0;
		while (!(temp & 1)) {
			temp >>= 1;
			cnt++;
		}
		Q.emplace(cnt, n);
	}
	cout << Q.top().second;

}