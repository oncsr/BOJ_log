#include <bits/stdc++.h>
#include <regex>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int TC;
	regex re("((100+1+)|(01))+");
	for (cin >> TC; TC--;) {
		string S;
		cin >> S;
		cout << (regex_match(S, re) ? "YES" : "NO") << '\n';
	}
}