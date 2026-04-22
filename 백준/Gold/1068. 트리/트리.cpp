#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > Tree(51);
vector<int> Parent(51);
int N, root, rmv, leaf = 0;

// 단말 노드의 개수를 구한다.
void dfs(int now, int parent) {
	if (now == rmv)	return;
	int isChild = 0;
	for (int child : Tree[now]) {
		if (child != parent && child != rmv) {
			dfs(child, now);
			isChild++;
		}
	}
	if (isChild == 0)	leaf++;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		Parent[i] = a;
		if (a == -1)	root = i;
		else {
			Tree[a].push_back(i);
			Tree[i].push_back(a);
		}
	}
	cin >> rmv;

	dfs(root, -1);
	cout << leaf;
}