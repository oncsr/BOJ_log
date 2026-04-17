#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
vector<vector<int>> arr;
vector<int> ans;

int mx = 0;
int res = 0;

void solve(int pos, int sel, vector<int> t) {
	if (pos == N) {
		if (sel & 1) {
			int cnt = 0;
			for (int j = 0; j < M; j++) {
				if (t[j] > sel / 2)	t[j] = 1;
				else	t[j] = 0;
				if (t[j] == ans[j])	cnt++;
			}
			if (cnt > mx)	res = 1;
		}
		return;
	}
	solve(pos + 1, sel, t);
	sel++;
	for (int j = 0; j < M; j++)	t[j] += arr[pos][j];
	solve(pos + 1, sel, t);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	arr = vector<vector<int>>(N, vector<int>(M));
	ans = vector<int>(M);
	for (int& i : ans)	cin >> i;
	for (int i = 0; i < N; i++) {
		int cnt = 0;
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == ans[j])	cnt++;
		}
		mx = max(mx, cnt);
	}

	vector<int> s(M);
	solve(0, 0, s);
	cout << res;

}