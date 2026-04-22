#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, o, a, id = 0, fr = 0, mx = 0, ans = 1111110;
	for (cin >> N; N--;) {
		cin >> o;
		if (o == 1) {
			cin >> a;
			id++;
			if (id - fr > mx)	mx = id - fr, ans = a;
			else if (id - fr == mx && a < ans)	ans = a;
		}
		else	fr++;
	}
	cout << mx << ' ' << ans;
}