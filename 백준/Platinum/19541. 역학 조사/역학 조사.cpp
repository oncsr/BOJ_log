#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M;
	cin >> N >> M;
	vector<vector<int> > meet(100001);
	for (int i = 0; i < M; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int a;
			cin >> a;
			meet[i].push_back(a);
		}
	}
	bitset<100001> ans;
	for (int i = 1; i <= N; i++) {
		bool a;
		cin >> a;
		ans[i] = a;
	}
	bitset<100001> total = ans;
	for (int i = M - 1; i >= 0; i--) {
		bool check = 1;
		for (int j : meet[i])	check &= ans[j];
		if (check)	continue;
		for (int j : meet[i])	ans[j] = 0;
	}

	bool check = 0;
	for (int i = 1; i <= N; i++)	check |= ans[i];
	
	bitset<100001> temp = ans;
	for (int i = 0; i < M; i++) {
		bool infect = 0;
		for (int j : meet[i])	infect |= temp[j];
		if (!infect)	continue;
		for (int j : meet[i])	temp[j] = 1;
	}
	if (temp != total) {
		cout << "NO";
		return 0;
	}

	cout << "YES\n";
	for (int i = 1; i <= N; i++)	cout << ans[i] << ' ';
}