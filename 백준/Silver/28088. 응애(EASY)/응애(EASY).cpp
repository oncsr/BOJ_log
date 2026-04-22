#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N, M, K;
	cin >> N >> M >> K;

	vector<int> D(N);
	for (; M--;) {
		int a;
		cin >> a;
		D[a] = 1;
	}
	for (int i = 0; i < K; i++) {
		vector<int> temp(N);
		for (int j = 0; j < N; j++) {
			if (D[j] == 1)	temp[(j + N - 1) % N]++, temp[(j + 1) % N]++;
			else	D[j] = 0;
		}
		D = temp;
	}
	int ans = 0;
	for (int i = 0; i < N; i++)
		if (D[i] == 1)	ans++;
	cout << ans;
}