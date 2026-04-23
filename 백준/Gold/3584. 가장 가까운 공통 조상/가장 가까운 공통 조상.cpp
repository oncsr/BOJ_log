#include <iostream>
#include <vector>
using namespace std;

int T, a, b, N;
vector<vector<int> > V(10001);
vector<int> P(10001);
vector<int> D(10001);

void dfs(int n, int d) {
	D[n] = d;
	for (int i : V[n])	dfs(i, d + 1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	for (cin >> T; T--;) {
		cin >> N;
		V = vector<vector<int> >(N + 1);
		P = vector<int>(N + 1);
		D = vector<int>(N + 1);
		int g[10001]{}, root = 1;
		for (int i = 1; i < N; i++) {
			cin >> a >> b;
			V[a].push_back(b);
			P[b] = a;
			g[b]++;
		}
		for (int i = 1; i <= N; i++) {
			if (!g[i]) {
				root = i;
				break;
			}
		}
		dfs(root, 0);
		cin >> a >> b;
		while (a != b) {
			if (D[a] > D[b])	a = P[a];
			else	b = P[b];
		}
		cout << a << '\n';
	}
}