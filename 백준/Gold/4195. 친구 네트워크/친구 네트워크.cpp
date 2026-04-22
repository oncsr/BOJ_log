#include <bits/stdc++.h>
using namespace std;

vector<int> root(200003);
vector<int> cnt(200003);
int pos = 1;
pair<int, int> find(int x) {
	if (x == root[x])	return { x, cnt[x] };
	pair<int, int> p = find(root[x]);
	root[x] = p.first, cnt[x] = p.second;
	return p;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	for (cin >> T; T--;) {
		pos = 1;
		root = vector<int>(200003);
		cnt = vector<int>(200003);
		map<string, int> name;
		int N;
		cin >> N;
		for (int i = 1; i <= 2 * N; i++)	root[i] = i, cnt[i] = 1;
		for (; N--;) {
			string a, b;
			cin >> a >> b;
			if (!name[a])	name[a] = pos++;
			if (!name[b])	name[b] = pos++;
			pair<int, int> x = find(name[a]), y = find(name[b]);
			if (x.first == y.first) {
				cout << x.second << '\n';
				continue;
			}
			int G = x.second + y.second;
			cnt[x.first] = cnt[y.first] = G;
			root[x.first] = y.first;
			cout << G << '\n';
		}
	}
}