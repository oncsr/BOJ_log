#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, mx = 1, cnt = 1, S;
	cin >> N >> S;
	for (int i = 1; i < N; i++) {
		int a;
		cin >> a;
		if (a < S)	cnt++;
		else	cnt = 1, S = a;
		mx = max(mx, cnt);
	}
	cout << mx;
}