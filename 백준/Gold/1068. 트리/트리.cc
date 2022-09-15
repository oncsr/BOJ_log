#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > g(51);
int visit[51] = { 0 };
int cnt = 0;

int dfs(int n) {
	if (visit[n] || g[n].empty())
		return 1;
	else {
		visit[n]++;
		bool find = false;
		for (int i = 0; i < g[n].size(); i++) {
			if (visit[g[n][i]])
				continue;
			else {
				find = true;
				dfs(g[n][i]);
			}
		}
		if (!find)
			cnt++;
		return cnt;
	}
}

int main() {
	
	int n;
	cin >> n;
	int root;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a == -1) {
			root = i;
			continue;
		}
		g[i].push_back(a);
		g[a].push_back(i);
	}
	int f;
	cin >> f;
	visit[f]++;
	if (f == root)
		cout << "0\n";
	else
		cout << dfs(root) << '\n';
}