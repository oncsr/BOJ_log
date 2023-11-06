#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int R, n, m;
	cin >> R >> n >> m;

	int arr[1001]{}, sum = 0;
	vector<int> A;
	for (int i = 1; i <= n; i++)	cin >> arr[i], sum += arr[i];
	A.push_back(sum);
	A.push_back(0);
	for (int i = 1; i <= n; i++) {
		int s = 0;
		for (int j = i; j < i + n - 1; j++) {
			int id = j % n;
			if (!id)	id = n;
			s += arr[id];
			A.push_back(s);
		}
	}
	sum = 0;
	for (int i = 1; i <= m; i++)	cin >> arr[i], sum += arr[i];
	vector<int> B;
	B.push_back(sum);
	B.push_back(0);
	for (int i = 1; i <= m; i++) {
		int s = 0;
		for (int j = i; j < i + m - 1; j++) {
			int id = j % m;
			if (!id)	id = m;
			s += arr[id];
			B.push_back(s);
		}
	}
	sort(B.begin(), B.end());
	ll ans = 0;
	for (int i : A) {
		ans += upper_bound(B.begin(), B.end(), R - i) - lower_bound(B.begin(), B.end(), R - i);
	}
	cout << ans;

}