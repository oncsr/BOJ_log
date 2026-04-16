#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N;
	cin >> N;
	vector<pair<int, int>> cnt(26, { 1e9,1e9 });
	int ans = 1e9;
	for (int i = 1; i <= N; i++) {
		string a;
		cin >> a;
		vector<pair<int, int>> temp(26, { 1e9,1e9 });
		for (int j = 0; j < a.size(); j++) {
			int now = a[j] - 'a';
			temp[now].first = min(temp[now].first, int(a.size()) - j - 1);
			temp[now].second = min(temp[now].second, j);
		}

		for (int j = 0; j < 26; j++) {
			if (temp[j].first != 1e9) {
				if (cnt[j].second != 1e9)	ans = min(ans, temp[j].first + cnt[j].second);
			}
			if (temp[j].second != 1e9) {
				if (cnt[j].first != 1e9)	ans = min(ans, temp[j].second + cnt[j].first);
			}
		}

		for (int j = 0; j < 26; j++) {
			cnt[j].first = min(cnt[j].first, temp[j].first);
			cnt[j].second = min(cnt[j].second, temp[j].second);
		}
	}
	cout << (ans == 1e9 ? -1 : ans);

}