#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M, K;
	cin >> N >> M >> K;
	int deg[100001]{};
	int build[100001]{};
	vector<vector<int>> V(100001);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		V[a].push_back(b);
		deg[b]++;
	}
	bool ans = 1;
	for (; K--;) {
		int a, b;
		cin >> a >> b;
		if (a == 1) {
			if (deg[b]) { cout << "Lier!"; return 0; }
			if (build[b]++)	continue;
			for (int i : V[b])	deg[i]--;
		}
		else {
			if (!build[b]) { cout << "Lier!"; return 0; }
			if (!(--build[b])) {
				for (int i : V[b])	deg[i]++;
			}
		}
	}
	cout << "King-God-Emperor";


}