#include <iostream>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, Q;
	cin >> N >> Q;
	int arr1[100001]{};
	ll arr2[100001]{};
	for (int i = 1; i <= N; i++) {
		cin >> arr1[i];
		arr2[i] = arr1[i] * arr1[i];
		arr1[i] += arr1[i - 1];
		arr2[i] += arr2[i - 1];
	}
	for (; Q--;) {
		int l, r;
		cin >> l >> r;
		ll G = (((ll)arr1[r] - (ll)arr1[l - 1]) * ((ll)arr1[r] - (ll)arr1[l - 1]) - (arr2[r] - arr2[l - 1])) / 2;
		cout << G << '\n';
	}
}