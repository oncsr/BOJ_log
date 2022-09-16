#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll, int> edge;	// 간선

int V, E, A, B, C;	// V = 정점 수, E = 간선 수
int visit[10001] = { 0 };	// 방문 여부 확인
vector<vector<edge> > graph(10001);	// 그래프
priority_queue<edge, vector<edge>, greater<> > Q;
// 탐색 우선순위 저장
int cnt = 0;	// 탐색한 간선의 수
ll cost = 0;	// 비용

void dfs(int node) {
	if (!visit[node]) {
		visit[node]++;
		while (cnt < V - 1) {
			for (int i = 0; i < graph[node].size(); i++)
				if (!visit[graph[node][i].second])
					Q.push(graph[node][i]);
			int next = Q.top().second;
			int money = Q.top().first;
			Q.pop();
			while (!Q.empty() && visit[next]) {
				next = Q.top().second;
				money = Q.top().first;
				Q.pop();
			}
			cost += money;
			cnt++;
			dfs(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		cin >> A >> B >> C;
		graph[A].push_back({ C,B });
		graph[B].push_back({ C,A });
	}
	dfs(1);
	cout << cost << '\n';
}