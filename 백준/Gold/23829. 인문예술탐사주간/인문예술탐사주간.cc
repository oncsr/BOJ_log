#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, Q;
	ll a;
	cin >> N >> Q;
	vector<ll> arr(N + 1, 0);
	vector<ll> sum(N + 1, 0);
	for (int i = 1; i <= N; i++)	cin >> arr[i];

	sort(arr.begin() + 1, arr.end());
	for (int i = 1; i <= N; i++) {
		sum[i] = sum[i - 1] + arr[i];
	}
	for (; Q--;) {
		cin >> a;
		int p = upper_bound(arr.begin(), arr.end(), a) - arr.begin();
		ll s = sum[N] - sum[p - 1] - (N - p + 1) * a;
		s += (p - 1) * a - sum[p - 1];
		cout << s << '\n';
	}

}