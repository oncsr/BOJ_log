#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	vector<vector<int> > L(1000001);
	vector<vector<int> > R(1000001);
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		L[a].push_back(b);
		R[b].push_back(a);
	}
	for (int i = 0; i <= 1000000; i++) {
		if (L[i].size())	sort(L[i].begin(), L[i].end(), less<int>());
		if (R[i].size())	sort(R[i].begin(), R[i].end(), less<int>());
	}

	int Q;
	for (cin >> Q; Q--;) {
		int l, r;
		cin >> l >> r;
		if (L[l].empty() || R[r].empty()) {
			cout << -1 << '\n';
			continue;
		}
		bool f = 0;
		int s = 0;
		// L[l]에 r이 있는지 찾기
		int mx1 = L[l].back();
		int id1 = lower_bound(L[l].begin(), L[l].end(), r) - L[l].begin();
		if (id1 != L[l].size() && L[l][id1] == r)	cout << 1 << '\n';
		else {
			if (mx1 < r)	cout << -1 << '\n';
			else {
				int mx2 = R[r][0];
				int id2 = lower_bound(R[r].begin(), R[r].end(), l) - R[r].begin();
				if (id2 != R[r].size() && R[r][id2] == l)	cout << 1 << '\n';
				else {
					if (mx2 > l)	cout << -1 << '\n';
					else	cout << 2 << '\n';
				}
			}
		}
	}
}