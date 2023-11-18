#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int M, N;
	cin >> N >> M;
	int arr[100]{};
	int dp[1024][101]{};
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		arr[i] = abs(a);
		dp[arr[i]][1] = 1;
	}
	
	for (int j = 1; j < M; j++) {
		for (int i = 0; i < 1024; i++) {
			if (!dp[i][j])	continue;
			for (int k = 0; k < N; k++) {
				int g = i ^ arr[k];
				dp[g][j + 1]++;
			}
		}
	}

	for (int j = 1023; j >= 0; j--) {
		if (!dp[j][M])	continue;
		cout << j;
		break;
	}

}