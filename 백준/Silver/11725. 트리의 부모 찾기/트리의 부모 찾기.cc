#include <iostream>
#include <vector>
using namespace std;

int N;
int parent[100001];
vector<vector<int> > Tree(100001);

void dfs(int k) {
	for (int i = 0; i < Tree[k].size(); i++) {
		int child = Tree[k][i];
		if (parent[child] == 0) {
			parent[child] = k;
			dfs(child);
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		Tree[a].push_back(b);
		Tree[b].push_back(a);
	}

	parent[1] = -1;
	dfs(1);

	for (int i = 2; i <= N; i++) {
		cout << parent[i] << '\n';
	}
}