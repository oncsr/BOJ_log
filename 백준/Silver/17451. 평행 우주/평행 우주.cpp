#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N;
	ll arr[300001]{};
	cin >> N;
	for (int i = 1; i <= N; i++)	cin >> arr[i];

	ll ans = arr[N];
	for (int i = N - 1; i >= 1; i--) {
		if (arr[i] > ans)	ans = arr[i];
		else {
			if (ans % arr[i] == 0)	ans = arr[i] * (ans / arr[i]);
			else	ans = arr[i] * (ans / arr[i] + 1);
		}
	}
	cout << ans;

}