#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int T;
	for (cin >> T; T--;) {
		int N;
		cin >> N;
		vector<int> cnt(N + 1);
		// i, cnt[i], pos[i] = {int, int, vector<int>}
		vector<vector<int>> pos(N + 1);
		for (int i = 0; i < N; i++) {
			int a;
			cin >> a;
			cnt[a]++;
			pos[a].push_back(i);
		}

		vector<tuple<int, int, vector<int>>> TP;
		for (int i = 1; i <= N; i++)	TP.push_back({ cnt[i], i, pos[i] });
		sort(TP.begin(), TP.end(), greater<>());
		vector<int> List;
		for (int i = 1; i <= N; i++)	List.push_back(get<1>(TP[i % N]));
		
		int comp = 0, c = 0;
		vector<int> ans(N);
		for (auto [x, y, z] : TP) {
			for (int i = 0; i < x; i++) {
				if (y == List[c]) { comp = 1; break; }
				ans[z[i]] = List[c++];
			}
			if (comp)	break;
		}
		cout << (comp ? "NO\n" : "YES\n");
		if (comp)	continue;
		for (int i : ans)	cout << i << ' ';
		cout << '\n';

	}

}