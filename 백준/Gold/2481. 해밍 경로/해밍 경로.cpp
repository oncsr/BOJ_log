#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, K;
	cin >> N >> K;
	int arr[100001]{};
	unordered_map<int, int> M;
	for (int i = 1; i <= N; i++) {
		bitset<30> B;
		cin >> B;
		int now = B.to_ulong();
		M[now] = i;
		arr[i] = now;
	}

	vector<vector<int>> V(100001);
	for (int i = 1; i <= N; i++) {
		for (int k = 0; k < K; k++) {
			int next = arr[i] ^ (1 << k);
			if (M.find(next) == M.end())	continue;
			V[i].push_back(M[next]);
			V[M[next]].push_back(i);
		}
	}

	int m;
	for (cin >> m; m--;) {
		int a;
		cin >> a;
		queue<int> Q;
		Q.emplace(1);
		vector<int> vis(N + 1);
		vis[1] = -1;
		bool find = 0;
		while (!Q.empty()) {
			int pos = Q.front();
			Q.pop();
			if (pos == a) {
				find = 1;
				stack<int> route;
				while (vis[pos] != -1) {
					route.push(pos);
					pos = vis[pos];
				}
				cout << 1 << ' ';
				while (!route.empty())	cout << route.top() << ' ', route.pop();
				cout << '\n';
				break;
			}
			for (int j : V[pos]) {
				if (vis[j])	continue;
				Q.push(j);
				vis[j] = pos;
			}

		}
		if (!find)	cout << "-1\n";
	}
	

	
}