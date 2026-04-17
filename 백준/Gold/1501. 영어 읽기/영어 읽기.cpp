#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, Q;
	map<string, int> M;
	M[""] = 1;
	for (cin >> N; N--;) {
		string a;
		cin >> a;
		if (a.size() > 2)	sort(a.begin() + 1, a.end() - 1);
		M[a]++;
	}
	for (cin >> Q, cin.ignore(); Q--;) {
		string line;
		getline(cin, line);
		string word = "";
		int ans = 1;
		for (char i : line) {
			if (i != ' ') { word += i; continue; }
			if (word.size() > 2)	sort(word.begin() + 1, word.end() - 1);
			ans *= M[word];
			word = "";
		}
		if (word.size() > 2)	sort(word.begin() + 1, word.end() - 1);
		ans *= M[word];
		cout << ans << '\n';
	}

}