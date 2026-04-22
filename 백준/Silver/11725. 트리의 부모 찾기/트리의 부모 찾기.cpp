#include <iostream>
#include <vector>
using namespace std;

// 트리
vector<vector<int> > Tree(100001);

// 각 노드의 부모 노드를 저장할 벡터
vector<int> Parent(100001);

// now : 현재 노드, parent : 현재 노드의 부모
void dfs(int now, int parent) {
	Parent[now] = parent;
	for (int next : Tree[now]) {
		if (next != parent) {
			dfs(next, now);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	// N - 1개의 줄을 입력받기
	for (int i = 1; i < N; i++) {
		int a, b;
		cin >> a >> b;
		// 무방향 간선 만들기
		Tree[a].push_back(b);
		Tree[b].push_back(a);
	}

	dfs(1, 0);

	for (int i = 2; i <= N; i++)
		cout << Parent[i] << '\n';
	
}