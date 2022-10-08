#include <iostream>
#include <vector>
using namespace std;

int s[100001]{}, p[100001]{};
vector<vector<int> > V(100001);
void dfs(int n, int P) {
	p[n] = P, s[n] = 1;
	for (int i : V[n])
		if (i != P) {
			dfs(i, n);
			s[n] += s[i];
		}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, R, Q, a, b;
	cin >> N >> R >> Q;
	for (int i = 1; i < N; i++) {
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	dfs(R, 0);
	for (; Q--;) {
		cin >> a;
		cout << s[a] << '\n';
	}
}