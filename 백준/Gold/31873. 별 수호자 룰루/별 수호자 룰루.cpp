#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
	cin.tie(0)->sync_with_stdio(0);
 
	ll N, K;
	cin >> N >> K;
	if (K == 1) { cout << "NO"; return 0; }
	if ((K * (K + 1) / 2) % K != 0) {
		cout << "YES\n";
		for (int j = 0; j < N / K; j++) {
			for (int i = 1; i <= K; i++)	cout << j * K + i << ' ';
			cout << '\n';
		}
		return 0;
	}
	ll line = N / K;
	if (line == 1) { cout << "NO"; return 0; }
	cout << "YES\n";
	ll g = 0;
	if (line & 1) {
		for (int i = 1; i < K; i++)	cout << i << ' ';
		cout << 2 * K - 1 << '\n';
		for (int i = K + 1; i < 2 * K - 1; i++)	cout << i << ' ';
		cout << 3 * K - 2 << ' ' << 2 * K << '\n';
		for (int i = 2 * K + 1; i < 3 * K - 2; i++)	cout << i << ' ';
		cout << K << ' ' << 3 * K - 1 << ' ' << 3 * K << '\n';
		line -= 3;
		g += 3;
	}
	while (line > 0) {
		for (int i = g * K + 1; i < (g + 1) * K; i++)	cout << i << ' ';
		cout << (g + 1) * K + 1 << '\n' << (g + 1) * K << ' ';
		for (int i = (g + 1) * K + 2; i <= (g + 2) * K; i++)	cout << i << ' ';
		cout << '\n';
		g += 2;
		line -= 2;
	}
}
