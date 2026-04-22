#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > V(300001);
vector<int> visit(300001);
vector<int> cnt(300001);

bool dfs(int n, int p, int v) {
	cnt[n] = v;
	bool temp = true;
	for (int i : V[n]) {
		if (i != p) {
			if (!visit[i]) {
				visit[i]++;
				temp &= dfs(i, n, v ^ 1);
			}
			else {
				if (cnt[i] == cnt[n])	return false;
			}
		}
	}
	return temp;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	for (cin >> T; T--;) {
		int N, M, a, b;
		
		V = vector<vector<int> >(300001);
		visit = vector<int>(300001);
		cnt = vector<int>(300001);
		for (cin >> N >> M; M--;) {
			cin >> a >> b;
			V[a].push_back(b);
			V[b].push_back(a);
		}
		bool suc = true;
		for (int i = 1; i <= N; i++) {
			if (visit[i])	continue;
			suc &= dfs(i, 0, 0);
		}
		cout << (suc ? "YES\n" : "NO\n");
	}
}