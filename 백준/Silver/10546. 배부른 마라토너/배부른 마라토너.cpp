#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	string a, ans;
	map<string, int> M;
	for (int i = 0; i < N; i++) {
		cin >> a;
		M[a]++;
	}
	for (int i = 1; i < N; i++) {
		cin >> a;
		M[a]--;
	}
	for (auto i = M.begin(); i != M.end(); i++) {
		if (i->second % 2 == 1)	ans = i->first;
	}
	cout << ans;
}