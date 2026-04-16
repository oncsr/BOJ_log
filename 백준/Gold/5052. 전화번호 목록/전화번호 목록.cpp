#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int T;
	for (cin >> T; T--;) {
		int N, ans = 1;
		cin >> N;
		set<string> S;
		vector<string> V(N);
		for (auto& i : V)	cin >> i, S.insert(i);

		for (auto i : V) {
			string temp = "";
			for (char j : i) {
				temp += j;
				if (temp == i)	break;
				if (S.count(temp))	ans = 0;
			}
		}
		cout << (ans ? "YES\n" : "NO\n");

	}

}