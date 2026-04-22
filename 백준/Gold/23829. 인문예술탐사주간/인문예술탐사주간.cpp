#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, Q;
	cin >> N >> Q;
	ll arr[100001]{}, sum[100001]{};
	for (int i = 1; i <= N; i++)	cin >> arr[i];
	sort(arr + 1, arr + N + 1);
	for (int i = 1; i <= N; i++)	sum[i] = arr[i] + sum[i - 1];
	for (; Q--;) {
		ll a;
		cin >> a;
		int pos = upper_bound(arr, arr + N + 1, a) - arr - 1;
		cout << ((ll)2 * pos - N) * a + sum[N] - 2 * sum[pos] << '\n';
	}
}