#include <iostream>
using namespace std;
using ll = long long;

int main() {
	int N;
	ll arr[1000001]{}, s = 2, e = 3, a;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a;
		arr[i] = arr[i - 1] + a;
	}
	ll ans = 0;
	for (int s = 2, e = N; s < N; s++) {
		ll head = arr[s - 1];
		while (arr[N] - arr[e - 1] <= head)	e--;
		if (s >= e)	break;
		int a = s, b = e - 1, m = (a + b + 1) / 2;
		while (a <= b) {
			ll chest = arr[m] - head;
			ll stomach = arr[N] - arr[m];
			if (chest > stomach) {
				ans += ((ll)b - m + 1);
				if (a == b)	break;
				b = m - 1;
			}
			else {
				if (a == b)	break;
				a = m + 1;
			}
			m = (a + b) / 2;
		}
	}
	cout << ans;
}