#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> ii;

vector<vector<ii> > V(100001);
priority_queue<ii, vector<ii>, greater<> > Q;
priority_queue<int> Q2;
int visit[100001] = { 0 };
int N, M, a, b, c;
int cost = 0, cnt = 0;

void dfs(int node) {
	if (!visit[node]) {
		visit[node]++;
		while (cnt < N - 1) {
			for (int i = 0; i < V[node].size(); i++) {
				ii temp = V[node][i];
				if (!visit[temp.second])
					Q.push(temp);
			}
			int next = Q.top().second;
			int val = Q.top().first;
			Q.pop();
			while (!Q.empty() && visit[next]) {
				next = Q.top().second;
				val = Q.top().first;
				Q.pop();
			}
			if (Q.empty() && visit[next])	return;
			cost += val;
			cnt++;
			Q2.push(val);
			dfs(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		V[a].push_back({ c,b });
		V[b].push_back({ c,a });
	}
	dfs(1);
	cout << cost - Q2.top() << '\n';
}