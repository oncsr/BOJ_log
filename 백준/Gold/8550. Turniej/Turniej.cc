#include <iostream>
#include <queue>
using namespace std;
using ii = pair<int, int>;
vector<vector<int> > V(100001);
int d[100001]{};
int v[100001]{};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M, a, b;
	for (cin >> N >> M; M--;) {
		cin >> a >> b;
		V[a].push_back(b);
		d[b]++;
	}
	priority_queue<int, vector<int>, greater<> > Q;
	for (int i = 1; i <= N; i++)
		if (!d[i])	Q.push(i);
	for (int i = 1; i <= N; i++) {
		if (Q.empty()) {
			cout << -1;
			break;
		}
		int now = Q.top();
		Q.pop();
		cout << now << '\n';
		for (int j : V[now]) {
			if (--d[j] == 0)
				Q.push(j);
		}
	}
}