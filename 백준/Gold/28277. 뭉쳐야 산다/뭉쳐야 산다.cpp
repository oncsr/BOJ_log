#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, Q;
	cin >> N >> Q;
	set<int> none;
	set<int> S[500001]{};
	for (int i = 1; i <= N; i++) {
		int n;
		cin >> n;
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			S[i].insert(a);
		}
	}
	for (; Q--;) {
		int o, a, b;
		cin >> o >> a;
		if (o == 1) {
			cin >> b;
			if (S[a].size() < S[b].size()) {
				swap(S[a], S[b]);
			}
			for (int i : S[b])	S[a].insert(i);
			S[b] = none;
		}
		else	cout << S[a].size() << '\n';
	}
}