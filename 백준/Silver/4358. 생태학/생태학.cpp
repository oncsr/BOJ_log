#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int tot = 0;
	string tree;
	map<string, int> M;
	while (getline(cin, tree)) {
		tot++;
		M[tree]++;
	}

	cout.precision(4);
	for (auto& [a, b] : M) {
		cout << a << ' ';
		cout << fixed << (double)b / tot * 100 << '\n';
	}

}