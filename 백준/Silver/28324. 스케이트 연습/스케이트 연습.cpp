#include <iostream>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	ll arr[500001]{};
	cin >> n;
	for (int i = 1; i <= n; i++)	cin >> arr[i];
	ll a = 1, ans = 0;
	for (int i = n; i >= 1; i--) {
		ans += min(a, arr[i]);
		if (a > arr[i])	a = arr[i];
		a++;
	}
	cout << ans;
}