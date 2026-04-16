#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	ll H, D[61] = { 1,1,3 };
	cin >> H;
	for (int i = 3; i <= H; i++) {
		D[i] = LLONG_MAX;
		for (int j = 0; j < i; j++) {
			D[i] = min(D[i], D[j] * (1LL << (i - j)) + D[i - j - 1]);
		}
	}
	cout << D[H];

}