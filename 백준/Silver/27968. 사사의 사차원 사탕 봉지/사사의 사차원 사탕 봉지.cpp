#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M;
	cin >> N >> M;
	ll arr[300000]{};
	for (int i = 0; i < M; i++) {
		cin >> arr[i];
		if (!i)	continue;
		arr[i] += arr[i - 1];
	}
	for (int i = 0; i < N; i++) {
		ll a;
		cin >> a;
		int g = lower_bound(arr, arr + M, a) - arr;
		if (g == M)	cout << "Go away!\n";
		else	cout << g + 1 << '\n';
	}
}