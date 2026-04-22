#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M, K;
	cin >> N >> M >> K;
	if (K < N + M - 1)	cout << "NO";
	else {
		cout << "YES\n";
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < M; j++)	cout << i + j << ' ';
			cout << '\n';
		}
	}
}