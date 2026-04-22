#include <iostream>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll N, K;
	cin >> N >> K;
	if (K > N) {
		cout << -1;
		return 0;
	}
	if (N > K * K) {
		cout << -1;
		return 0;
	}
	ll cnt = N - K, G = N - K + 2;

	for (int i = K; i >= 1; i--) {
		cout << i << ' ';
		if (G + K - 2 <= K)	continue;
		if (G > K) {
			for (int j = G; j < G + K - 1; j++)	cout << j << ' ';
		}
		else {
			for (int j = G; j < G + K - 1; j++) {
				if (j > K)	cout << j << ' ';
			}
		}
		G -= K - 1;		
	}
}