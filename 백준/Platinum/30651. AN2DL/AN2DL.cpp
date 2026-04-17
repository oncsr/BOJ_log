#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M, R, S;
	cin >> N >> M;
	int arr[4000][4000]{};
	for (int i = 0; i < N; i++)	for (int j = 0; j < M; j++)	cin >> arr[i][j];
	cin >> R >> S;

	vector<vector<int>> F;
	for (int i = 0; i < N; i++) {
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> Q;
		vector<int> temp;
		for (int j = 0; j < M; j++) {
			Q.emplace(-arr[i][j], j);
			while (j - Q.top().second >= S)	Q.pop();
			if (j >= S - 1)	temp.push_back(-Q.top().first);
		}
		F.push_back(temp);
	}

	vector<vector<int>> ans(N - R + 1, vector<int>(M - S + 1));
	for (int j = 0; j < M - S + 1; j++) {
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> Q;
		vector<int> temp;
		int d = 0;
		for (int i = 0; i < N; i++) {
			Q.emplace(-F[i][j], i);
			while (i - Q.top().second >= R)	Q.pop();
			if (i >= R - 1)	ans[d++][j] = -Q.top().first;
		}
	}

	for (auto& T : ans) {
		for (int& i : T)	cout << i << ' ';
		cout << '\n';
	}

}