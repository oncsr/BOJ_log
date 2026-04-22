#include <iostream>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll arr[200000]{}, base[200000]{};
	int n;
	ll sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> arr[i], sum += arr[i], base[i] = arr[i];
	int s = 1, e = n - 2;
	while (s <= e) {
		while (s <= e && arr[s - 1] <= arr[s])	s++;
		while (s <= e && arr[e + 1] <= arr[e])	e--;
		if (s > e)	break;
		if (arr[s - 1] < arr[e + 1]) {
			ll cnt = (arr[s - 1] - arr[s] - 1) / base[s] + 1;
			arr[s] += cnt * base[s];
			sum += cnt * base[s];
			s++;
		}
		else {
			ll cnt = (arr[e + 1] - arr[e] - 1) / base[e] + 1;
			arr[e] += cnt * base[e];
			sum += cnt * base[e];
			e--;
		}
	}
	cout << sum;
}