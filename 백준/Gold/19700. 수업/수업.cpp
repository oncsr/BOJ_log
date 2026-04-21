#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

bool cmp(ii a, ii b) {
	if (a.first == b.first)	return a.second < b.second;
	return a.first > b.first;
}



int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	vector<ii> V(N);
	for (auto& i : V)	cin >> i.first >> i.second;
	sort(V.begin(), V.end(), cmp);

	vector<int> pos(500001, 0);
	int mx = 1;
	for (int i = 0; i < N; i++) {

		int k = V[i].second;
		
		int s = 1, e = 500000, m = (s + e) >> 1;
		while (s < e) {
			if (pos[m] < k)	e = m;
			else	s = m + 1;
			m = (s + e) >> 1;
		}
		pos[m]++;
		mx = max(mx, m);
	}
	cout << mx;
}