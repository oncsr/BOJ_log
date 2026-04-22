#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int N, M;
int arr[10][10]{}, dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
int id = 1, vis[10][10]{};
vector<vector<ii>> V(7);
int visited[7]{};
priority_queue<ii, vector<ii>, greater<>> Q;
int cnt = 0, cost = 0;
bool fal = 0;

void dfs(int n) {
	if (!visited[n]) {
		visited[n]++;
		while (cnt < id - 2) {
			for (ii i : V[n])
				if (!visited[i.second])	Q.push(i);
			if (Q.empty()) {
				fal = 1;
				return;
			}
			int next = Q.top().second;
			int money = Q.top().first;
			Q.pop();
			while (!Q.empty() && visited[next]) {
				next = Q.top().second;
				money = Q.top().first;
				Q.pop();
			}
			if (visited[next])	return;
			cost += money;
			cnt++;
			dfs(next);
		}

	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)	for (int j = 0; j < M; j++)	cin >> arr[i][j];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (vis[i][j] || !arr[i][j])	continue;
			queue<ii> Q;
			vis[i][j]++;
			Q.push({ i,j });
			while (!Q.empty()) {
				ii now = Q.front();
				arr[now.first][now.second] = id;
				Q.pop();
				for (int k = 0; k < 4; k++) {
					int x = now.first + dx[k], y = now.second + dy[k];
					if (x >= 0 && x < N && y >= 0 && y < M && !vis[x][y] && arr[x][y]) {
						Q.push({ x,y });
						vis[x][y]++;
					}
				}
			}
			id++;
		}
	}
	/*
	cout << "==========\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)	cout << arr[i][j] << ' ';
		cout << '\n';
	}
	cout << "==========\n";
	*/
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!arr[i][j])	continue;
			int now = arr[i][j];
			int len = 0, next = -1;
			for (int k = i - 1; k >= 0; k--) {
				if (arr[k][j]) {
					next = arr[k][j];
					break;
				}
				len++;
			}
			if (next != -1 && now != next && len > 1) {
				//cout << now << "-" << next << " : 길이 " << len << " 추가 \n";
				V[now].push_back({ len, next });
				V[next].push_back({ len, now });
			}
			len = 0, next = -1;
			for (int k = i + 1; k < N; k++) {
				if (arr[k][j]) {
					next = arr[k][j];
					break;
				}
				len++;
			}
			if (next != -1 && now != next && len > 1) {
				//cout << now << "-" << next << " : 길이 " << len << " 추가 \n";
				V[now].push_back({ len, next });
				V[next].push_back({ len, now });
			}
			len = 0, next = -1;
			for (int k = j - 1; k >= 0 ; k--) {
				if (arr[i][k]) {
					next = arr[i][k];
					break;
				}
				len++;
			}
			if (next != -1 && now != next && len > 1) {
				//cout << now << "-" << next << " : 길이 " << len << " 추가 \n";
				V[now].push_back({ len, next });
				V[next].push_back({ len, now });
			}
			len = 0, next = -1;
			for (int k = j + 1; k < M; k++) {
				if (arr[i][k]) {
					next = arr[i][k];
					break;
				}
				len++;
			}
			if (next != -1 && now != next && len > 1) {
				//cout << now << "-" << next << " : 길이 " << len << " 추가 \n";
				V[now].push_back({ len, next });
				V[next].push_back({ len, now });
			}
		}
	}
	dfs(1);
	if (fal || cnt < id - 2)	cout << -1;
	else	cout << cost;
}