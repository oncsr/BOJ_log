#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int arr[31][31]{};
	arr[1][1] = 1;
	for (int i = 2; i <= 30; i++) {
		for (int j = 1; j <= i; j++) {
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}

	int R, C, W;
	cin >> R >> C >> W;
	int ans = 0;
	for (int i = R; i < R + W; i++) {
		for (int j = C; j < C + (i - R + 1); j++) {
			ans += arr[i][j];
		}
	}
	cout << ans;

}