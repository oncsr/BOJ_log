#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > tree(100001);
int sz[100001]{};	// sz[i] = 정점 i의 서브트리의 노드 개수
int parent[100001]{};	// parent[i] = 정점 i의 부모 정점
vector<vector<int> > chain(100001);
int chain_num[100001]{};	// i번 노드가 속한 체인의 루트 번호
int depth[100001]{};		// i번 노드가 속한 체인의 깊이
int chain_index[100001]{};	// i번 노드가 속한 체인에서 몇 번째 노드인지


int dfs(int node, int par) {
	parent[node] = par;
	sz[node] = 1;
	for (int next : tree[node])
		if (next != par)
			sz[node] += dfs(next, node);
	return sz[node];
}

// node = 현재 정점, par = 부모 정점
// chain_start = 현재 체인의 루트
// dep = 현재 체인의 깊이
void HLD(int node, int par, int chain_start, int dep) {
	depth[node] = dep;
	chain_num[node] = chain_start;
	chain_index[node] = chain[chain_start].size();
	chain[chain_start].push_back(node);

	int heavy = -1;
	for (int next : tree[node]) {
		if (next != par && (heavy == -1 || sz[next] > sz[heavy]))
			heavy = next;
	}
	if (heavy != -1)
		HLD(heavy, node, chain_start, dep);
	
	for (int next : tree[node]) {
		if (next != par && next != heavy)
			HLD(next, node, next, dep + 1);
	}
}

int LCA(int u, int v) {
	while (chain_num[u] != chain_num[v]) {
		if (depth[u] > depth[v])
			u = parent[chain_num[u]];
		else
			v = parent[chain_num[v]];
	}
	return chain_index[u] > chain_index[v] ? v : u;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M, a, b;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	dfs(1, 0);
	HLD(1, 0, 1, 0);
	for (cin >> M; M--;) {
		cin >> a >> b;
		cout << LCA(a, b) << '\n';
	}
}