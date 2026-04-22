#include <iostream>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
	if (a < b)	swap(a, b);
	return a % b ? gcd(a % b, b) : b;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	ll arr[100000]{}, G = 0, ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (!i)	continue;
		if (!G)	G = arr[i] - arr[i - 1];
		else	G = gcd(G, arr[i] - arr[i - 1]);
	}
	for (int i = 1; i < N; i++)
		ans += ((arr[i] - arr[i - 1]) / G) - 1;
	cout << ans;
}