#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int e[1000001]{};
	for (int i = 2; i * i <= 1000000; i++)
		if (!e[i])
			for (int j = i * i; j <= 1000000; j += i)
				if (!e[j])	e[j] = i;

	int idx[1000001]{}, c = 0;
	vector<int> sosu;
	for (int i = 2; i <= 1000000; i++)
		if (!e[i])	idx[i] = c++, sosu.push_back(i);

	int n;	cin >> n;
	int arr[100][78498]{};
	int sum[78498]{};
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		while (e[a]) {
			arr[i][idx[e[a]]]++;
			sum[idx[e[a]]]++;
			a /= e[a];
		}
		if (a > 1) {
			arr[i][idx[a]]++;
			sum[idx[a]]++;
		}
	}
	int ans = 1, cnt = 0;
	for (int i = 0; i < c; i++) {
		int g = sum[i] / n;
		if (!g)	continue;
		for (int j = 0; j < n; j++) {
			if (arr[j][i] < g)	cnt += g - arr[j][i];
		}
		while (g--)	ans *= sosu[i];
	}
	cout << ans << ' ' << cnt;
}