#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> root;
int N, M[3]{};
vector<pair<tuple<int, int, int>, int>> V;

int find(int x) {
	if (x == root[x])	return x;
	return root[x] = find(root[x]);
}

void study(int m, int id) {
	root.resize(N + 1);
	for (int i = 1; i <= N; i++)	root[i] = i;
	for (; m--;) {
		int a, b;
		cin >> a >> b;
		int x = find(a), y = find(b);
		root[x] = y;
	}
	for (int i = 1; i <= N; i++) {
		int g = find(i);
		if (id == 0)	get<0>(V[i].first) = g;
		if (id == 1)	get<1>(V[i].first) = g;
		if (id == 2)	get<2>(V[i].first) = g;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M[0] >> M[1] >> M[2];
	V.resize(N + 1);
	for (int i = 1; i <= N; i++)	V[i].second = i;
	for (int i = 0; i < 3; i++)	study(M[i], i);
	sort(V.begin() + 1, V.end());
	vector<vector<int>> G;
	vector<int> temp;
	for (int i = 2; i <= N; i++) {
		if (V[i].first == V[i - 1].first) {
			temp.push_back(V[i - 1].second);
		}
		else {
			if (!temp.empty()) {
				temp.push_back(V[i - 1].second);
				sort(temp.begin(), temp.end());
				G.push_back(temp);
				temp.clear();
			}
		}
	}
	if (!temp.empty()) {
		temp.push_back(V[N].second);
		sort(temp.begin(), temp.end());
		G.push_back(temp);
	}
	sort(G.begin(), G.end());
	cout << G.size() << '\n';
	for (auto i : G) {
		for (auto j : i)	cout << j << ' ';
		cout << '\n';
	}
}