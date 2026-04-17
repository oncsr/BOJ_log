#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N;
	cin >> N;
	map<string, int> M;
	for (int i = 1; i <= N; i++) {
		string a;
		cin >> a;
		M[a] = i;
	}
	stack<int> S;
	for (int i = 1; i <= N; i++) {
		string a;
		cin >> a;
		S.push(M[a]);
	}
	int mn = 1e9, ans = 0;
	while (!S.empty()) {
		int a = S.top();
		if (a > mn)	ans++;
		S.pop();
		mn = min(mn, a);
	}
	cout << ans;

}