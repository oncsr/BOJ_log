#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N, deg[501]{}, val[501]{}, b, real[501]{};
	vector<vector<int> > V(501);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> val[i];
		cin >> b;
		while (b != -1) {
			V[b].push_back(i);
			deg[i]++;
			cin >> b;
		}
	}
	queue<int> Q;
	for (int i = 1; i <= N; i++) {
		if (!deg[i])	Q.push(i);
		real[i] = val[i];
	}
	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();
		for (int j : V[now]) {
			real[j] = max(real[j], real[now] + val[j]);
			if (--deg[j] == 0) {
				Q.push(j);
			}
		}
	}
	for (int i = 1; i <= N; i++)
		cout << real[i] << '\n';
}