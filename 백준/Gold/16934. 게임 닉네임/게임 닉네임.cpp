#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	multiset<string> S;
	unordered_map<string, int> Full;
	for (int i = 0; i < N; i++) {
		string a;
		cin >> a;
		bool f = 0;
		int g = 0;
		Full[a]++;
		for (int j = 1; j <= a.size(); j++) {
			string t = a.substr(0, j);
			if (S.count(t)) {
				S.insert(t);
				continue;
			}
			S.insert(t);
			if (!f) {
				f = 1;
				g = j;
			}
		}
		if (f) {
			string ans = a.substr(0, g);
			cout << ans << '\n';
		}
		else {
			cout << a;
			int s = Full[a];
			if (s > 1)	cout << s;
			cout << '\n';
		}
	}


}