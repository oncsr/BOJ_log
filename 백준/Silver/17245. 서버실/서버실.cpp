#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
ll arr[1000][1000]{};

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	ll sum = 0;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
		cin >> arr[i][j];
		sum += arr[i][j];
	}

	ll s = 0, e = 10000000, m = (s + e) >> 1;
	while (s < e) {
		ll cur = 0;
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
			cur += min(m, arr[i][j]);
		}
		if (cur >= (sum + 1) / 2) {
			e = m;
		}
		else {
			s = m + 1;
		}
		m = (s + e) >> 1;
	}
	cout << m;
	
}