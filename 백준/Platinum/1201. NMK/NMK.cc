#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M, K;
	cin >> N >> M >> K;
	if (N > K * M) {
		cout << -1;
		return 0;
	}
	if (M > N - K + 1) {
		cout << -1;
		return 0;
	}
	int G = N - M + 2;
	for (int i = K; i >= 1; i--) {
		cout << i << ' ';
		if (G > K) {
			for (int j = G; j < G + M - 1; j++)	cout << j << ' ';
		}
		else {
			if (G + M - 2 <= K)	continue;
			for (int j = G; j < G + M - 1; j++) {
				if (j > K)	cout << j << ' ';
			}
		}
		G -= M - 1;
	}
}