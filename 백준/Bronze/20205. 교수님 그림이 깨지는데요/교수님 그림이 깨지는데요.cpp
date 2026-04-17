#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N, K;
	cin >> N >> K;
	int arr[10][10]{};
	for (int i = 0; i < N; i++)	for (int j = 0; j < N; j++)	cin >> arr[i][j];
	int ans[100][100]{};
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int x = i * K; x < (i + 1) * K; x++) {
				for (int y = j * K; y < (j + 1) * K; y++) {
					ans[x][y] = arr[i][j];
				}
			}
		}
	}
	for (int i = 0; i < N * K; i++) {
		for (int j = 0; j < N * K; j++) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}

}