#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string a;
	cin >> a;
	string S = "";
	vector<string> T;
	int p = 0, i = 0, n = a.size();
	for (; i < n; i++) {
		S += a[i];
		if (a[i] == '(')	p++;
		else	p--;
		if (!p) {
			T.push_back(S);
			S = "";
		}
	}
	S = T[0];
	bool can = 0;
	for (i = 1; i < T.size(); i++) {
		if (S == T[i]) {
			S = T[i];
			continue;
		}
		can = 1;
		break;
	}
	if (!can) {
		cout << "no";
		return 0;
	}
	for (int g = i; i < g + T.size(); i++) {
		cout << T[i % T.size()];
	}
}