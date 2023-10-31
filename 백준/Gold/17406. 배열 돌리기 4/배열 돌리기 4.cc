#include <bits/stdc++.h>
using namespace std;

int N, M, K;
vector<vector<int>> arr(51, vector<int>(51));

void rotate(int r, int c, int s) {
	for (int k = 1; k <= s; k++) {
		int temp = arr[r - k][c - k];
		for (int i = 0; i < 2 * k; i++)	arr[r - k + i][c - k] = arr[r - k + i + 1][c - k];
		for (int i = 0; i < 2 * k; i++)	arr[r + k][c - k + i] = arr[r + k][c - k + i + 1];
		for (int i = 0; i < 2 * k; i++)	arr[r + k - i][c + k] = arr[r + k - i - 1][c + k];
		for (int i = 0; i < 2 * k; i++)	arr[r - k][c + k - i] = arr[r - k][c + k - i - 1];
		arr[r - k][c - k + 1] = temp;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}
	vector<tuple<int, int, int>> V;
	vector<int> ord;
	for (int i = 0; i < K; i++)	ord.push_back(i);
	for (int i = 0; i < K; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		V.push_back({ a,b,c });
	}

	int ans = 1e9;
	do {

		vector<vector<int>> T = arr;

		for (int i = 0; i < K; i++) {
			auto [r, c, s] = V[ord[i]];
			rotate(r, c, s);
		}

		for (int i = 1; i <= N; i++) {
			int s = 0;
			for (int j = 1; j <= M; j++)	s += arr[i][j];
			ans = min(ans, s);
		}

		arr = T;

	} while (next_permutation(ord.begin(), ord.end()));
	
	cout << ans;

}