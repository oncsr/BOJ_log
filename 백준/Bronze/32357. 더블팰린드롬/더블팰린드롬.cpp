#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		string a;
		cin >> a;
		int s = 0, e = a.size() - 1, x = 0;
		while (s < e)	if (a[s++] != a[e--])	x++;
		if (!x)	ans++;
	}
	cout << ans * (ans - 1);

}