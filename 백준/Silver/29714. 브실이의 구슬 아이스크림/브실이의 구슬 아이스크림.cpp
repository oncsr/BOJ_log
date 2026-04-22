#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	map<int, int> M;
	int N, Q;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		M[a]++;
	}
	for (cin >> Q; Q--;) {
		int a;
		map<int, int> temp;
		set<int> S1;
		bool ok = 1;
		for (cin >> a; a--;) {
			int g;
			cin >> g;
			S1.insert(g);
			temp[g]++;
			if (temp[g] > M[g])	ok = 0;
		}
		int b;
		map<int, int> pour;
		set<int> S2;
		for (cin >> b; b--;) {
			int g;
			cin >> g;
			S2.insert(g);
			pour[g]++;
		}
		if (!ok)	continue;
		for (auto i : S1)	M[i] -= temp[i];
		for (auto i : S2)	M[i] += pour[i];
	}
	vector<int> ans;
	for (auto i : M) {
		while (i.second--)	ans.push_back(i.first);
	}
	cout << ans.size() << '\n';
	for (int i : ans)	cout << i << ' ';

}