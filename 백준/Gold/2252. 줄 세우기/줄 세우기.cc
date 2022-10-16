#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N, M, a, b, d[32001]{};
	cin >> N >> M;
	vector<vector<int> > V(32001);
	while (M--) {
		cin >> a >> b;
		V[a].push_back(b);
		d[b]++;
	}
	queue<int> Q;
	for (int i = 1; i <= N; i++)
		if (!d[i])	Q.push(i);
	for (int i = 1; i <= N; i++) {
		int now = Q.front();
		cout << now << ' ';
		Q.pop();
		for (int j : V[now])
			if (!(--d[j]))
				Q.push(j);
	}
}