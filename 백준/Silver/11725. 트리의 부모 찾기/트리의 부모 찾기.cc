#include <iostream>
#include <vector>
using namespace std;
int N, a, b;
vector<vector<int> > V(100001);
int D[100001]{};

void dfs(int n, int p) {
	D[n] = p;
	for (int next : V[n])if (next != p)dfs(next, n);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	dfs(1, 0);
	for (int i = 2; i <= N; i++)	cout << D[i] << '\n';
}