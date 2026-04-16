#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T, D[191230] = { 0,1,2 }, mod = 1e9 + 7;
	for (int i = 3; i <= 191229; i++)	D[i] = (D[i - 1] + D[i - 2]) % mod;
	for (cin >> T; T--;) {
		int N;
		cin >> N;
		cout << D[N] << '\n';
	}

}