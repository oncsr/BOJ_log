#include <bits/stdc++.h>
using namespace std;
using ll = long long;

char arr[10][10]{};
int N, M;

int ans = -1;

void solve(vector<int> row, vector<int> col) {
	string a = "";
	for (int i = 0; i < row.size(); i++)
		a += arr[row[i]][col[i]];
	int num = stoi(a);
	if ((int)sqrt(num) * (int)sqrt(num) == num)	ans = max(ans, num);

	int next_row = 2 * row[row.size() - 1] - row[row.size() - 2];
	int next_col = 2 * col[col.size() - 1] - col[col.size() - 2];
	if ((next_row > N || next_col > M) || (next_row < 1 || next_col < 1))	return;
	row.push_back(next_row);
	col.push_back(next_col);
	solve(row, col);

}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == '0')	ans = max(ans, 0);
			if (arr[i][j] == '1')	ans = max(ans, 1);
			if (arr[i][j] == '4')	ans = max(ans, 4);
			if (arr[i][j] == '9')	ans = max(ans, 9);
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			for (int a = 1; a <= N; a++) {
				for (int b = 1; b <= M; b++) {
					if (make_pair(i, j) == make_pair(a, b))	continue;
					solve({ i,a }, { j,b });
				}
			}
		}
	}
	cout << ans;

}