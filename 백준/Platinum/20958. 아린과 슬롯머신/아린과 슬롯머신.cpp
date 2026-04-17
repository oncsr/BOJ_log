#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int e[10001]{};
	for (int i = 2; i * i <= 10000; i++) {
		if (!e[i]) {
			for (int j = i * i; j <= 10000; j += i)	e[j] = 1;
		}
	}
	vector<int> prime;
	for (int i = 2; i * i <= 10000000; i++) {
		if (i == 7)	continue;
		if (!e[i])	prime.push_back(i);
	}

	int N, M;
	int cnt[2000001]{};
	ll ans = 0;
	vector<vector<pair<int, int>>> info(50001);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (auto [a, b] : info[i])	cnt[a] -= b;
		int a;
		cin >> a;
		if ((a % 7) || (a % 49 == 0)) { cout << -1; return 0; }
		a /= 7;
		for (int j : prime) {
			if (j * j > a)	break;
			if (a % j)	continue;
			int temp = 0;
			while (a % j == 0)	a /= j, temp++;
			if (temp > cnt[j]) {
				ans += temp - cnt[j];
				if (i + M <= N)	info[i + M].emplace_back(j, temp - cnt[j]);
				cnt[j] = temp;
			}
		}
		if (a > 1) {
			if (!cnt[a]) {
				ans++;
				if (i + M <= N)	info[i + M].emplace_back(a, 1);
				cnt[a] = 1;
			}
		}
	}
	cout << ans;

}