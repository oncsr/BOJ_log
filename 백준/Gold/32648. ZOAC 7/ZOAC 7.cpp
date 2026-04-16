#include <bits/stdc++.h>
using namespace std;
 
int main() {
	cin.tie(0)->sync_with_stdio(0);
 
	int N, M;
	cin >> N >> M;
	int arr[2001][2001]{};
	int dp1[2001][2001][4]{}, dp2[2002][2002][4]{};
 
	string zoac = "ZOAC";
	for (int i = 1; i <= N; i++)	for (int j = 1; j <= M; j++) {
		char a;
		cin >> a;
		for (int k = 0; k < 4; k++) {
			if (a == zoac[k])	arr[i][j] = k;
		}
	}
 
	for (int i = 1; i <= N; i++)	for (int j = 1; j <= M; j++)	for (int k = 0; k < 4; k++) {
		dp1[i][j][k] = max(dp1[i - 1][j][k], dp1[i][j - 1][k]) + (arr[i][j] == k);
	}
 
	for (int i = N; i >= 1; i--)	for (int j = M; j >= 1; j--)	for (int k = 0; k < 4; k++) {
		dp2[i][j][k] = max(dp2[i + 1][j][k], dp2[i][j + 1][k]) + (arr[i][j] == k);
	}
 
	int ans[4]{};
	for (int i = 1; i <= N; i++)	for (int j = 1; j <= M; j++)	for (int k = 0; k < 4; k++) {
		ans[k] = max(ans[k], dp1[i][j][k] + max(dp2[i + 1][1][k], dp2[1][j + 1][k]));
	}
 
	for (int k = 0; k < 4; k++)	cout << ans[k] << ' ';
 
}