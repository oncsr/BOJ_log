#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	string s;
	cin >> s;
	auto cmp = [&](set<int> a, set<int> b) -> bool {
		string A = "", B = "";
		for (int i : a)	A += s[i];
		for (int i : b)	B += s[i];
		return A < B;
	};
	set<int> S;
	for (int i = 0; i < s.size(); i++) {
		set<int> mx;
		for (int j = 0; j < s.size(); j++) {
			if (S.count(j))	continue;
			S.insert(j);
			if (mx.empty())	mx = S;
			else if (cmp(S, mx))	mx = S;
			S.erase(j);
		}
		for (int i : mx)	cout << s[i];
		S = mx;
		cout << '\n';
	}

}