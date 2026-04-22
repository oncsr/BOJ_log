#include <iostream>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll N, M, X;
	cin >> N >> M >> X;
	ll arr[1000001]{};
	for (int i = 1; i <= M; i++)	cin >> arr[i];
	for (ll i = 1; i < M; i++) {
		ll K = min(N, max(0LL, (X - N * arr[M])) / (arr[i] - arr[M]));
		cout << K << ' ';
		N -= K;
		X -= K * arr[i];
	}
	cout << min(N, X / arr[M]);
}